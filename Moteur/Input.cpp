#include "moteur.h"

<<<<<<< HEAD
 bool Input::InputPressed[KEYTYPE_ITEM_NBR];
 float Input::x = 0;
 float Input::y = 0;
 float Input::rawX = 0.0f;
 float Input::rawY = 0.0f;
=======

>>>>>>> fix

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
<<<<<<< HEAD
    if (GetCursorPos(&newMousePos)) {
        rawX = static_cast<float>((newMousePos.x - x)) * STimer::s_deltaTime;
        rawY = static_cast<float>((newMousePos.y - y)) * STimer::s_deltaTime; 
        x = newMousePos.x;
        y = newMousePos.y;
=======
    if (GetCursorPos(&newMousePos)) {  
        x = 0;
        y = 0;
        x += -(150 - newMousePos.x);
        y += -(150 - newMousePos.y);
        if (newMousePos.x != 150) {
            cam->m_transform.rotate(x * 0.01f, 0.0f, 0.0f);
        }
        
        //OutputDebugStringA(std::to_string(newMousePos.x).append("\n").c_str()); 

        //OutputDebugStringA(std::to_string(y).append("\n").c_str()); 

        SetCursorPos(150, 150);
>>>>>>> fix
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