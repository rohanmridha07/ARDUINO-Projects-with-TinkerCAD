// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
int LedPin = 0;      // LED connected to physical pin 5 (PWM capable)
int Pot_Value = 0;   // Variable to store the value from the potentiometer
int SensorPin = A3;  // Potentiometer's middle pin connected to physical pin 2
void setup()
{
  // Set the LED pin as an output
  pinMode(LedPin, OUTPUT);
  // Set the potentiometer pin as an input
  pinMode(SensorPin, INPUT);
}
void loop()
{
  // Read the analog value from the potentiometer (0-1023)
  Pot_Value = analogRead(SensorPin);
  
  // Map the 10-bit analog value to an 8-bit PWM value (0-255)
  Pot_Value = map(Pot_Value, 0, 1023, 0, 255);
  
  // Write the PWM value to the LED to set its brightness
  analogWrite(LedPin, Pot_Value);
}
