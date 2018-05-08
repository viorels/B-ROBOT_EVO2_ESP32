#ifndef LedEyes_H_
#define LedEyes_H_

#include <Adafruit_NeoPixel.h>

typedef struct {
  byte r;
  byte g;
  byte b;
} RGB;

extern Adafruit_NeoPixel pixels;
extern RGB eyes_t;
extern RGB eyes_color;

void initEyes();
void updateEyes();

#endif /* LedEyes_H_ */
