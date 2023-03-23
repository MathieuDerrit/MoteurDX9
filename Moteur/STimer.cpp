#include "STimer.h"
#include <timeapi.h>

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
	timeGetTime() / 1000.0f - s_initTime;
	return s_deltaTime = timeGetTime();
}