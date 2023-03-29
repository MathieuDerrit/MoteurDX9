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
      void ReadInputs();
      bool IsPressed(KeyType InputType);
      int GetMouseX() {
          OutputDebugStringA("x:");
          OutputDebugStringA(std::to_string(x).append("\n").c_str()); 
          return x;
      }
      int GetMouseY() {
          OutputDebugStringA("y:");
          OutputDebugStringA(std::to_string(y).append("\n").c_str()); 
          return y; 
      }
      int GetRawX() { return rawX; }
      int GetRawY() { return rawY; }
      void UpdateInput(KeyType InputType, int vKey);

      Camera *cam;
private:
    bool InputPressed[KEYTYPE_ITEM_NBR];
    long x = 0;
    long y = 0;
    float rawX = 0.0f;
    float rawY = 0.0f;
   
};
