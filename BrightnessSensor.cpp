//TEMT6000 Light Sensor reading
#define BRIGHTNESSSENSOR A0 //VP pin
void setup()
{
pinMode(BRIGHTNESSSENSOR, INPUT);
Serial.begin(115200);
}
void loop()
{
float reading = analogRead(BRIGHTNESSSENSOR); //Read light level
float square_ratio = reading / 1023.0; //Get percent of maximum value (1023)
square_ratio = pow(square_ratio, 2.0);
Serial.println(reading);
delay(300);
}