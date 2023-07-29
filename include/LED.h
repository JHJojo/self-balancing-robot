#ifndef Led_H
#define Led_H

#include "Adafruit_NeoPixel.h"
#include "Pins.h"
#define NUMPIXELS 4

class Led : public Adafruit_NeoPixel{
public:
  Led() : Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800){}
  void Init();

  void Red(int pixel_number);
  void Green(int pixel_number);
  void Blue(int pixel_number);

  void ColorWipe(uint32_t color, int wait);
  void Rainbow(int wait);

private:
    int brightness = 50;

};

#endif