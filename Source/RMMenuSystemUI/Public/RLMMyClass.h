// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Displayinfo.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RLMMyClass.generated.h"

/**
 * 
 */
UCLASS()
class RMMENUSYSTEMUI_API URLMMyClass : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Dispaly")
	static int GetDisplayCount();
	UFUNCTION(BlueprintCallable, Category = "Dispaly")
	static TArray<FDisplayinfo> GetAllDisplayNames();
	UFUNCTION(BlueprintCallable, Category = "Dispaly")
	static bool SetActiveDisplay(int32 DisplayIndex);
	
};
