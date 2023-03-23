#include "Input.h"

void Input::ReadInputs()
{
    UpdateInput(Z, 'Z');
    UpdateInput(Q, 'Q');
    UpdateInput(S, 'S');
    UpdateInput(D, 'D');
    UpdateInput(Space, VK_SPACE);
    UpdateInput(LMB, VK_LBUTTON);
    UpdateInput(RMB, VK_RBUTTON);
    POINT newMousePos;
    if (GetCursorPos(&newMousePos)) {

        rawX = static_cast<float>((newMousePos.x - x)) * timer.s_deltaTime;
        rawY = static_cast<float>((newMousePos.y - y)) * timer.s_deltaTime;
        x = newMousePos.x;
        y = newMousePos.y;
    }
}

bool Input::IsPressed(KeyType InputType)
{
    return InputPressed[InputType];
}

void Input::UpdateInput(KeyType InputType, int vKey)
{
    if (GetAsyncKeyState(vKey))
    {

        InputPressed[InputType] = true;                
    }
    else {
        InputPressed[InputType] = false;
    }
}