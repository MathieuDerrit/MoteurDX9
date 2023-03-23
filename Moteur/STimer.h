#include <Windows.h>
#include <winnt.h>
#include <profileapi.h>
#include <timeapi.h>

class STimer
{
private:
    float s_initTime;
    bool s_isPerformanceTimer;
    float s_frequency;
    int s_performTime;

public:
    void InitSystemTime();
    float GetSystemTimeEx();
    float s_deltaTime;
};