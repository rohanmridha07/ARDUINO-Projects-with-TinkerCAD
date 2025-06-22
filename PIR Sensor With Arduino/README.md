# PIR Motion Sensor with Arduino 🚶‍♂️💡

This is a simple and fun beginner project that demonstrates how to use a Passive Infrared (PIR) sensor with an Arduino Uno. When the sensor detects motion, it triggers an LED to light up and sends a status update to the Serial Monitor.

## 👋 Introduction

A PIR sensor is an electronic sensor that measures infrared (IR) light radiating from objects in its field of view. They are most often used in PIR-based motion detectors. This project is a basic implementation of a motion-activated switch, perfect for understanding digital inputs and sensor calibration.

## 🛠️ Required Components

*   🤖 Arduino Uno
*   🔥 PIR Sensor (HC-SR501 or similar)
*   💡 LED (any color)
*    resistor 220-ohm Resistor
*   🍞 Breadboard
*   🔗 Jumper Wires

## ⚙️ How It Works

### 🔌 Circuit Setup

1.  **PIR Sensor Connection:**
    *   Connect the `VCC` pin of the PIR sensor to the `5V` pin on the Arduino.
    *   Connect the `GND` pin to the `GND` pin on the Arduino.
    *   Connect the `OUT` (output) pin to **Digital Pin 13** on the Arduino.

2.  **LED Connection:**
    *   Connect the longer leg (anode) of the LED to one end of the 220-ohm resistor.
    *   Connect the other end of the resistor to **Digital Pin 12** on the Arduino.
    *   Connect the shorter leg (cathode) of the LED to the `GND` pin on the Arduino.

### 🧠 Program Logic

*   **Calibration:** When the Arduino first powers on, the `setup()` function runs a 30-second calibration routine for the PIR sensor. This allows the sensor to get a stable reading of the ambient infrared energy in the room. You will see progress dots in the Serial Monitor during this time.
*   **Detection:** The `loop()` constantly checks the state of the PIR sensor's output pin.
*   **Action:** If motion is detected, the pin goes `HIGH`. The code then turns the LED on and prints a "Motion detected" message with a timestamp to the Serial Monitor.
*   **Reset:** When motion stops, the pin goes `LOW`, and the LED turns off. After a 5-second pause, the code prints a "Motion ended" message and resets, ready to detect the start of a new motion event. This prevents the serial monitor from being spammed with messages.

## 💻 Code

Here is the complete Arduino sketch for this project. Upload it to your Arduino Uno using the Arduino IDE.

```cpp
// C++ code
//
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirPin = 13;
int ledPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  // Give the sensor time to calibrate
  Serial.print("Calibrating Sensor ");
  for (int i = 0; i < calibrationTime; i++)
  {
    Serial.print(".");
    delay(1000);
  }
    Serial.println("\nDONE");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void loop()
{
  if (digitalRead(pirPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    if(lockLow)
    { 
     // A new motion event has been detected
     lockLow = false;
     Serial.println("---");
     Serial.print("Motion detected at ");
     Serial.print(millis()/1000);
     Serial.println(" sec");
     delay(50);
    }
    takeLowTime = true;
  }
  
  if (digitalRead(pirPin) == LOW)
  {
    digitalWrite(ledPin, LOW);
    if(takeLowTime)
    { 
      // Start the timer for the end of the motion
      lowIn = millis();
      takeLowTime = false;
    }
  }
    // If motion has stopped for the specified pause duration
    if(!lockLow && millis() - lowIn > pause)
    { 
     lockLow = true;
     Serial.print("Motion ended at ");
     Serial.print((millis() - pause) / 1000);
     Serial.println(" sec");
     Serial.println("---");
     delay(50);
    } 
}
```
## 🚀 Applications

This simple circuit is the foundation for many real-world applications, such as:

*   🏠 **Home Security Systems:** To detect intruders and trigger an alarm.
*   💡 **Automatic Lighting:** To turn on lights in a room when someone enters and turn them off when they leave, saving energy.
*   🚪 **Automatic Doors:** Used in stores and buildings to open doors when a person approaches.
*   📸 **Wildlife Cameras:** To trigger a camera to take a picture when an animal passes by.
*   🎨 **Interactive Art Installations:** To create art that responds to the presence of people.
