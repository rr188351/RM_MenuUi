// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtendedUserSettingSubsystem.h"
#include "GenericPlatform/GenericApplication.h"
#include "GenericPlatform/GenericPlatformApplicationMisc.h"
#include "Widgets/SWindow.h"


TArray<FDisplayinfo> UExtendedUserSettingSubsystem::GetAlDisplayInfo() const
{
	TArray<FDisplayinfo> MonitorInfoArray;
    FDisplayMetrics DisplayMetrics;
	FDisplayMetrics ::RebuildDisplayMetrics(DisplayMetrics);
	for (const FMonitorInfo& MonitorInfo : DisplayMetrics.MonitorInfo)
	{
		MonitorInfoArray.Add(FDisplayinfo(MonitorInfo.Name, MonitorInfo.ID,
			MonitorInfo.NativeWidth, MonitorInfo.NativeHeight,
			MonitorInfo.MaxResolution,
			MonitorInfo.bIsPrimary, MonitorInfo.DPI));
	}
	return MonitorInfoArray;
}

void UExtendedUserSettingSubsystem::SetActiveDisplayInfo(const FString& DisplayId)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics ::RebuildDisplayMetrics(DisplayMetrics);
	for (const FMonitorInfo& MonitorInfo : DisplayMetrics.MonitorInfo)
	{
		if (MonitorInfo.ID == DisplayId)
		{
			FVector2D NewWindowPosition(MonitorInfo.WorkArea.Left, MonitorInfo.WorkArea.Top);
			FVector2D NewWindowSize(MonitorInfo.WorkArea.Right - MonitorInfo.WorkArea.Left, MonitorInfo.WorkArea.Bottom - MonitorInfo.WorkArea.Top);
			if (GEngine && GEngine->GameViewport)
			{
				TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
				if (GameWindow.IsValid())
				{
					GameWindow->MoveWindowTo(NewWindowPosition);
					GameWindow->Resize(NewWindowSize);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Game window is not valid."));
				}
				
			}
			return;
		}
	}
}
