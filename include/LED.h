#ifndef Led_H
#define Led_H

#include "Adafruit_NeoPixel.h"
#include "Pins.h"
#define NUMPIXELS 4

class Led : public Adafruit_NeoPixel{
public:
  Led() : Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800){}
  void Init();

  void Off();
  void Red();
  void Green();
  void Blue();

  void Left(uint32_t color);
  void Right(uint32_t color);
  void Front(uint32_t color);
  void Back(uint32_t color);

  void ColorWipe(uint32_t color, int wait);
  void Rainbow(int wait);

private:
    int brightness = 30;

};

#endif