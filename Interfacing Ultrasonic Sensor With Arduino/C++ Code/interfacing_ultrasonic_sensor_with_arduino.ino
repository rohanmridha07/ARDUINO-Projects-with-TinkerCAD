// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// Define the trigger and echo pins
int trigPin = 11;
int echoPin = 10;

// Variables to store time and distance
long time;
int distance;

void setup() {
  // Set trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set echo pin as an INPUT
  pinMode(echoPin, INPUT);
  
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by sending a 10 microsecond high pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  time = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  // Speed of sound wave divided by 2 (go and back)
  // 340 m/s = 0.034 cm/µs
  distance = time * 0.034 / 2;
  
  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100); // Delay for better readability
}
