### 💡 Arduino Uno LED Blink

A foundational "Hello, world!" project for physical computing. This program demonstrates how to control a Light Emitting Diode (LED) by blinking it on and off using an Arduino Uno.

### 🛠️ Required Components

*   1 x Arduino Uno
*   1 x LED (any color)
*   1 x 1kΩ Resistor
*   Jumper Wires
*   Breadboard (optional, but recommended for a clean setup)

### ⚙️ How It Works

#### 🔌 Circuit Setup

The circuit is designed to safely power an LED using a digital output pin on the Arduino. A resistor is crucial for limiting the current that flows through the LED, protecting it from burning out.

1.  Connect the **Anode** (long leg) of the LED to one end of the 1kΩ resistor.
2.  Connect the other end of the resistor to **Digital Pin 13** on the Arduino Uno.
3.  Connect the **Cathode** (short leg) of the LED to the **GND** (Ground) pin on the Arduino.

#### 💻 Program Logic

The code uses two main functions: `setup()` and `loop()`. The `setup()` function runs once to configure pin 13 as an output. The `loop()` function then runs continuously, repeatedly turning the LED on (`HIGH`), pausing for 500ms, turning it off (`LOW`), and pausing again. This sequence creates the steady blinking effect.

```

int LED = 13;
void setup()
{
 pinMode(LED, OUTPUT);
}
void loop()
{
digitalWrite(LED, HIGH); // Turn the LED on (HIGH is the voltage level)
delay(500); // Wait for 500 milliseconds
digitalWrite(LED, LOW); // Turn the LED off by making the voltage LOW
delay(500); // Wait for 500 milliseconds
}

```

### ✨ Applications

While simple, this project is the basis for many real-world applications, including:

*   **Visual Indicators:** Used as a status light to indicate power, a completed task, or an error state.
*   **Debugging Tool:** Programmers often blink an LED to visually confirm that a specific section of code is being executed.
*   **Learning Foundation:** Teaches the fundamental concepts of digital output, program loops, and basic circuit design.
*   **Simple Signaling:** Can be adapted to create signals, like a Morse code transmitter or a simple warning light.
