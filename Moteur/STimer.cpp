#include "moteur.h"

 float STimer::s_initTime = 0.0f;
 bool STimer::s_isPerformanceTimer = false;
 float STimer::s_frequency = 0.0f;
 int STimer::s_performTime = 0;
 float STimer::s_deltaTime = 0.0f;
 float STimer::s_timeUpdate = 0.0f;
 float STimer::s_timeScale = 0.0f;
 float STimer::s_SystemScaledTimeEx = 0.0f;

void STimer::InitSystemTime()
{
	s_initTime = timeGetTime() / 1000.0f;
	s_isPerformanceTimer = false;
	s_frequency = 0.0f;
	LARGE_INTEGER frequency;
	memset(&frequency, 0, sizeof(LARGE_INTEGER));
	if (QueryPerformanceFrequency(&frequency) && frequency.QuadPart)
	{
		s_isPerformanceTimer = true;
		s_frequency = (float)frequency.QuadPart;
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		s_performTime = counter.QuadPart;
	}
}

float STimer::GetSystemTimeEx()
{
	// Performance
	if (s_isPerformanceTimer)
	{
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		return (float)(counter.QuadPart - s_performTime) / s_frequency;
	}

	// Classic
	return timeGetTime() / 1000.0f - s_initTime;
}

void STimer::UpdateDeltaTime()
{
	float tempTime = GetSystemTimeEx();
	s_deltaTime = (tempTime - s_timeUpdate) * s_timeScale;
	s_timeUpdate = tempTime;
	s_SystemScaledTimeEx += s_deltaTime;
}