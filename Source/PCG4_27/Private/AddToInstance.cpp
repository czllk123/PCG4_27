// Fill out your copyright notice in the Description page of Project Settings.


#include "AddToInstance.h"
#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "UObject/UObjectGlobals.h"
#include "FoliageEditModule.h"
#include "FoliageType_Actor.h"
#include "UObject/Package.h"
#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/ContentBrowser/Public/IContentBrowserSingleton.h"
#include "Editor/ContentBrowser/Public/ContentBrowserModule.h"
#include "Misc/Guid.h"

#include "InstancedFoliageActor.h"
#include "Subsystems/AssetEditorSubsystem.h"



AInstancedFoliageActor* UAddToInstance::GetOrCreateIFA()
{
	//获取当前关卡
	ULevel* CurrentLevel = GWorld->GetCurrentLevel();

	//获取当前关卡中的IFA, 如果没有则自动创建一个
	AInstancedFoliageActor* InstancedFoliageActor = AInstancedFoliageActor::GetInstancedFoliageActorForLevel(CurrentLevel, true);
	return InstancedFoliageActor;
	
}


bool UAddToInstance::AddToFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, UStaticMesh* InStaticMesh, int32 StaticMeshIndex, FTransform Transform, FString SavePath, TMap<int32, FGuid>& FoliageUUIDs)
{
	//如果IFA不存在或者无效，返回false
	if(!InstancedFoliageActor || !IsValid(InstancedFoliageActor))
	{
		UE_LOG(LogTemp,Error,TEXT("Can not find InstancedFoliageActor!!!"))
		return false;
	}


	FGuid FoliageInstaceGuid;
	FoliageInstaceGuid = FGuid::NewGuid();
	
	//打印当前植被的UUID
	UE_LOG(LogTemp, Warning, TEXT("FoliageInstaceGuid is : %s"), *FoliageInstaceGuid.ToString());
	
	//获取给定static mesh 所有的Foliage Type,这里的FoliageType 类型必须是UFoliageType，不能是 UFoliageType_InstancedStaticMesh，要不然下面那个函数用不了
	TArray<const UFoliageType*> FoliageTypes;
	InstancedFoliageActor->GetAllFoliageTypesForSource(InStaticMesh, FoliageTypes);

	//如果给定的StaticMesh没已有关联的FoliageType,则新建一个。
	UFoliageType* FoliageType;
	if(FoliageTypes.Num()==0)
	{
		//获取给定的StaticMesh名称作为FoliageType名称
		const FString FoliageTypeName = FString::Format(TEXT("{0}_FoliageType"),{InStaticMesh->GetName()});
		//这个新建的FoliageType对象的Outer为InstancedFoliageActor，用于实例化植被
		FoliageType = NewObject<UFoliageType_InstancedStaticMesh>(InstancedFoliageActor, *FoliageTypeName,RF_Public | RF_Standalone);
		//这个地方别对这个foliageType做任何更改，只是将他创建出来用来撒点，最后将这个保存成foliageType文件，然后对它做相应的设置
		//FoliageType->SetSource(InStaticMesh);
		//InstancedFoliageActor->AddFoliageType(FoliageType);

		
		// 设置资产保存的目标路径
		//FString Path = TEXT("/Game/MyFoliageTypes/"); // 自定义保存路径
		FString AssetPath;
		if(SavePath.IsEmpty())
		{
			AssetPath = TEXT("/Game/FoliageTypes/");
		}
		else
		{
			AssetPath = SavePath;
		}
		const FString AssetName = FoliageTypeName;
		const FString PackageName = AssetPath + AssetName;

		//创建一个新的空的资源包
		UPackage* NewPackage  = CreatePackage(nullptr, *PackageName);
		
		// 加载资源包到内存
		NewPackage->FullyLoad();

		// 检查资产是否已存在，如果已存在，则什么都不做
		if (UObject* ExistingAsset = FindObject<UObject>(NewPackage, *AssetName ))
		{
			return false;
		}
		
		//DuplicateObject函数创建一个新的 UFoliageType 对象，它将复制源 FoliageType 对象的属性和值，并且将outer更改为AssetPackage用于保存上面新建的FoliageType文件，在这个地方对FoliageType进行设置
		UFoliageType* FoliageTypeAsset = DuplicateObject<UFoliageType>(FoliageType, NewPackage);
		FoliageTypeAsset->SetSource(InStaticMesh);
		InstancedFoliageActor->AddFoliageType(FoliageTypeAsset);

		if (FoliageTypeAsset != nullptr)
		{
			// 标记资源包为"脏"
			bool bIsMarkedDirty = NewPackage->MarkPackageDirty();

			if (bIsMarkedDirty)
			{
				UE_LOG(LogTemp, Log, TEXT("AssetPackage has been successfully marked as dirty."));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to mark AssetPackage as dirty."));
			}
		}
		
		// 保存资产
		const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		bool const bSaved = UPackage::SavePackage(NewPackage, FoliageTypeAsset, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageName, GError, nullptr, false, true, SAVE_None);
		if (bSaved)
		{
			// 通知资产注册表有关新资产的信息
			AssetRegistryModule.Get().AddPath(AssetPath);
			
			// Scan the asset files in the specified path to update the registry
			TArray<FString> ScanPaths;
			ScanPaths.Add(AssetPath);
			AssetRegistryModule.Get().ScanPathsSynchronous(ScanPaths);

			AssetRegistryModule.Get().AssetCreated(FoliageTypeAsset);
		}
		// After saving the asset and updating the asset registry
		const FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		ContentBrowserModule.Get().SyncBrowserToAssets(TArray<FAssetData>{ FAssetData(FoliageTypeAsset) });
	
	}
	else
	{
		//如果StaticMesh指向的FoliageType已经存在或者存在多个，那就用第一个。
		FoliageType = const_cast<UFoliageType*>(FoliageTypes[0]);
	}

	// 查找Foliage Type对应的Foliage Info
	FFoliageInfo* FoliageInfo = InstancedFoliageActor->FindInfo(FoliageType);

	//如果找到了FoliageInfo
	if(FoliageInfo)
	{
		FFoliageInstance* FoliageInstance = new FFoliageInstance;
		FoliageInfo->AddInstance(InstancedFoliageActor,FoliageType, *FoliageInstance);

		if(FoliageInstance)
		{
			//Foliage Instance Index
			const int32 FoliageInstanceIndex = FoliageInfo->Instances.Num() - 1;

			//Get The New Foliage Instance
			FoliageInstance = &FoliageInfo->Instances[FoliageInstanceIndex];


			FoliageInfo->PreMoveInstances(InstancedFoliageActor,{FoliageInstanceIndex});

			
			//FoliageInstance->Location = Transform.GetLocation();

			//此处调用CheckInstanceLocationOverlap函数，检查在容差范围内是否有相同的实例要放置
			//现在先用这种方法检测，之后用SphereOverlapActors()
			/*
			FVector InstanceLocation = Transform.GetLocation();
			
			//设置位置检测容差值
			float Tolerance = 10.0f;
			if(CheckInstanceLocationOverlap(FoliageInfo, InstanceLocation, Tolerance))
			{
				// 位置已经存在实例，不要添加新实例
				UE_LOG(LogTemp,Error,TEXT("Instance already exists at the current location, No need to add !!!"))
				return false;
			}
			*/
			// 设置Foliage Instance的位置、旋转和缩放
			FoliageInstance->Location = Transform.GetLocation();
			FoliageInstance->Rotation = Transform.GetRotation().Rotator();
			const FVector Scale = Transform.GetScale3D();
			FoliageInstance->DrawScale3D = FVector(Scale.X,Scale.Y,Scale.Z);
			
			//上面通过传入FoliageInstaceGuid传到ProceduralGuid
			FoliageInstance->ProceduralGuid = FoliageInstaceGuid;
			
			//Need To Be Called After Instance Is Moved
			FoliageInfo->PostMoveInstances(InstancedFoliageActor,{ FoliageInstanceIndex });
			
			//输出植被的UUID
			
			FoliageUUIDs.Add(StaticMeshIndex, FoliageInstaceGuid);

			//刷新新指定的 InstancedFoliageActor 中的植被信息。
			FoliageInfo->Refresh(InstancedFoliageActor,true, true);
			
			return true;
			
		}
		//Refresh Foliage Editor
		//IFoliageEditModule& FoliageEditModule = FModuleManager::LoadModuleChecked<IFoliageEditModule>("FoliageEdit");
		//FoliageEditModule.UpdateMeshList();
		
	}
	return false;

}

bool UAddToInstance::RemoveFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, TArray<FGuid> FoliageInstanceUUID)
{
	//如果IFA不存在或者无效，返回false
	if(!InstancedFoliageActor || !IsValid(InstancedFoliageActor))
	{
		UE_LOG(LogTemp,Error,TEXT("Can not find InstancedFoliageActor!!!"))
		return false;
	}

	//遍历所有的FoliageInfos
	for (auto& FoliagePair:InstancedFoliageActor->FoliageInfos)
	{
		FFoliageInfo& FoliageInfo = FoliagePair.Value.Get();
		TArray<int32> InstanceIndicesToRemove;

		//遍历所有的Foliage实例，检查他们的UUID是否在要删除的数组中
		for (int32 i = 0; i<FoliageInfo.Instances.Num(); i++)
		{
			FGuid InstanceUUID = FoliageInfo.Instances[i].ProceduralGuid;
			if(FoliageInstanceUUID.Contains(InstanceUUID))
			{
				//如果找到要删除的实例，将其索引添加到要删除的实例索引数组中
				InstanceIndicesToRemove.Add(i);
			}
		}
		//对找到要删除的索引，按逆序对他们进行排序，以便在删除时不会影响其他实例的索引
		InstanceIndicesToRemove.Sort([](const int32& A, const int32& B) {return A > B; });

		//遍历要删除实例的索引数组，从FoliageInfo中删除他们
		for (int32 IndexToRemove : InstanceIndicesToRemove )
		{
			FoliageInfo.RemoveInstances(InstancedFoliageActor, TArray<int32> {IndexToRemove} ,true);
		}
		FoliageInfo.Refresh(InstancedFoliageActor,true, true);
	}
	
	return true;
}

TArray<int32> UAddToInstance::CalculateWeightAverage(const TArray<float>& Weights, int32 OutputSize)
{
	TArray<int32> result;

	// 计算权重总和
	float sum_weights = 0.0f;
	for (const float weight : Weights) {
		sum_weights += weight;
	}

	// 根据权重随机生成索引
	for (int32 i = 0; i < OutputSize; i++) {
		float rand_weight = FMath::RandRange(0.0f, sum_weights);
		float accum_weight = 0.0f;

		for (int32 j = 0; j < Weights.Num(); j++) {
			accum_weight += Weights[j];

			if (rand_weight <= accum_weight) {
				result.Add(j);
				break;
			}
		}
	}

	return result;
}

// 检查是否已经存在具有相同位置的实例
bool UAddToInstance::CheckInstanceLocationOverlap( FFoliageInfo* FoliageInfo,  FVector Location, float Tolerance)
{
	for ( FFoliageInstance& Instance : FoliageInfo->Instances)
	{
		if (FVector::DistSquared(Instance.Location, Location) <= Tolerance * Tolerance)
		{
			return true;
		}
	}
	return false;
}
