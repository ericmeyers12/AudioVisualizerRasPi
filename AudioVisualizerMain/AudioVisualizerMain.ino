#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_PIXELS 30
#define NUM_LED_STRIPS 5
#define WAIT 50
#define WAIT2 2
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
byte frequency[NUM_LED_STRIPS];
//uint32_t temp[NUM_LED_STRIPS][NUM_PIXELS];  //initiate 2D array of colors
int t,u;
void loop() { 
  for(int i=0; i<NUM_LED_STRIPS; i++) {
    frequency[i] = random(50,255);
  }
  colorSoundBar(frequency);
//   vRainbowCycle(); 
//   rainbowRow();
}

void colorSoundBar(byte freq[]) {
  uint16_t k=NUM_PIXELS/2, freqFactor=255/NUM_PIXELS;
  for(int i=0; i<NUM_LED_STRIPS; i++) {
    for(int j=0; j<NUM_PIXELS; j++) {
      if (j>(k-freq[i]/freqFactor/2)  && j<k) {colors[i][j] = BarColor(((k-j)-u));}
      else if (j>k && j<(k+freq[i]/freqFactor/2)) {colors[i][j] = BarColor(((j-k)-u));}
      else if (j==k) colors[i][j] = BarColor(-u); //define middle color here
      else colors[i][j] = s.Color(0,0,0);
      
    }
       
  }
  if(t%WAIT2==0) {u++;} //erase if color change not desired 
  t++;
  setColors(colors);

}

//Input WheelPos takes in 0-255 value
uint32_t BarColor(byte WheelPos) {
  WheelPos = WheelPos & NUM_PIXELS/2;
  if(WheelPos <= (NUM_PIXELS/6)) {
    return s.Color(255 - WheelPos * (255/(NUM_PIXELS/6)),0, 255);
  }
  if(WheelPos <= (NUM_PIXELS/3)) {
    WheelPos -= (NUM_PIXELS/6);
    return s.Color(0, WheelPos * (255/(NUM_PIXELS/6)), 255 - WheelPos * (255/(NUM_PIXELS/6)));
  }
  WheelPos -= (NUM_PIXELS/3);
  return s.Color(WheelPos * (255/(NUM_PIXELS/6)), 255 - WheelPos * (255/(NUM_PIXELS/6)), 0);
}



/*
void dRainbowCycle() { 
   for (int j=0; j<NUM_PIXELS; j++) {  
    for (int i=0; i<NUM_LED_STRIPS; i++){
     colors[i][j]=Wheel( (i+9*j) % 255);
     }
   }
   saveCurrentState(colors, temp);
  
}
*/

//__________VERTICAL_RAINBOW_CYCLE____________
//meshes a rainbow down each strip
void vRainbowCycle() { 
   for (int j=0; j<NUM_PIXELS; j++) {  
    for (int i=0; i<NUM_LED_STRIPS; i++){
     colors[i][j]=Wheel( (i+9*j) % 255);
     }
   }
   for(int n=0; n<30; n++) {
    for (int j=0; j<NUM_PIXELS; j++) {  
      for (int i=0; i<NUM_LED_STRIPS; i++) {
        int x;
        if(j==0) {x=29;}
        else {x=j-1;}
        colors[i][x]=colors[i][j];
      }
    }
    setColors(colors);
  }
}


//__________RAINBOW_ROW____________
//shoots a downward rainbow line
void rainbowRow() {
   for (int j=0; j<NUM_PIXELS; j++) {  
    for (int i=0; i<NUM_LED_STRIPS; i++){

//       colors[i][(j-2+30)%29]=colors[i][j];
      colors[i][j]=Wheel( (5*i+9*j) % 255);

       int x;
       if(j==0) {x=29;}
       else {x=j-1;}
        
       colors[i][x]=s.Color(0,0,0);       
    }
    setColors(colors);
   }
   
}




// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return s.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return s.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return s.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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


