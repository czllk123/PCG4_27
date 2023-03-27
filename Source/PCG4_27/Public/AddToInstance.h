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
		static bool AddToFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, UStaticMesh *InStaticMesh, int32 StaticMeshIndex, FTransform Transform, FString SavePath, TMap<int32, FGuid>& FoliageUUIDs);

	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static bool RemoveFoliageInstance(AInstancedFoliageActor* InstancedFoliageActor, TArray<FGuid> FoliageInstanceUUID);

	UFUNCTION(BlueprintCallable, Category=AddToFoliage)
		static TArray<int32> CalculateWeightAverage(const TArray<float>& Weights, int32 OutputSize);

	static bool CheckInstanceLocationOverlap( FFoliageInfo* FoliageInfo,  FVector Location, float Tolerance = 0.1f);
};
