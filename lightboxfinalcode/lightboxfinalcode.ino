//hi
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 9
#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

int p;
int x;
int y;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(26, INPUT);
  pinMode(27, INPUT);
}

void loop() {
  p = analogRead(A3);
  if (p < 512) {
    y = map(p, 0, 512, 0, 6);
    for (x = 0; x < 6; x++) {
      if (x < y) {
        pixels.setPixelColor(x, pixels.Color(250, 250, 250));
        pixels.setPixelColor(11 - x, pixels.Color(250, 250, 250));
      } else {
        pixels.setPixelColor(x, pixels.Color(0, 0, 0));
        pixels.setPixelColor(11 - x, pixels.Color(0, 0, 0));
      }
    }
    Serial.print(y);
    Serial.print(';');
    Serial.println(p);
    pixels.show();
  } else {
    y = map(p, 512, 1023, 0, 6);
    for (x = 0; x < 6; x++) {
      if (x < y) {
        pixels.setPixelColor(x, pixels.Color(0, 0, 0));
        pixels.setPixelColor(11 - x, pixels.Color(0, 0, 0));
      } else {
        pixels.setPixelColor(x, pixels.Color(250, 250, 250));
        pixels.setPixelColor(11 - x, pixels.Color(250, 250, 250));
      }
    }
    Serial.print(y);
    Serial.print(';');
    Serial.println(p);
    pixels.show();
  }

}
