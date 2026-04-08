// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Displayinfo.h"
#include "ExtendedUserSettingSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract,Blueprintable)
class RMMENUSYSTEMUI_API UExtendedUserSettingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "ExtendedUserSettingSubsystem")
	TArray<FDisplayinfo> GetAlDisplayInfo() const;

	UFUNCTION(BlueprintCallable, Category = "ExtendedUserSettingSubsystem")
	void SetActiveDisplayInfo(const FString& DisplayId);
};
