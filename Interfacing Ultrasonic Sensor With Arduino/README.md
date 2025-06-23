# Interfacing Ultrasonic Sensor with Arduino 📏

This project demonstrates a simple way to interface an HC-SR04 ultrasonic sensor with an Arduino Uno to measure distance. The measured distance is then displayed on the Arduino's Serial Monitor.

## 📖 Introduction

An ultrasonic sensor is a device that measures the distance to an object using ultrasonic sound waves. It works by sending out a sound wave at a specific frequency and listening for that sound wave to bounce back. By recording the time elapsed between the sound wave being generated and the sound wave bouncing back, it is possible to calculate the distance to an object.

## ⚙️ Required Components

*   Arduino Uno 💻
*   HC-SR04 Ultrasonic Sensor 🔊
*   Breadboard
*   Jumper Wires
*   Arduino IDE

## 🛠️ How It Works

### 🔌 Circuit Setup

The connection between the Arduino Uno and the HC-SR04 sensor is straightforward.

1.  Connect the **VCC** pin of the sensor to the **5V** pin on the Arduino.
2.  Connect the **GND** pin of the sensor to the **GND** pin on the Arduino.
3.  Connect the **Trig** (Trigger) pin of the sensor to **Digital Pin 11** on the Arduino.
4.  Connect the **Echo** pin of the sensor to **Digital Pin 10** on the Arduino.

![Circuit Diagram](https://www.electronicshub.org/wp-content/uploads/2021/06/Arduino-Ultrasonic-Sensor-Circuit-Diagram.jpg)
*(Image credit: Electronicshub.org)*

### 🧠 Program Logic

The program works in a sequence of steps to measure the distance:

1.  **Trigger Pulse:** The Arduino first sends a short 10-microsecond HIGH pulse to the `Trig` pin of the sensor. This tells the sensor to emit an ultrasonic burst.
2.  **Listen for Echo:** The Arduino then listens on the `Echo` pin. The `Echo` pin will go HIGH for the exact amount of time it takes for the sound wave to travel to an object and bounce back to the sensor.
3.  **Measure Time:** The `pulseIn()` function is used to measure the duration (in microseconds) for which the `Echo` pin remains HIGH.
4.  **Calculate Distance:** The measured time is converted into distance (in centimeters) using the formula:
    `Distance = (Time * Speed of Sound) / 2`
    The division by 2 is necessary because the time measured is for the round trip (to the object and back).

## 💻 Arduino Code

Upload the following code to your Arduino Uno using the Arduino IDE. Make sure to open the **Serial Monitor** (set to 9600 baud) to see the distance readings.

```cpp
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
```
## 🚀 Applications

This simple distance-measuring project can be the foundation for many other exciting applications, such as:

*   **Obstacle Avoiding Robots:** To detect and navigate around obstacles.
*   **Parking Assistant System:** To alert a driver about the distance to a wall or another car.
*   **Water Level Monitoring:** To measure the level of water in a tank.
*   **Security Systems:** To detect the presence of an intruder in a specific area.
*   **Digital Measuring Tape:** A simple handheld device to measure distances.
