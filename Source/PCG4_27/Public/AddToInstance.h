// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InstancedFoliage.h"
#include "AddToInstance.generated.h"

/**
 * 
 */
UCLASS()
class  UAddToInstance : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category= AddToFoliage)
		static AInstancedFoliageActor* GetOrCreateIFA();


	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static bool AddToFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, UStaticMesh *InStaticMesh, FTransform Transform, FString SavePath, FGuid& FoliageUUID);

	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static bool RemoveFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, TArray<FGuid> FoliageInstanceUUID);

	static bool CheckInstanceLocationOverlap( FFoliageInfo* FoliageInfo,  FVector Location, float Tolerance = 0.1f);
};
