#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "InputManager.h"
#include "PatPet.h"

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
    PatPet game(display);
  }
  if (inMgr.btnBPressed()) {
    count /= 2;
  }
}

void drawMenu() {
  display.setTextSize(1);
  display.clearDisplay();
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, 0);
  display.print("SELECT A GAME");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0, 15);
  display.print(">PatPet");
  display.display();
}
