#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H  

class InputManager {
  public:
    InputManager();
    bool btnAPressed();
    bool btnAHeld();
    bool btnBPressed();
    bool btnBHeld();
    bool btnXPressed();
    bool btnXHeld();
    bool btnYPressed();
    bool btnYHeld();
    bool btnUpPressed();
    bool btnUpHeld();
    bool btnDownPressed();
    bool btnDownHeld();
    bool btnRightPressed();
    bool btnRightHeld();
    bool btnLeftPressed();
    bool btnLeftHeld();
  private:
    bool btnA, btnB, btnX, btnY;
    bool btnUp, btnDown, btnRight, btnLeft;
    bool prevBtnA, prevBtnB, prevBtnX, prevBtnY;
    bool prevBtnUp, prevBtnDown, prevBtnRight, prevBtnLeft;
};

#endif
