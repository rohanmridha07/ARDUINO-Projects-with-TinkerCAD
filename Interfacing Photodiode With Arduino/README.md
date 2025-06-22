# Interfacing a Photodiode with Arduino Uno

A simple project to demonstrate how to measure ambient light intensity using a photodiode and an Arduino Uno. The raw analog values are read from the sensor and printed to the Serial Monitor.

## 💡 Introduction

This project is a great entry point for understanding how analog sensors work. A photodiode is a semiconductor device that converts light into an electrical current. By using it in a simple voltage divider circuit, we can measure the changes in voltage with an Arduino's analog pin to determine the intensity of the light hitting the sensor.

## 📋 Required Components

*   🤖 Arduino Uno
*   💡 Photodiode
*   🔌 220 Ohm Resistor
*   🍞 Breadboard
*   🔗 Jumper Wires

## ⚙️ How It Works

The project works by creating a simple circuit and running a small program on the Arduino.

### Circuit Setup 🔌

The circuit is set up as a **voltage divider**. The photodiode and the resistor are connected in series between the Arduino's 5V and GND pins. The point between them is connected to an analog input pin (`A0`).

1.  Connect the **Anode** (longer leg) of the photodiode to the Arduino's **5V** pin.
2.  Connect the **Cathode** (shorter leg) of the photodiode to the Arduino's **A0** (Analog In) pin.
3.  Connect the 220Ω resistor from the **A0** pin to the Arduino's **GND** pin.

When more light hits the photodiode, its resistance decreases. This causes the voltage at the `A0` pin to increase. Conversely, in the dark, the photodiode's resistance is very high, causing the voltage at `A0` to drop towards 0V. The Arduino reads this changing voltage.

### Program Logic 🧠

The Arduino code is straightforward. In the `setup()` function, we initialize the Serial communication to display the sensor values. In the `loop()` function, the Arduino continuously reads the analog voltage from pin `A0` using the `analogRead()` function. This function returns a value between 0 (for 0 volts) and 1023 (for 5 volts), which is then printed to the Serial Monitor.

## 💻 Brief Program Logic

*   The Arduino continuously reads the voltage level from the analog pin `A0`.
*   This raw analog value (from 0 to 1023) is directly proportional to the light intensity.
*   The value is then printed to the Serial Monitor, allowing you to see the light level changes in real-time.

## 📄 Code

Here is the complete Arduino sketch for this project.

```cpp
// C++ code
int sensorPin = A0;
int sensorValue = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
}
```
## 🌟 Applications

A simple light sensor like this can be the foundation for many interesting projects, including:

*   ☀️ **Day/Night Detectors:** Automatically turn on lights when it gets dark.
*   💡 **Automatic Lighting Systems:** Adjust indoor lighting based on ambient sunlight.
*   🤖 **Line Following Robots:** Detect a dark line on a light surface (or vice versa).
*   🚨 **Light-based Alarm Systems:** Trigger an alarm if a light beam is broken.
*   🌱 **Ambient Light Measurement:** Monitor light levels for plants or photography setups.
