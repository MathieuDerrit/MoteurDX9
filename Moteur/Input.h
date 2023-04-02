#pragma once

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
      static void ReadInputs();
      static bool IsPressed(KeyType InputType);
      static float GetMouseX() { return x; }
      static float GetMouseY() { return y; }
      static float GetRawX() { return rawX; }
      static float GetRawY() { return rawY; }
      static void UpdateInput(KeyType InputType, int vKey);
private:
    static bool InputPressed[KEYTYPE_ITEM_NBR];
    static float x ;
    static float y ;
    static float rawX ;
    static float rawY ;

   
};
