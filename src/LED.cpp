#include "LED.h"

void Led::Init() {
  begin();
  setBrightness(brightness);
  show();
}

void Led::Red(int pixel_number) {
  setPixelColor(pixel_number, 255, 0, 0);
  show();
}

void Led::Green(int pixel_number) {
  setPixelColor(pixel_number, 0, 255, 0);
  show();
}

void Led::Blue(int pixel_number) {
  setPixelColor(pixel_number, 0, 0, 255);
  show();
}

void Led::ColorWipe(uint32_t color, int wait) {
  for (uint16_t i = 0; i < numPixels(); i++) {
    setPixelColor(i, color);
    show();
    delay(wait);
  }
}

void Led::Rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    rainbow(firstPixelHue);
    show();
    delay(wait);
  }
}
