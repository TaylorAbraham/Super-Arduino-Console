#ifndef PATPAT_H
#define PATPET_H

class PatPet {
  public:
    PatPet(Adafruit_PCD8544& d);
  private:
    Adafruit_PCD8544* display;
    void draw();
};

#endif
