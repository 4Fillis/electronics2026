//add temt, bmp, tft, moisture sensor (x2), and ds3231 libraries
//libraries
//tft 
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

//tft pins setting
#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS   15
  #define TFT_DC   27
  #define TFT_RST  26 //changed from 33

  #define TFT_MOSI 13   // HSPI MOSI
  #define TFT_SCLK 14   // HSPI SCLK


#elif defined(ESP8266)
  #define TFT_CS   15
  #define TFT_DC   27
  #define TFT_RST  26 //changed from 33

  #define TFT_MOSI 13   // HSPI MOSI
  #define TFT_SCLK 14   // HSPI SCLK


#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.

  #define TFT_CS   15
  #define TFT_DC   27
  #define TFT_RST  26 //changed from 33 Or set to -1 and connect to Arduino RESET pin

  #define TFT_MOSI 13   // HSPI MOSI
  #define TFT_SCLK 14   // HSPI SCLK

#endif
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);



//declare pins
const int flowsens = 26;
const int lvlsens = 33;
int wtrlvl = 0;
const int moissens = 32;
const int mospin = 23;
const int touch = 4;
int light_lvl;
int fill_water = 0;;
int soilmois;
float lightsens = 36;

//add bmp280
//add tft
//add ds3231

void setup() {
  //tft initialiser
  tft.init(240, 320);  // Init ST7789 320x240
  //set pin modes
  pinMode(flowsens, INPUT);
  pinMode(lvlsens, INPUT);
  pinMode(moissens, INPUT);
  pinMode(touch, INPUT);
  pinMode(mospin, OUTPUT);

  Serial.begin(115200); 

}

void loop() {
  //read brightness
  lightsens = analogRead(lightsens); //Read light level
  if (lightsens > 341) and (lightsens < 682){
    light_lvl = 2;}
  else if (lightsens > 341){
    light_lvl = ;1}
  else {
    light_lvl = 3;}
  Serial.print("light_reading: ");
  Serial.println(lightsens)
  Serial.print("light_lvl: ");
  Serial.println(light_lvl)

  //read water lvl
  lvlsens = analogRead(33);
  wtrlvl = (100-((lvlsense/4095.00)*100));
  Serial.print("wtrlvl: "); 
  Serial.println(wtrlvl); 

  //if under threshold: put fill_water to yes
  if (wtrlvl <= 25){
    fill_water = 1;
  }

  //read soil moisture and map it to how wet (%)
  soilmois = analogRead(moissens);
  soilpcent = map(soilmois, 1800, 2395, 100, 0);
  soilpcent = constrain(soilpcent, 0, 100);

  //refill plant water if too dry
  if (soilpcent <= 20){
    fill_pot = 1;
    //if the water level is too low to refill the pot
    if (wtrlvl < 10){
      //if user detected (ultrasonic)
      if (wtrlvl <10){
        //play music ("scream")
        }
      //send a phone alert to the user
      //do a thing with webhooks and auto send message in discord server
    }
    //refill pot
    //flow sensor for x amt of ticks
    ticks = 0;
    digitalWrite(mospin, HIGH);
    while (ticks < 1500){
      int ticks = analogRead(26);
      Serial.println(ticks);
      delay(100);
    }
    digitalWrite(mospin, LOW);
    
  }
  delay(200);
  
      
      //if < dry threshold:
      //if fill_thing = yes:
      //else:
      //start flow sensor
      //set mospin high
      //while ticks < x amt:
      //continue
      //stop

      //
}
