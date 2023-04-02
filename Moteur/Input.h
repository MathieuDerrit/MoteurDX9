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
<<<<<<< HEAD
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

=======
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
>>>>>>> fix
   
};
