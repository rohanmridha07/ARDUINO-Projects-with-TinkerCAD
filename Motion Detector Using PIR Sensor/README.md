# Arduino PIR Motion Detector 🚶‍♂️💡

A simple and fun project to build a motion detector using an Arduino Uno and a PIR (Passive Infrared) sensor. When motion is detected, an LED lights up as a visual indicator. This project is great for beginners looking to get started with sensors and Arduino.

## ⚙️ Required Components
*   Arduino Uno
*   PIR Sensor (HC-SR501 or similar)
*   LED (any color)
*   1kΩ Resistor
*   Jumper Wires
*   Breadboard

## 🛠️ How It Works

### 🔌 Circuit Setup
1.  **PIR Sensor:**
    *   Connect the `VCC` pin to the `5V` pin on the Arduino.
    *   Connect the `GND` pin to the `GND` pin on the Arduino.
    *   Connect the `OUT` pin to digital pin `13` on the Arduino.
2.  **LED:**
    *   Connect the LED's positive leg (anode, longer leg) to one end of the 1kΩ resistor.
    *   Connect the other end of the resistor to digital pin `7` on the Arduino.
    *   Connect the LED's negative leg (cathode, shorter leg) to the `GND` pin on the Arduino.

### 💻 Program Logic
The Arduino program is straightforward:
-   **`setup()`**: Initializes the serial monitor for debugging and sets the PIR pin as an `INPUT` and the LED pin as an `OUTPUT`.
-   **`loop()`**: Continuously reads the digital signal from the PIR sensor.
    -   If the signal is `HIGH` (motion detected), it turns the LED on and prints "Motion Detected" to the serial monitor.
    -   If the signal is `LOW` (no motion), it turns the LED off and prints "No Motion Detected".

## 👨‍💻 Code
Here is the complete Arduino sketch for the project. Upload this code to your Arduino Uno.

```cpp
// C++ code
//
int pir = 13;
int led = 7;
bool pir_value = false;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
 
}

void loop()
{
  pir_value = digitalRead(pir);
  
  if (pir_value == HIGH)
  {
    Serial.println("Motion Detected");
    digitalWrite(led, HIGH);
  }
  
  else
  {
    Serial.println("No Motion Detected");
    digitalWrite(led, LOW);
  }
  
}
```
## ✨ Applications
This simple motion detector can be the foundation for many cool projects, such as:
*   **Home Security System:** Trigger an alarm or send a notification when an intruder is detected.
*   **Automatic Lighting:** Automatically turn on lights in a room, hallway, or staircase when someone enters.
*   **Visitor Counter:** Keep track of how many people enter a room or building.
*   **Energy Saving:** Turn off appliances or lights in a room when it's unoccupied.
*   **Interactive Art:** Create installations that react to the presence of people.
