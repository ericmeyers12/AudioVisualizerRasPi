#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_PIXELS 30
#define DEBUG 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// initiate number of strips
//Adafruit_NeoPixel s, strip;

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(NUM_PIXELS, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(NUM_PIXELS, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(NUM_PIXELS, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(NUM_PIXELS, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_5 = Adafruit_NeoPixel(NUM_PIXELS, 6, NEO_GRB + NEO_KHZ800);

//Adafruit_NeoPixel strip_6 = Adafruit_NeoPixel(NUM_PIXELS, 7, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_7 = Adafruit_NeoPixel(NUM_PIXELS, 8, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_8 = Adafruit_NeoPixel(NUM_PIXELS, 9, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_9 = Adafruit_NeoPixel(NUM_PIXELS, 10, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_10 = Adafruit_NeoPixel(NUM_PIXELS, 11, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
#ifdef DEBUG
Serial.begin(9600);
#endif

  strip_1.begin();
  strip_2.begin();
  strip_3.begin();
  strip_4.begin();
  strip_5.begin();


  strip_1.show(); // Initialize all pixels to 'off'
  strip_2.show();    
  strip_3.show();
  strip_4.show();
  strip_5.show();  

}

void loop() {
  // Some example procedures showing how to display to the pixels:
//  swirlCycle(50);
//  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
//  theaterChase(strip.Color(127, 127, 127), 50); // White
//  theaterChase(strip.Color(127, 0, 0), 50); // Red
//  theaterChase(strip.Color(0, 0, 127), 50); // Blue

//  rainbow(20);
//  rainbowCycle(20);
//  theaterChaseRainbow(50);
  snakeTest(strip_5.Color(127,0,127),10,10);
  snakeTest(strip_5.Color(127,127,0),5,10);
  snakeTest(strip_5.Color(0,127,127),14,10);
}




// Fill the dots one after the other with a color
void snakeTest(uint32_t c, uint16_t snakelength, uint8_t wait) {
  for(uint16_t i=0; i<(strip_5.numPixels()+snakelength); i++) { //coming up strip 5
    if(i<strip_5.numPixels()) {
      strip_5.setPixelColor(i, c);
    }
    if(i>=snakelength) {
      strip_5.setPixelColor(i-snakelength,0);
    }
    strip_5.show();
    delay(wait);
  }

  for(uint16_t i=(strip_4.numPixels()+snakelength); i>0; i--) { //coming down strip 4
    if(i>=snakelength+1) {
      strip_4.setPixelColor(i-snakelength-1, c);
    }
    if(i<strip_4.numPixels()+1) {
      strip_4.setPixelColor(i-1,0);
    }
    strip_4.show();
    delay(wait);
  }

  for(uint16_t i=0; i<(strip_3.numPixels()+snakelength); i++) { //coming up strip 3
    if(i<strip_3.numPixels()) {
      strip_3.setPixelColor(i, c);
    }
    if(i>=snakelength) {
      strip_3.setPixelColor(i-snakelength,0);
    }
    strip_3.show();
    delay(wait);
  }

  for(uint16_t i=(strip_2.numPixels()+snakelength); i>0; i--) { //coming down strip 2
    if(i>=snakelength+1) {
      strip_2.setPixelColor(i-snakelength-1, c);
    }
    if(i<strip_2.numPixels()+1) {
      strip_2.setPixelColor(i-1,0);
    }
    strip_2.show();
    delay(wait);
  }

  for(uint16_t i=0; i<(strip_1.numPixels()+snakelength); i++) { //coming up strip 1
    if(i<strip_1.numPixels()) {
      strip_1.setPixelColor(i, c);
    }
    if(i>=snakelength) {
      strip_1.setPixelColor(i-snakelength,0);
    }
    strip_1.show();
    delay(wait);
  }
}

// moves pixels from the center in and out
void swirlCycle(uint8_t wait) {
  uint16_t i=strip_5.numPixels()/2, j, k;
for(k=0; k<10; k++) {
  for(j=0; j<=(strip_5.numPixels()/2); j++) {
      strip_5.setPixelColor((i+j),BarColor(j));
      strip_5.setPixelColor((i-j),BarColor(j));
      strip_5.show();
      delay(wait);
  }
  for(j=(strip_5.numPixels()/2); j>0; j--) {
      strip_5.setPixelColor((i+j),0);
      strip_5.setPixelColor((i-j),0);
      strip_5.show();
      delay(wait);
  }
}
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip_5.numPixels(); i++) {
      strip_5.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip_5.show();
    delay(wait);
  }
}


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip_5.numPixels(); i++) {
      strip_5.setPixelColor(i, Wheel(((i * 256 / strip_5.numPixels()) + j) & 255));
    }
    strip_5.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip_5.numPixels(); i=i+3) {
        strip_5.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip_5.show();

      delay(wait);

      for (uint16_t i=0; i < strip_5.numPixels(); i=i+3) {
        strip_5.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip_5.numPixels(); i=i+3) {
        strip_5.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip_5.show();

      delay(wait);

      for (uint16_t i=0; i < strip_5.numPixels(); i=i+3) {
        strip_5.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

uint32_t BarColor(byte WheelPos) {
  WheelPos = WheelPos & 255;
  if(WheelPos <= (NUM_PIXELS/6)) {
    return strip_5.Color(0, 0, 255);
  }
  if(WheelPos <= (NUM_PIXELS/3)) {
    WheelPos -= (NUM_PIXELS/6);
    return strip_5.Color(0, WheelPos * (255/(NUM_PIXELS/6)), 255 - WheelPos * (255/(NUM_PIXELS/6)));
  }
  WheelPos -= (NUM_PIXELS/3);
  return strip_5.Color(WheelPos * (255/(NUM_PIXELS/6)), 255 - WheelPos * (255/(NUM_PIXELS/6)), 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip_5.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip_5.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip_5.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
