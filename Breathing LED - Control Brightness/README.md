# Breathing LED - Control Brightness 💡

A simple Arduino project to create a "breathing" effect with an LED, where its brightness gently fades in and out. This is a great beginner project to understand PWM (Pulse Width Modulation).

---

## 🛠️ Required Components

*   [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3)
*   1 x LED (any color)
*   1 x 220Ω Resistor
*   Breadboard
*   Jumper Wires

---

## ⚙️ How It Works

This project controls the brightness of an LED to simulate a rhythmic breathing pattern.

### 🔌 Circuit Setup

1.  Connect the Arduino's `GND` pin to the negative rail of the breadboard.
2.  Connect the LED's shorter leg (cathode) to the same negative rail.
3.  Connect the LED's longer leg (anode) to one end of the 220Ω resistor.
4.  Connect the other end of the resistor to the Arduino's digital PWM pin `~11`.

*(Note: PWM pins on the Arduino Uno are marked with a tilde `~` symbol. These are pins 3, 5, 6, 9, 10, and 11.)*

### 🧠 Program Logic

The program uses **Pulse Width Modulation (PWM)** to control the LED's brightness.

*   The `analogWrite()` function sends a PWM signal to the LED pin. This function can accept a value from `0` (0% duty cycle, LED is off) to `255` (100% duty cycle, LED is at full brightness).
*   The first `for` loop gradually increases the brightness value from `0` to `255`, making the LED fade in.
*   The second `for` loop gradually decreases the value from `255` to `0`, making the LED fade out.
*   The small `delay()` inside the loops creates a smooth transition, and the final `delay()` adds a pause before the cycle repeats, completing the "breathing" effect.

---

## 💻 Code

Here is the complete Arduino sketch for the project.

```cpp
// C++ code
//
int LEDpin = 11;

void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  // Fade in from 0 to 255
  for (int a = 0; a <= 255; a++) {
    analogWrite(LEDpin, a);
    delay(20);
  }

  // Fade out from 255 to 0
  for (int a = 255; a >= 0; a--) {
    analogWrite(LEDpin, a);
    delay(20);
  }

  // A short pause before repeating
  delay(200);
}
```
### ✨ Applications
* Status Indicators: Simulating a "sleep" or "standby" mode on electronic devices.
* Decorative Lighting: Creating ambient mood lamps or holiday decorations.
* Visual Feedback: The brightness level could represent a sensor reading (e.g., getting brighter as temperature rises).
* Art Installations: Adding dynamic lighting to sculptures or interactive art.
