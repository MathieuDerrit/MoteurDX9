#include "moteur.h"

 bool Input::InputPressed[KEYTYPE_ITEM_NBR];
 float Input::x = 0;
 float Input::y = 0;
 float Input::rawX = 0.0f;
 float Input::rawY = 0.0f;

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
        rawX = static_cast<float>((newMousePos.x - x)) * STimer::s_deltaTime;
        rawY = static_cast<float>((newMousePos.y - y)) * STimer::s_deltaTime; 
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