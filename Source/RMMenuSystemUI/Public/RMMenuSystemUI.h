//copyrights Unreal
#pragma once
#include "Modules/ModuleManager.h"

class RMMenuSystemUIModule :public IModuleInterface
{
    public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

};
