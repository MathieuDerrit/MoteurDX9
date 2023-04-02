class Time
{
public:
    DWORD initTime, previousFrame;
    float deltaTime, timeScale, gameTime, maxFrame, minFrame;
    void InitSystemTime();
    void UpdateTime();
};