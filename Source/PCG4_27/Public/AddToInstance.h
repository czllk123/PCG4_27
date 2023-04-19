// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InstancedFoliage.h"
#include "AddToInstance.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBPSelected
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=AddToFoliage)
	FName LayerToScatter = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	float Weight = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	FVector2D Scale = FVector2D(.8f, 1.3f);;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	AActor* BluePrint;
};

USTRUCT(BlueprintType)
struct FScatterData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	TMap<int32, FTransform> ScatterPointCloud; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	//直接引用上面的结构体，不需要指针
	FBPSelected CurrentBP;
};


USTRUCT(BlueprintType)
struct FPerMeshSetting
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	float Weight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	FVector2D RandomScale = FVector2D(.8f, 1.3f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AddToFoliage)
	UStaticMesh* Mesh;
};


USTRUCT(BlueprintType)
struct FLayerSetting
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	int32 ScatterCounts = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	float MatchNormalRatio = .2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	FVector2D MixMaxRadius = FVector2D(.8f, 1.3f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	FVector2D RadomZRoatation = FVector2D(0, 360);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	FPerMeshSetting Mesh;
};

USTRUCT(BlueprintType)
struct FSpawnPoints
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	FVector points;
};

USTRUCT(BlueprintType)
struct FStoredSpawns
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	FTransform PointLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AddToFoliage)
	float MatchNormalRatio = .2f;
	
};



UCLASS()
class  UAddToInstance : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category= AddToFoliage)
		static AInstancedFoliageActor* GetOrCreateIFA();


	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static bool AddToFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, UStaticMesh *InStaticMesh, int32 StaticMeshIndex, FTransform Transform, FString SavePath, TMap<int32, FGuid>& FoliageUUIDs);

	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static bool RemoveFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, TArray<FGuid> FoliageInstanceUUID);

	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static TArray<int32> CalculateWeightAverage(const TArray<float>& Weights, int32 OutputSize);

	static bool CheckInstanceLocationOverlap( FFoliageInfo* FoliageInfo,  FVector Location, float Tolerance = 0.1f);
};
