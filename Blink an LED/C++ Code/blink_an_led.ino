// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
int LED = 13;
void setup()
{
 pinMode(LED, OUTPUT);
}
void loop()
{
digitalWrite(LED, HIGH); // Turn the LED on (HIGH is the voltage level)
delay(500); // Wait for 500 milliseconds
digitalWrite(LED, LOW); // Turn the LED off by making the voltage LOW
delay(500); // Wait for 500 milliseconds
}
