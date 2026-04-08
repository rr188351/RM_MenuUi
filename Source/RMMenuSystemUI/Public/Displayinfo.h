// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "Displayinfo.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct  RMMENUSYSTEMUI_API FDisplayinfo 
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	FString Name;
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	FString ID;
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	int32 NativeWidth;
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	int32 NativeHight;
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	FIntPoint MaxResolution =FIntPoint(ForceInitToZero);
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	bool bIsPrimary;
	UPROPERTY(BlueprintReadOnly,Category="DisplayInfo")
	int DPI=0;

	FDisplayinfo()
	{
		Name = FString("");
		ID = FString("");
		NativeWidth = 0;
		NativeHight = 0;
		MaxResolution = FIntPoint(ForceInitToZero);
		bIsPrimary = false;
		DPI = 0;
	}
	FDisplayinfo(const FString& InName, const FString& InID, int32 InNativeWidth, int32 InNativeHight, const FIntPoint& InMaxResolution, bool bInIsPrimary, int InDPI)
	:Name(InName),
	ID(InID),
	NativeWidth(InNativeWidth),
	NativeHight(InNativeHight),
	MaxResolution(InMaxResolution),
	bIsPrimary(bInIsPrimary),
	DPI(InDPI)
	{
	}
};
