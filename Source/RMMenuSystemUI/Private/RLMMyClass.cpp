// Fill out your copyright notice in the Description page of Project Settings.


#include "RLMMyClass.h"
#include "GenericPlatform/GenericApplication.h"
#include "Engine.h"
#include "Widgets/SWindow.h"



int URLMMyClass::GetDisplayCount()
{
	FDisplayMetrics Displays;
	FDisplayMetrics ::RebuildDisplayMetrics(Displays);
	return Displays.MonitorInfo.Num();
	
}

TArray<FDisplayinfo> URLMMyClass::GetAllDisplayNames()
{
	TArray<FDisplayinfo> ALLDisplays;
	FDisplayMetrics Displays;
	FDisplayMetrics ::RebuildDisplayMetrics(Displays);
	for (const FMonitorInfo& Monitor : Displays.MonitorInfo)
	{
		ALLDisplays.Add(FDisplayinfo(Monitor.Name, Monitor.ID,
	   Monitor.NativeWidth, Monitor.NativeHeight,
	   Monitor.MaxResolution,
	   Monitor.bIsPrimary, Monitor.DPI));
	}
	return ALLDisplays;
}

bool URLMMyClass::SetActiveDisplay(int32 DisplayIndex)
{
	FDisplayMetrics Displays;
	FDisplayMetrics ::RebuildDisplayMetrics(Displays);
	if (DisplayIndex < 0 || DisplayIndex >= Displays.MonitorInfo.Num())
	{
		return false;
	}
	const FMonitorInfo& Monitor = Displays.MonitorInfo[DisplayIndex];
	FVector2D WindowPosition(static_cast<float>(Monitor.WorkArea.Left), static_cast<float>(Monitor.WorkArea.Top));
	if (GEngine && GEngine->GameViewport)
	{
		TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
		GameWindow->MoveWindowTo(WindowPosition);
		UGameUserSettings *GameUserSettings = GEngine->GetGameUserSettings();
		GameUserSettings->SetScreenResolution(FIntPoint(Monitor.NativeWidth, Monitor.NativeHeight));
		GameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		GameUserSettings->ApplySettings(true);
		GameUserSettings->ApplyResolutionSettings(false);
		return true;
	}
	return false;
}
	

