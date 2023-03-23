#pragma once
#include <Windows.h>
#include "STimer.h"

enum KeyType {
    Z,
    Q,
    S,
    D,
    Space,
    LMB,
    RMB,
    KEYTYPE_ITEM_NBR
};

class Input {
public:
    void ReadInputs();
    bool IsPressed(KeyType InputType);
    int GetMouseX() { return x; }
    int GetMouseY() { return y; }
    int GetRawX() { return rawX; }
    int GetRawY() { return rawY; }
private:
    void UpdateInput(KeyType InputType, int vKey);
    bool InputPressed[KEYTYPE_ITEM_NBR];
    int x = 0;
    int y = 0;
    float rawX = 0;
    float rawY = 0;
    STimer timer;
};
