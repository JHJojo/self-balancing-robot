#include "LED.h"

void Led::Init() {
  begin();
  setBrightness(brightness);
  show();
}

void Led::Off(){
  clear();
  show();
}

void Led::Red() {
  for (uint16_t i = 0; i < numPixels(); i++) {
    setPixelColor(i, 255, 0, 0);
    show();
  }
}

void Led::Green() {
  for (uint16_t i = 0; i < numPixels(); i++) {
    setPixelColor(i, 0, 255, 0);
    show();
  }
}

void Led::Blue() {
  for (uint16_t i = 0; i < numPixels(); i++) {
    setPixelColor(i, 0, 0, 255);
    show();
  }
}

void Led::Left(uint32_t color){
  Off();
  setPixelColor(1, color);
  setPixelColor(2, color);
  show();
}

void Led::Right(uint32_t color){
  Off();
  setPixelColor(0, color);
  setPixelColor(3, color);
  show();
}

void Led::Front(uint32_t color){
  Off();
  setPixelColor(2, color);
  setPixelColor(3, color);
  show();
}

void Led::Back(uint32_t color){
  Off();
  setPixelColor(0, color);
  setPixelColor(1, color);
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
