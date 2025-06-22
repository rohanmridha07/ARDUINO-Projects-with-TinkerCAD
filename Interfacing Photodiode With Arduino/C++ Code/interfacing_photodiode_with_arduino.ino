// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// Define the analog pin connected to the photodiode
int sensorPin = A0;

// Variable to store the sensor's reading
int sensorValue = 0;

void setup()
{
  // Start serial communication at 9600 bps
  Serial.begin(9600);
  
  // No need to set pinMode for analog inputs, but it's good practice
  pinMode(sensorPin, INPUT);
}

void loop()
{
  // Read the analog value from the sensor
  sensorValue = analogRead(sensorPin);
  
  // Print the value to the Serial Monitor
  Serial.println(sensorValue);

  // A small delay can make the output more readable
  delay(100); 
}
