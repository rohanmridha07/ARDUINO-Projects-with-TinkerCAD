# Arduino - Controlling Multiple LEDs 🚦

A simple Arduino project to control six LEDs (acting as three pairs) using a potentiometer. This project is a great introduction to using `analogRead()` and conditional logic (`if-else`) to create interactive outputs.


*(Image: Example of multiple LEDs being controlled)*

## 🧱 Required Components

*   1 x Arduino Uno
*   1 x Breadboard
*   6 x LEDs (2 Red, 2 Yellow, 2 Green)
*   6 x 220Ω Resistors
*   1 x Potentiometer (10kΩ is a good value)
*   Jumper Wires

## ⚙️ How It Works

### 🔌 Circuit Setup

1.  **Potentiometer:** Connect the outer two pins of the potentiometer to the `5V` and `GND` pins on the Arduino. Connect the middle pin to analog pin `A5`.
2.  **LEDs:**
    *   Connect the long leg (anode) of each LED to its respective digital pin through a 220Ω resistor.
    *   Connect the short leg (cathode) of all six LEDs to a common `GND` pin on the Arduino.

**Pinout:**
*   **Red LEDs:** Pins `13` & `12`
*   **Yellow LEDs:** Pins `11` & `10`
*   **Green LEDs:** Pins `9` & `8`

### 🧠 Program Logic

The program works on a simple principle: reading an analog value and acting on it.

1.  **Read Value:** In the `loop()`, the Arduino continuously reads the analog voltage from the potentiometer using `analogRead(pot)`. This gives a value between `0` and `1023`.
2.  **Conditional Checks:** The program then uses a series of `if-else if` statements to check the value:
    *   If the value is `0`, the first pair of LEDs (Red) is turned off.
    *   If the value is between `1` and `250`, the Red LEDs are turned on.
    *   If the value is between `251` and `500`, the Yellow LEDs are turned on.
    *   If the value is greater than `500`, the Green LEDs are turned on.
3.  **Output:** Based on which condition is true, the `digitalWrite()` function sets the corresponding LED pins to `HIGH` (on) or `LOW` (off).

## 💻 Code

Here is the complete Arduino sketch for this project.

```cpp
// Define the analog pin for the potentiometer
int pot = A5;

// Variable to store the potentiometer value
int val = 0;

// Define digital pins for the LEDs
int led1 = 13; // Red 1
int led2 = 12; // Red 2
int led3 = 11; // Yellow 1
int led4 = 10; // Yellow 2
int led5 = 9;  // Green 1
int led6 = 8;  // Green 2

void setup()
{
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Set all LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  // Set the potentiometer pin as INPUT
  pinMode(pot, INPUT);
}

void loop() 
{
  // Read the analog value from the potentiometer (0-1023)
  val = analogRead(pot);
  
  // Print the value to the Serial Monitor to see what's happening
  Serial.println(val);
  
  // Check the value and control the LEDs accordingly
  if(val==0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else if(val > 0 && val <= 250)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val > 250 && val <= 500)
  {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);  
  }
  else if(val > 500)
  {
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
}
```
## 🚀 Applications

This simple circuit can be a base for many interesting projects, such as:

*   **Visual Level Indicator:** Replace the potentiometer with a sensor (like a photoresistor or a temperature sensor) to create a visual gauge for light or heat.
*   **Status Display:** Use the LEDs to show the status of a process (e.g., Off -> Initializing -> Running -> Complete).
*   **Simple Game Controller:** The potentiometer could be used to control an element in a simple game where the LEDs provide feedback.
*   **Educational Tool:** An excellent hands-on example for teaching beginners about analog inputs, mapping values, and using conditional logic in programming.
*   **Traffic Light Simulation:** With a slight change in the code to use `delay()` instead of a potentiometer, this setup is perfect for simulating a traffic light sequence.
