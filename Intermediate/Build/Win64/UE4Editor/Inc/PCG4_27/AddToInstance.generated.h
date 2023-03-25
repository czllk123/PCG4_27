// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AInstancedFoliageActor;
struct FGuid;
class UStaticMesh;
struct FTransform;
#ifdef PCG4_27_AddToInstance_generated_h
#error "AddToInstance.generated.h already included, missing '#pragma once' in AddToInstance.h"
#endif
#define PCG4_27_AddToInstance_generated_h

#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_SPARSE_DATA
#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRemoveFoliageInstance); \
	DECLARE_FUNCTION(execAddToFoliageInstance); \
	DECLARE_FUNCTION(execGetOrCreateIFA);


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRemoveFoliageInstance); \
	DECLARE_FUNCTION(execAddToFoliageInstance); \
	DECLARE_FUNCTION(execGetOrCreateIFA);


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAddToInstance(); \
	friend struct Z_Construct_UClass_UAddToInstance_Statics; \
public: \
	DECLARE_CLASS(UAddToInstance, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PCG4_27"), NO_API) \
	DECLARE_SERIALIZER(UAddToInstance)


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUAddToInstance(); \
	friend struct Z_Construct_UClass_UAddToInstance_Statics; \
public: \
	DECLARE_CLASS(UAddToInstance, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PCG4_27"), NO_API) \
	DECLARE_SERIALIZER(UAddToInstance)


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAddToInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAddToInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAddToInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAddToInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAddToInstance(UAddToInstance&&); \
	NO_API UAddToInstance(const UAddToInstance&); \
public:


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAddToInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAddToInstance(UAddToInstance&&); \
	NO_API UAddToInstance(const UAddToInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAddToInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAddToInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAddToInstance)


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_PRIVATE_PROPERTY_OFFSET
#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_13_PROLOG
#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_PRIVATE_PROPERTY_OFFSET \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_SPARSE_DATA \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_RPC_WRAPPERS \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_INCLASS \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_PRIVATE_PROPERTY_OFFSET \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_SPARSE_DATA \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_INCLASS_NO_PURE_DECLS \
	AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PCG4_27_API UClass* StaticClass<class UAddToInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AddToFoliage4_27_Plugins_PCG4_27_Source_PCG4_27_Public_AddToInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
