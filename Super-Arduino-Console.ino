#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "InputManager.h"
#include "src/games/PatPet.h"

#define LCD_BL 7

enum Game {PATPET, TIPPLETOPPLE, SLIPPERYBOI, NUM_GAMES};
int numGames = NUM_GAMES;
int selectedGame = 0;

boolean backlight = true;
int contrast = 50;

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
    Serial.write("Starting PatPet!\n");
    PatPet game(display);
  }
  if (inMgr.btnUpPressed()) {
    if (selectedGame > 0) {
      selectedGame -= 1;
    } else {
      selectedGame = numGames - 1;
    }
  }
  if (inMgr.btnDownPressed()) {
    if (selectedGame < numGames - 1) {
      selectedGame += 1;
    } else {
      selectedGame = 0;
    }
  }
}

void drawMenu() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, 0);
  display.print("SELECT A GAME");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0, 15);
  if (selectedGame == PATPET) {
    display.print(">PatPet");
  } else {
    display.print(" PatPet");
  }
  display.setCursor(0, 25);
  if (selectedGame == TIPPLETOPPLE) {
    display.print(">TippleTopple");
  } else {
    display.print(" TippleTopple");
  }
  display.setCursor(0, 35);
  if (selectedGame == SLIPPERYBOI) {
    display.print(">SlipperyBoi");
  } else {
    display.print(" SlipperyBoi");
  }

  display.display();
}
