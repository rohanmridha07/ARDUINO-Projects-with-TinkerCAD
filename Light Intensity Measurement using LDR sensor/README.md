# ☀️ Light Intensity Measurement using LDR & Arduino

A simple Arduino project to measure ambient light intensity using a photoresistor (LDR). The brightness of an LED is controlled in real-time based on the amount of light the LDR detects.

---

### 📝 Introduction

This project demonstrates how a Light Dependent Resistor (LDR) works and how it can be interfaced with an Arduino. The LDR's resistance changes based on the light it's exposed to. We read this change as an analog voltage, which the Arduino then uses to control the brightness of an LED via Pulse Width Modulation (PWM). The raw sensor value is also printed to the Serial Monitor for observation.

### 🛠️ Required Components

*   Arduino UNO
*   1 x LED (any color)
*   1 x Photoresistor (LDR)
*   2 x 220Ω Resistors
*   1 x Breadboard
*   Jumper Wires
*   A Multimeter (optional, for testing)

### ⚙️ How It Works

#### 🔌 Circuit Setup

The core of this circuit is a **voltage divider** created by the LDR and a 220Ω resistor.

1.  **LDR Setup:**
    *   Connect one leg of the LDR to the **5V** pin on the Arduino.
    *   Connect the other leg of the LDR to the **A0** (Analog In) pin.
    *   From that same leg (connected to A0), connect a **220Ω resistor** to **GND**. This completes the voltage divider.

2.  **LED Setup:**
    *   Connect the **long leg (anode)** of the LED to one end of the second **220Ω resistor**.
    *   Connect the other end of that resistor to digital pin **~9** (a PWM pin) on the Arduino.
    *   Connect the **short leg (cathode)** of the LED to **GND**.

#### 🧠 Program Logic

The program logic is very straightforward:

1.  In `setup()`, we initialize Serial Communication to view the sensor values and set the LED pin as an `OUTPUT`.
2.  In `loop()`, the Arduino continuously:
    *   Reads the voltage from the LDR circuit using `analogRead(A0)`. This returns a value between 0 (low light) and 1023 (bright light).
    *   Prints this value to the Serial Monitor.
    *   Uses the `map()` function to scale the input range of the LDR (0-1023) to the output range of the LED's brightness (0-255).
    *   Sets the LED brightness using `analogWrite()`.
    *   Waits for a short moment before repeating.

### 💻 Code

Here is the complete Arduino code for the project.

```cpp
// C++ code
//
int sensorValue = 0 ;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(A0);
  Serial.println (sensorValue);
  analogWrite (9, map (sensorValue, 0, 1023, 0, 255));
  delay(100); 
}
```
### 💡 Applications

This simple light-sensing circuit is the foundation for many real-world applications, including:

*   **Automatic Streetlights:** Turning on lights when it gets dark.
*   **Automatic Display Brightness:** Adjusting phone or laptop screen brightness.
*   **Light-activated Alarms:** Triggering an alarm when a light beam is broken.
*   **Robotics:** Helping a robot follow a line or avoid dark areas.
*   **Photography:** As a basic light meter.
