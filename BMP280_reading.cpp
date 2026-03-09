/* This code is to use with Adafruit BMP280
 * It measures temperature, pressure, altitude and displays them on the Serial monitor
 * Modified version of the Adafruit example code
 Credit: https://projecthub.arduino.cc/SurtrTech/bmp280-measure-temperature-pressure-and-altitude-6002cd
*/

#include
  <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C Interface

void setup()
  {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if
  (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor,
  check wiring!"));
    while (1);
  }

  /* Default settings from datasheet.
  */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */

                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */

                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */

                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500);
  /* Standby time. */
}

void loop() {
    Serial.print(F("Temperature
  = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");


    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure()/100);
  //displaying the Pressure in hPa, you can change the unit
    Serial.println("
  hPa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1019.66));
  //"1019.66" is the standard pressure(hPa) at sea level (regional)
    Serial.println("m");  //If unknown: modify until current altitude is given

    Serial.println();
    delay(2000);
}
