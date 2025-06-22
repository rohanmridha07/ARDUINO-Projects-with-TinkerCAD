# 💡 Arduino Dimmer Bulb

This is a simple and fun Arduino project that allows you to control the brightness of a bulb (or an LED) using a potentiometer. By turning the knob of the potentiometer, you can smoothly increase or decrease the light intensity. It's a great introduction to analog inputs and Pulse Width Modulation (PWM) outputs on the Arduino.

## ⚙️ Required Components
*   Arduino Uno
*   A Bulb (or an LED)
*   1k Ohm Resistor (especially important if using an LED)
*   250k Ohm Potentiometer
*   Breadboard
*   Jumper Wires

## 🧠 How it Works
The project works by reading an analog value from the potentiometer and mapping it to a PWM signal to control the bulb's brightness.

### 🔌 Circuit Setup
1.  **Potentiometer:**
    *   Connect the middle pin to the Arduino's `A0` analog pin.
    *   Connect one of the outer pins to `5V` on the Arduino.
    *   Connect the other outer pin to `GND` (Ground).
2.  **Bulb (LED):**
    *   Connect the positive leg (anode) of the bulb/LED to the Arduino's digital PWM pin `9` (marked with a `~`).
    *   Connect the negative leg (cathode) to one end of the 1k Ohm resistor.
    *   Connect the other end of the resistor to `GND`.

### 💻 Program Logic
*   The Arduino continuously reads the analog voltage from the potentiometer's middle pin. This gives a value from `0` (when turned fully to GND) to `1023` (when turned fully to 5V).
*   This input value (`0-1023`) is then mapped or scaled to a PWM-compatible range of `0-255`.
*   The `analogWrite()` function sends this `0-255` value to the bulb pin. A value of `0` means the bulb is completely off, and `255` means it's at full brightness.
*   The result is a smooth dimming effect as you turn the potentiometer knob.

## 👨‍💻 Code
Here is the complete Arduino sketch for the project.

```cpp
// C++ code
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
```
## 🚀 Applications
This simple circuit is a fundamental building block for many projects, including:
*   **Mood Lighting:** Creating ambient light for your room.
*   **Controlling Fan Speed:** With the addition of a motor and a transistor, you can control the speed of a small fan.
*   **User Input:** Using the potentiometer as a simple dial to set a value in a larger project (e.g., setting a timer, adjusting volume).
*   **Art Installations:** Creating interactive light-based art pieces.
