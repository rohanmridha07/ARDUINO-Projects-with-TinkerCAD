# LED Flowing Lights with Arduino 💡

A simple and fun beginner-friendly project to create a "flowing" or "chasing" light effect using an Arduino Uno and 8 LEDs. This project is a great introduction to basic electronics, digital outputs, and programming loops.


*(Image is a representative GIF of a similar project)*

## 🛠️ Required Components

*   1 x Arduino Uno
*   8 x LEDs (any color)
*   8 x 220 Ohm Resistors
*   1 x Breadboard
*   Jumper Wires

## ⚙️ How It Works

### 🔌 Circuit Setup

The circuit is straightforward. We connect each of the 8 LEDs to a separate digital pin on the Arduino, with a current-limiting resistor in series to protect both the LED and the Arduino.

1.  Place the 8 LEDs onto the breadboard, all facing the same direction.
2.  Connect the shorter leg (cathode) of each LED to the ground rail (GND) of the breadboard.
3.  Connect the longer leg (anode) of each LED to its own 220-ohm resistor.
4.  Connect the other end of each resistor to a digital pin on the Arduino. For this project, we use **digital pins 1 through 8**.
5.  Finally, connect the GND pin from the Arduino to the ground rail on the breadboard.

> **Note:** Pins 0 and 1 on the Arduino Uno are typically used for serial communication (RX/TX). While this code works, for more advanced projects, it's good practice to start using pins from 2 upwards to avoid conflicts.

### 👨‍💻 Program Logic

The logic is based on simple `for` loops.

*   **`setup()`**: A `for` loop runs once to initialize digital pins 1 through 8 as `OUTPUT` pins.
*   **`loop()`**:
    1.  The first `for` loop iterates from 1 to 8. In each step, it turns an LED `ON` (`HIGH`) and waits for 300 milliseconds. This creates the effect of the light "flowing" in one direction.
    2.  The second `for` loop does the same, but this time it turns each LED `OFF` (`LOW`), clearing the sequence and preparing it to start over.
    3.  This entire loop repeats forever, creating a continuous flowing light effect.

## 💻 Code

Here is the complete Arduino sketch for the project.

```cpp
// C++ code
//
unsigned char LED;
void setup() 
{
  // Loop to set pins 1 through 8 as outputs
  for (LED = 1; LED <= 8; LED++)
  {
    pinMode(LED, OUTPUT);
  }
}
void loop() {
  
  // Turn LEDs on one by one
  for (LED = 1; LED <= 8; LED++) {
    digitalWrite(LED, HIGH);
    delay(300);
  }
  
  // Turn LEDs off one by one
  for (LED = 1; LED <= 8; LED++) {
    digitalWrite(LED, LOW);
    delay(300);
  }
}
```
## ✨ Applications

This simple effect can be adapted for many creative uses, such as:

*   **Knight Rider / KITT Scanner:** A classic effect for model cars or displays.
*   **Decorative Lighting:** Holiday lights (Christmas, Diwali) or ambient mood lighting.
*   **PC Case Modding:** Add a dynamic flair to your computer case.
*   **Visual Indicators:** Use it as a simple loading bar or status indicator.
*   **Educational Tools:** A great visual aid for teaching basic programming concepts like loops.
