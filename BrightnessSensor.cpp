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

    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();


    delay(300);
}