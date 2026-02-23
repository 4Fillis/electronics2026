// Simple code for Measuring Voltage from
// Capacitive soil moisture sensor
//
int soil_pin = A0; // AOUT pin on sensor
void setup() {
Serial.begin(9600); // serial port setup
analogReference(EXTERNAL); // set the analog reference to
3.3V
}
void loop() {
Serial.print(&quot;Soil Moisture Sensor Voltage: &quot;);
Serial.print((float(analogRead(soil_pin))/1023.0)*3.3); //
read sensor
Serial.println(&quot; V&quot;);

delay(100); // slight delay between readings
}