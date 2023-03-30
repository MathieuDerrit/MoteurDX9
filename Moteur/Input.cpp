#include "moteur.h"



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
        x = 0;
        y = 0;
        x += (150 - newMousePos.x);
        y += (150 - newMousePos.y);
        if (newMousePos.x != 150) {
            //cam->m_transform.rotate(x * 0.01f, 0.0f, 0.0f);
        }
        
        //OutputDebugStringA(std::to_string(newMousePos.x).append("\n").c_str()); 

        //OutputDebugStringA(std::to_string(y).append("\n").c_str()); 

        SetCursorPos(150, 150);
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