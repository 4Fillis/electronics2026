//add temt, bmp, tft, moisture sensor (x2), and ds3231 libraries

//declare pins
const int flowsens = 26;
const int lvlsens = 33;
const int moissens = 32;
const int mospin = 23;
const int touch = 4;
const int lightsens = A0;

//add bmp280
//add tft
//add ds3231

void setup() {
  //set pin modes
  pinMode(flowsens, INPUT);
  pinMode(lvlsens, INPUT);
  pinMode(moissens, INPUT);
  pinMode(lightsens, INPUT);
  pinMode(touch, INPUT);
  pinMode(mospin, OUTPUT);

}

void loop() {
  //read brightness

  
  //read lvl
    //if under threshold: put fill_water to yes
  //read moisens
    //if < dry threshold:
      //if fill_water = yes:
    //else:
      //start flow sensor
      //set mospin high
      //while ticks < x amt:
        //continue
      //stop

  //
}
