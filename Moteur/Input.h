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
      float GetMouseX() {
          OutputDebugStringA("x:");
          OutputDebugStringA(std::to_string(x).append("\n").c_str()); 
          return x;
      }
      float GetMouseY() {
          OutputDebugStringA("y:");
          OutputDebugStringA(std::to_string(y).append("\n").c_str()); 
          return y; 
      }
      float GetRawX() { return rawX; }
      float GetRawY() { return rawY; }
      void UpdateInput(KeyType InputType, int vKey);

      Camera *cam;
private:
    float mouseSpeed = 0.0001f;
    bool InputPressed[KEYTYPE_ITEM_NBR];
    float x = 0;
    float y = 0;
    float rawX = 0.0f;
    float rawY = 0.0f;
   
};
