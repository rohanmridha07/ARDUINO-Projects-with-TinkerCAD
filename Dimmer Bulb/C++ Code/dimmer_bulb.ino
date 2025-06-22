// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
int potPin = A0;    // Potentiometer is connected to Analog Pin 0
int bulbPin = 9;    // Bulb/LED is connected to Digital PWM Pin 9

int readValue;      // Stores the value read from the potentiometer
int writeValue;     // Stores the value to write to the bulb

void setup()
{
  // Initialize the pins
  pinMode(potPin, INPUT);
  pinMode(bulbPin, OUTPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  // Read the analog value from the potentiometer (0 to 1023)
  readValue = analogRead(potPin);
  
  // Map the 0-1023 range to a 0-255 range for PWM
  writeValue = (255.0 / 1023.0) * readValue;
  
  // Write the mapped value to the bulb to set its brightness
  analogWrite(bulbPin, writeValue);
  
  // Print the current brightness value to the Serial Monitor
  Serial.print("You are writing a value of ");
  Serial.println(writeValue);
}
