#ifndef LedEyes_H_
#define LedEyes_H_

#include <Adafruit_NeoPixel.h>

#define EYES_EVIL_RED 200

typedef struct {
  byte r;
  byte g;
  byte b;
} RGB;

extern Adafruit_NeoPixel pixels;
extern RGB eyes_t;
extern RGB eyes_color;

void initEyes();
void setEyesStatus(int speed, int arm);
void updateEyes();

#endif /* LedEyes_H_ */
