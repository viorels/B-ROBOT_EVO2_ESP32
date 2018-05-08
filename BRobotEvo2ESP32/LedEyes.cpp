#include "LedEyes.h"
#include "defines.h"

#define EYES_NUM 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(2, PIN_LEDS, NEO_GRB + NEO_KHZ800);

RGB eyes_t = {0, 0, 0};   // transition color
RGB eyes_color = {100, 0, 0};

void initEyes() {
  pixels.begin();

  for (int i = 0; i < EYES_NUM; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 50)); // Moderately bright blue color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

int bringByteCloser(byte value, byte target, byte step) {
  if (value < target) {
    if (value + step <= 255) {
      value += step;
    } else {
      value = 255;
    }
  } else if (value > target) {
    if (value - step >= 0) {
      value -= step;
    } else {
      value = 0;
    }
  }
  return value;
}

void updateEyes() {
  byte step = 1;
  RGB eyes_change = {
    r: bringByteCloser(eyes_t.r, eyes_color.r, step),
    g: bringByteCloser(eyes_t.g, eyes_color.g, step),
    b: bringByteCloser(eyes_t.b, eyes_color.b, step),
  };
  eyes_t = eyes_change;

  // Update eyes led colors
  for (int i = 0; i < 2; i++) {
    pixels.setPixelColor(i, pixels.Color(eyes_t.r, eyes_t.g, eyes_t.b)); // Moderately bright blue color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}


