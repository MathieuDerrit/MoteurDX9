#include "moteur.h"
void Time::InitSystemTime()
{
    previousFrame = timeGetTime();
    timeScale = 1.0f;
    gameTime = 0.0f;
    deltaTime = 0.0f;
    minFrame = 1 / 30.0f;
    maxFrame = 1 / 144.0f;
}

void Time::UpdateTime()
{
    DWORD cur = timeGetTime();
    DWORD dt = cur - previousFrame;
    previousFrame = cur;

    if ((dt / 1000.0f) >= maxFrame && (dt / 1000.0f) <= minFrame)
    {
        deltaTime = dt / 1000.0f;
    }
    deltaTime *= timeScale;
    gameTime += deltaTime;
}