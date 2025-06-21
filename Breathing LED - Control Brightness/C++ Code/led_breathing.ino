// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// Define the PWM pin connected to the LED
int LEDpin = 11;
void setup()
{
  // Set the pin as an output
  pinMode(LEDpin, OUTPUT);
}
void loop() 
{
  // Fade in (brightness from 0 to 255)
  for (int a = 0; a <= 255; a++) {
    analogWrite(LEDpin, a);
    delay(20); // Wait for 20ms to see the dimming effect
  }
  // Fade out (brightness from 255 to 0)
  for (int a = 255; a >= 0; a--) {
    analogWrite(LEDpin, a);
    delay(20); // Wait for 20ms to see the dimming effect
  }
  // A short pause at the end of the cycle
  delay(200);
}
