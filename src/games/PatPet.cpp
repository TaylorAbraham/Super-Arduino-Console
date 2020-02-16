#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "PatPet.h"

PatPet::PatPet(Adafruit_PCD8544& d) {
  display = &d;
  while (true) {
    draw();
  }
}

void PatPet::draw() {
  display->setTextSize(1);
  display->clearDisplay();
  display->setTextColor(BLACK, WHITE);
  display->setCursor(15, 0);
  display->print("PATPET");
  display->drawFastHLine(0,10,83,BLACK);
  display->setCursor(0, 15);
  display->print("Welcome to PatPet!!");
  display->display();
}
