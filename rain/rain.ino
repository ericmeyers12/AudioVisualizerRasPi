#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_PIXELS 30
#define NUM_LED_STRIPS 5
#define WAIT 50
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
Adafruit_NeoPixel s;

Adafruit_NeoPixel strip_0 = Adafruit_NeoPixel(NUM_PIXELS, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(NUM_PIXELS, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(NUM_PIXELS, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(NUM_PIXELS, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(NUM_PIXELS, 6, NEO_GRB + NEO_KHZ800);

//Adafruit_NeoPixel strip_5 = Adafruit_NeoPixel(NUM_PIXELS, 7, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_6 = Adafruit_NeoPixel(NUM_PIXELS, 8, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_7 = Adafruit_NeoPixel(NUM_PIXELS, 9, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_8 = Adafruit_NeoPixel(NUM_PIXELS, 10, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip_9 = Adafruit_NeoPixel(NUM_PIXELS, 11, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
#ifdef DEBUG
Serial.begin(9600);
#endif



 
  
  strip_0.begin();
  strip_1.begin();
  strip_2.begin();
  strip_3.begin();
  strip_4.begin();


  strip_0.show(); // Initialize all pixels to 'off'
  strip_1.show();    
  strip_2.show();
  strip_3.show();
  strip_4.show();  

 void setColors( uint32_t newColors);  
}
uint32_t colors[NUM_LED_STRIPS][NUM_PIXELS];  //initiate 2D array of colors
uint32_t temp[NUM_LED_STRIPS][NUM_PIXELS];  //initiate 2D array of colors


void loop() {
  rain();
}

void rain() {
  int j, raindropSize = 8;
   
    int y0 = random(NUM_PIXELS), y1 = random(NUM_PIXELS), y2 = random(NUM_PIXELS), y3 = random(NUM_PIXELS), y4 = random(NUM_PIXELS);
       for (int k=0; k<raindropSize+raindropSize; k++) {
        
         for (j=0; j<NUM_PIXELS; j++) {  
            //for first LED strip
            if((j>=(y0-k)) && (j<=(y0+k))) {
              if (k<raindropSize) {colors[0][NUM_PIXELS-(y0+k)] = s.Color(((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255);}
              else
              colors[0][NUM_PIXELS-(y0+k-raindropSize+2)] = s.Color(0,0,0);
            }
            else 
              colors[0][NUM_PIXELS-j] = s.Color(0,0,0);
            
            //2nd LED strip
            if((j>=(y1-k)) && (j<=(y1+k))) {
              if (k<raindropSize) {colors[1][NUM_PIXELS-(y1+k)] = s.Color(((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255);}
              else
              colors[1][NUM_PIXELS-(y1+k-raindropSize+2)] = s.Color(0,0,0);
            }
            else 
              colors[1][NUM_PIXELS-j] = s.Color(0,0,0);
            
            //3rd LED strip
            if((j>=(y2-k)) && (j<=(y2+k))) {
              if (k<raindropSize) {colors[2][NUM_PIXELS-(y2+k)] = s.Color(((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255);}
              else
              colors[2][NUM_PIXELS-(y2+k-raindropSize+2)] = s.Color(0,0,0);
            }
            else 
              colors[2][NUM_PIXELS-j] = s.Color(0,0,0);

            //4th LED strip
            if((j>=(y3-k)) && (j<=(y3+k))) {
              if (k<raindropSize) {colors[3][NUM_PIXELS-(y3+k)] = s.Color(((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255);}
              else
              colors[3][NUM_PIXELS-(y3+k-raindropSize+2)] = s.Color(0,0,0);
            }
            else 
              colors[3][NUM_PIXELS-j] = s.Color(0,0,0);

            //5th LED strip
            if((j>=(y4-k)) && (j<=(y4+k))) {
              if (k<raindropSize) {colors[4][NUM_PIXELS-(y4+k)] = s.Color(((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255,((255/raindropSize)*(k/2))%255);}
              else
              colors[4][NUM_PIXELS-(y4+k-raindropSize+2)] = s.Color(0,0,0);
            }
            else 
              colors[4][NUM_PIXELS-j] = s.Color(0,0,0);   
         }
         setColors(colors);
       }
  
   
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// This is the beginning of the functions which set the LED lights.
// saves current state of LED lights into an array.
void saveCurrentState(uint32_t currColors[][30], uint32_t newColors[][30]) {
  for (int i=0; i<NUM_LED_STRIPS;  i++) {
    for (int j=0; j<NUM_PIXELS; j++) {
      newColors[i][j] = currColors[i][j];
    }
  }
}

// setColors() physically sets the LED light of each pixel and shows it.
void setColors(uint32_t newColors[][30]) {
  for (int i=0; i<NUM_LED_STRIPS;  i++) {
    for (int j=0; j<NUM_PIXELS; j++) {
      setLED(i, j, newColors[i][j]);
    }
  }
  strip_0.show();
  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();
  
/* //add for the other 5 LED strips
  strip_5.show();
  strip_6.show();
  strip_7.show();
  strip_8.show();
  strip_9.show();
*/  
  delay(WAIT);
}


// this sets the pixel color at a certain node
void setLED(int row, int light, uint32_t c) {
  switch (row) {
    case 0:
      strip_0.setPixelColor(light, c);
      break;
    case 1:
      strip_1.setPixelColor(light, c);
      break;
    case 2:
      strip_2.setPixelColor(light, c);
      break;
    case 3:
      strip_3.setPixelColor(light, c);
      break;
    case 4:
      strip_4.setPixelColor(light, c);
      break;
/* //this is for all 10 lights 
    case 5:
      strip_5.setPixelColor(light, c);
      break;
    case 6:
      strip_6.setPixelColor(light, c);
      break;
    case 7:
      strip_7.setPixelColor(light, c);
      break;
    case 8:
      strip_8.setPixelColor(light, c);
      break;
    case 9:
      strip_9.setPixelColor(light, c);
      break;
*/    
  }
}


