#include "InputManager.h"

#define BTN_A 0
#define BTN_B 1
#define BTN_X 2
#define BTN_Y 3
#define BTN_UP 10
#define BTN_DOWN 12
#define BTN_RIGHT 11
#define BTN_LEFT 13

InputManager::InputManager() {
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_X, INPUT_PULLUP);
  pinMode(BTN_Y, INPUT_PULLUP);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);

  btnA = false;
  btnB = false;
  btnX = false;
  btnY = false;
  btnUp = false;
  btnDown = false;
  btnRight = false;
  btnLeft = false;

  prevBtnA = false;
  prevBtnB = false;
  prevBtnX = false;
  prevBtnY = false;
  prevBtnUp = false;
  prevBtnDown = false;
  prevBtnRight = false;
  prevBtnLeft = false;
}

// Note that digitalRead is negated because INPUT_PULLUP reverses the value
bool InputManager::btnAPressed() {
  prevBtnA = btnA;
  btnA = !digitalRead(BTN_A);
  return btnA && !prevBtnA;
}

bool InputManager::btnAHeld() {
  return !digitalRead(BTN_A);
}

bool InputManager::btnBPressed() {
  prevBtnB = btnB;
  btnB = !digitalRead(BTN_B);
  return btnB && !prevBtnB;
}

bool InputManager::btnBHeld() {
  return !digitalRead(BTN_B);
}

bool InputManager::btnXPressed() {
  prevBtnX = btnX;
  btnX = !digitalRead(BTN_X);
  return btnX && !prevBtnX;
}

bool InputManager::btnXHeld() {
  return !digitalRead(BTN_X);
}

bool InputManager::btnYPressed() {
  prevBtnY = btnY;
  btnY = !digitalRead(BTN_Y);
  return btnY && !prevBtnY;
}

bool InputManager::btnYHeld() {
  return !digitalRead(BTN_Y);
}

bool InputManager::btnUpPressed() {
  prevBtnUp = btnUp;
  btnUp = !digitalRead(BTN_UP);
  return btnUp && !prevBtnUp;
}

bool InputManager::btnUpHeld() {
  return !digitalRead(BTN_UP);
}

bool InputManager::btnDownPressed() {
  prevBtnDown = btnDown;
  btnDown = !digitalRead(BTN_DOWN);
  return btnDown && !prevBtnDown;
}

bool InputManager::btnDownHeld() {
  return !digitalRead(BTN_DOWN);
}

bool InputManager::btnRightPressed() {
  prevBtnRight = btnRight;
  btnRight = !digitalRead(BTN_RIGHT);
  return btnRight && !prevBtnRight;
}

bool InputManager::btnRightHeld() {
  return !digitalRead(BTN_RIGHT);
}

bool InputManager::btnLeftPressed() {
  prevBtnLeft = btnLeft;
  btnLeft = !digitalRead(BTN_LEFT);
  return btnLeft && !prevBtnLeft;
}

bool InputManager::btnLeftHeld() {
  return !digitalRead(BTN_LEFT);
}
