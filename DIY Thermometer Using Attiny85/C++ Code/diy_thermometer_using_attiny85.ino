// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// C++ code
// Define pin numbers for clarity
int ledPin = 0;      // Physical Pin 5 (PB0)
#define sensorPin A1 // Physical Pin 7 (PB2)

double fahrenheit;

void setup()
{
  pinMode(ledPin, OUTPUT);
  fahrenheit = 0.0;
}

void loop()
{
  // Read the raw analog value from the sensor
  int sensorValue = analogRead(sensorPin);

  // Convert the analog reading (0-1023) to a voltage (0-5V)
  double voltage = (double)sensorValue / 1024.0;
  voltage *= 5.0;

  // Convert voltage to temperature in Celsius
  // (assumes a sensor like TMP36 with 10mV per degree C and 500mV offset)
  double celsius = (voltage - 0.5) * 100;

  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  // Check the temperature range and blink the LED accordingly
  if (fahrenheit >= -40 && fahrenheit <= 68)
  {
    // Fast blink for cold temperatures
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  else if (fahrenheit >= 70 && fahrenheit <= 116)
  {
    // Medium blink for moderate temperatures
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (fahrenheit >= 123 && fahrenheit <= 238)
  {
    // Slow blink for hot temperatures
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else
  {
    // Solid ON for out-of-range temperatures
    digitalWrite(ledPin, HIGH);
  }
}
