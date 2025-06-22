# Interfacing a Servo Motor with Arduino Uno 🤖

A simple, beginner-friendly project demonstrating how to control the position of a standard servo motor using an Arduino Uno. This project sweeps the servo motor back and forth between 0 and 180 degrees.

## 📖 Introduction

Servo motors are essential components in robotics and automation projects. Unlike regular DC motors, they allow for precise control of angular position. This guide provides the basic circuit setup and code to get you started with controlling a servo motor.

## ⚙️ Required Components

*   1x Arduino Uno
*   1x Servo Motor (e.g., SG90)
*   Jumper Wires

## 🛠️ How It Works

### 🔌 Circuit Setup

Connecting the servo motor to the Arduino is straightforward. The servo has three wires:

*   **VCC (Red wire):** Connects to the `5V` pin on the Arduino.
*   **GND (Brown/Black wire):** Connects to the `GND` pin on the Arduino.
*   **Signal (Orange/Yellow wire):** Connects to a digital PWM pin on the Arduino. In this project, we use pin `7`.

### 🧠 Program Logic

The program logic is very simple:

1.  **Include Library:** The `Servo.h` library is included to provide functions for servo control.
2.  **Attach Servo:** In the `setup()` function, we create a `Servo` object and attach it to the digital pin it's connected to (Pin 7).
3.  **Sweep Motion:** The `loop()` function contains two `for` loops:
    *   The first loop gradually moves the servo from 0 to 180 degrees.
    *   After a short pause, the second loop moves the servo back from 180 to 0 degrees.
4.  **Repeat:** The `loop()` function runs continuously, causing the servo to sweep back and forth.

## 💻 Code

Here is the complete Arduino code for this project. Upload it to your Arduino Uno using the Arduino IDE.

```cpp
// C++ code for Arduino

// Include the servo library
#include <Servo.h>

// Create a servo object
Servo Myservo;

// Variable to store the servo position
int pos;

void setup()
{
  // Attach the servo on pin 7 to the servo object
  Myservo.attach(7);
}

void loop()
{
  // Sweep from 0 degrees to 180 degrees
  for (pos = 0; pos <= 180; pos++) {
    Myservo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(40);           // Wait 40ms for the servo to reach the position
  }

  delay(1000); // Wait for a second

  // Sweep from 180 degrees to 0 degrees
  for (pos = 180; pos >= 0; pos--) {
    Myservo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(40);           // Wait 40ms for the servo to reach the position
  }
  
  delay(3000); // Wait for three seconds
}
```
## 🚀 Applications

This basic principle can be extended to many real-world applications, such as:

*   **Robotic Arms:** Controlling the joints of a small robot arm.
*   **Home Automation:** Opening/closing blinds, locks, or vents.
*   **Camera Mounts:** Creating a pan-and-tilt system for a camera.
*   **Animatronics:** Moving parts on a model or character.
*   **Automated Systems:** Opening and closing a lid on a smart trash can.
