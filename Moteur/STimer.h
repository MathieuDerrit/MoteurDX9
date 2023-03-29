#pragma once
#include <Windows.h>
#include <winnt.h>
#include <profileapi.h>
#include <timeapi.h>

class STimer
{
private:
    static float s_initTime;
    static bool s_isPerformanceTimer;
    static float s_frequency;
    static int s_performTime; 
public:
    static void InitSystemTime();
    static float GetSystemTimeEx();
    static void UpdateDeltaTime();

    static float s_deltaTime;
    static float s_timeUpdate;
    static float s_timeScale;
    static float s_SystemScaledTimeEx;
};