//TEMT6000 Light Sensor reading
#define LIGHTSENSORPIN A0 //VP pin
void setup()
{
pinMode(LIGHTSENSORPIN, INPUT);
Serial.begin(115200);
}
void loop()
{
float reading = analogRead(LIGHTSENSORPIN); //Read light level
float square_ratio = reading / 1023.0; //Get percent of maximum value (1023)
square_ratio = pow(square_ratio, 2.0);
Serial.println(reading);
Serial.println(square_ratio);
delay(300);
}