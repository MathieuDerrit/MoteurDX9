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
      static int GetMouseX() { return x; }
      static int GetMouseY() { return y; }
      static int GetRawX() { return rawX; }
      static int GetRawY() { return rawY; }
      static void UpdateInput(KeyType InputType, int vKey);
private:
    static bool InputPressed[KEYTYPE_ITEM_NBR];
    static int x ;
    static int y ;
    static float rawX ;
    static float rawY ;
   
};
