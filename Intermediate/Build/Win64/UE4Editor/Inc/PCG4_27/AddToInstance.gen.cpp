// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCG4_27/Public/AddToInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAddToInstance() {}
// Cross Module References
	PCG4_27_API UClass* Z_Construct_UClass_UAddToInstance_NoRegister();
	PCG4_27_API UClass* Z_Construct_UClass_UAddToInstance();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_PCG4_27();
	FOLIAGE_API UClass* Z_Construct_UClass_AInstancedFoliageActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
// End Cross Module References
	DEFINE_FUNCTION(UAddToInstance::execRemoveFoliageInstance)
	{
		P_GET_OBJECT(AInstancedFoliageActor,Z_Param_InstancedFoliageActor);
		P_GET_TARRAY(FGuid,Z_Param_FoliageInstanceUUID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UAddToInstance::RemoveFoliageInstance(Z_Param_InstancedFoliageActor,Z_Param_FoliageInstanceUUID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAddToInstance::execAddToFoliageInstance)
	{
		P_GET_OBJECT(AInstancedFoliageActor,Z_Param_InstancedFoliageActor);
		P_GET_OBJECT(UStaticMesh,Z_Param_InStaticMesh);
		P_GET_PROPERTY(FIntProperty,Z_Param_StaticMeshIndex);
		P_GET_STRUCT(FTransform,Z_Param_Transform);
		P_GET_PROPERTY(FStrProperty,Z_Param_SavePath);
		P_GET_TMAP_REF(int32,FGuid,Z_Param_Out_FoliageUUIDs);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UAddToInstance::AddToFoliageInstance(Z_Param_InstancedFoliageActor,Z_Param_InStaticMesh,Z_Param_StaticMeshIndex,Z_Param_Transform,Z_Param_SavePath,Z_Param_Out_FoliageUUIDs);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAddToInstance::execGetOrCreateIFA)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AInstancedFoliageActor**)Z_Param__Result=UAddToInstance::GetOrCreateIFA();
		P_NATIVE_END;
	}
	void UAddToInstance::StaticRegisterNativesUAddToInstance()
	{
		UClass* Class = UAddToInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddToFoliageInstance", &UAddToInstance::execAddToFoliageInstance },
			{ "GetOrCreateIFA", &UAddToInstance::execGetOrCreateIFA },
			{ "RemoveFoliageInstance", &UAddToInstance::execRemoveFoliageInstance },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics
	{
		struct AddToInstance_eventAddToFoliageInstance_Parms
		{
			AInstancedFoliageActor* InstancedFoliageActor;
			UStaticMesh* InStaticMesh;
			int32 StaticMeshIndex;
			FTransform Transform;
			FString SavePath;
			TMap<int32,FGuid> FoliageUUIDs;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstancedFoliageActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InStaticMesh;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_StaticMeshIndex;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SavePath;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FoliageUUIDs_ValueProp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FoliageUUIDs_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_FoliageUUIDs;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_InstancedFoliageActor = { "InstancedFoliageActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, InstancedFoliageActor), Z_Construct_UClass_AInstancedFoliageActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_InStaticMesh = { "InStaticMesh", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, InStaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_StaticMeshIndex = { "StaticMeshIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, StaticMeshIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_SavePath = { "SavePath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, SavePath), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs_ValueProp = { "FoliageUUIDs", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs_Key_KeyProp = { "FoliageUUIDs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs = { "FoliageUUIDs", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventAddToFoliageInstance_Parms, FoliageUUIDs), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AddToInstance_eventAddToFoliageInstance_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AddToInstance_eventAddToFoliageInstance_Parms), &Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_InstancedFoliageActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_InStaticMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_StaticMeshIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_SavePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_FoliageUUIDs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "AddToFoliage" },
		{ "ModuleRelativePath", "Public/AddToInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAddToInstance, nullptr, "AddToFoliageInstance", nullptr, nullptr, sizeof(AddToInstance_eventAddToFoliageInstance_Parms), Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics
	{
		struct AddToInstance_eventGetOrCreateIFA_Parms
		{
			AInstancedFoliageActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventGetOrCreateIFA_Parms, ReturnValue), Z_Construct_UClass_AInstancedFoliageActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::Function_MetaDataParams[] = {
		{ "Category", "AddToFoliage" },
		{ "ModuleRelativePath", "Public/AddToInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAddToInstance, nullptr, "GetOrCreateIFA", nullptr, nullptr, sizeof(AddToInstance_eventGetOrCreateIFA_Parms), Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics
	{
		struct AddToInstance_eventRemoveFoliageInstance_Parms
		{
			AInstancedFoliageActor* InstancedFoliageActor;
			TArray<FGuid> FoliageInstanceUUID;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstancedFoliageActor;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FoliageInstanceUUID_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FoliageInstanceUUID;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_InstancedFoliageActor = { "InstancedFoliageActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventRemoveFoliageInstance_Parms, InstancedFoliageActor), Z_Construct_UClass_AInstancedFoliageActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_FoliageInstanceUUID_Inner = { "FoliageInstanceUUID", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_FoliageInstanceUUID = { "FoliageInstanceUUID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AddToInstance_eventRemoveFoliageInstance_Parms, FoliageInstanceUUID), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AddToInstance_eventRemoveFoliageInstance_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AddToInstance_eventRemoveFoliageInstance_Parms), &Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_InstancedFoliageActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_FoliageInstanceUUID_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_FoliageInstanceUUID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "AddToFoliage" },
		{ "ModuleRelativePath", "Public/AddToInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAddToInstance, nullptr, "RemoveFoliageInstance", nullptr, nullptr, sizeof(AddToInstance_eventRemoveFoliageInstance_Parms), Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAddToInstance_NoRegister()
	{
		return UAddToInstance::StaticClass();
	}
	struct Z_Construct_UClass_UAddToInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAddToInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PCG4_27,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAddToInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAddToInstance_AddToFoliageInstance, "AddToFoliageInstance" }, // 2474687335
		{ &Z_Construct_UFunction_UAddToInstance_GetOrCreateIFA, "GetOrCreateIFA" }, // 3550168888
		{ &Z_Construct_UFunction_UAddToInstance_RemoveFoliageInstance, "RemoveFoliageInstance" }, // 3095065209
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAddToInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AddToInstance.h" },
		{ "ModuleRelativePath", "Public/AddToInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAddToInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAddToInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAddToInstance_Statics::ClassParams = {
		&UAddToInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAddToInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAddToInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAddToInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAddToInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAddToInstance, 1336961836);
	template<> PCG4_27_API UClass* StaticClass<UAddToInstance>()
	{
		return UAddToInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAddToInstance(Z_Construct_UClass_UAddToInstance, &UAddToInstance::StaticClass, TEXT("/Script/PCG4_27"), TEXT("UAddToInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAddToInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
