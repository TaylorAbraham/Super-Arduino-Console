#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "InputManager.h"

#define LCD_BL 7

boolean backlight = true;
int contrast = 50;
int count = 0;

Adafruit_PCD8544 display = Adafruit_PCD8544(9, 8, 4, 5, 6);
InputManager inMgr;

void setup() {
  Serial.begin(9600);

  pinMode(LCD_BL, OUTPUT);

  display.begin();
  display.setContrast(contrast);
  display.clearDisplay();
  display.display();
}

void loop() {
  drawMenu();
  digitalWrite(LCD_BL, HIGH); // Turn backlight on
  if (inMgr.btnAPressed()) {
    count++;
  }
  if (inMgr.btnBPressed()) {
    count /= 2;
  }
}

void drawMenu() {
  display.setTextSize(1);
  display.clearDisplay();
  display.setTextColor(BLACK, WHITE);
  display.setCursor(15, 0);
  display.print("MAIN MENU");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0, 15);
  display.print(count);
  display.setCursor(0, 35);
  display.print(">Reset");
  display.display();
}
