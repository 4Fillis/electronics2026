//add temt, bmp, tft, moisture sensor (x2), and ds3231 libraries

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
