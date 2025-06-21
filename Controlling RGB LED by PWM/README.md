# 💡 Arduino RGB LED Controller using PWM

This project demonstrates how to control the color of an RGB LED using Pulse Width Modulation (PWM) on an Arduino Uno. The LED cycles through a predefined set of colors: Red, Green, Blue, White, and Off.

## 🛠️ Required Components

*   1 x Arduino Uno
*   1 x Common Cathode RGB LED
*   3 x 220Ω Resistors
*   Jumper Wires
*   1 x Breadboard

## ⚙️ How It Works

### 🔌 Circuit Setup

The setup is straightforward. The RGB LED has four pins: one for each color (Red, Green, Blue) and one common pin. In this project, we use a **common cathode** LED, where the common pin is connected to the ground (GND).

1.  **Identify the LED pins:** The longest pin is usually the common pin (cathode in this case). The other three pins correspond to Red, Green, and Blue.
2.  **Connect the Common Pin:** Connect the longest pin (cathode) of the RGB LED to the `GND` pin on the Arduino.
3.  **Connect the Color Pins:**
    *   Connect the **Red** pin of the LED to a 220Ω resistor. Connect the other end of the resistor to Arduino's digital pin **~11**.
    *   Connect the **Green** pin of the LED to a 220Ω resistor. Connect the other end of the resistor to Arduino's digital pin **~9**.
    *   Connect the **Blue** pin of the LED to a 220Ω resistor. Connect the other end of the resistor to Arduino's digital pin **~10**.

*(Note: Pins 9, 10, and 11 are used because they support PWM, indicated by the `~` symbol on the Arduino board.)*

### 💻 Program Logic

The program logic is simple and based on a custom function to set the color.

*   **`setup()`**: This function runs once at the beginning. It configures pins 9, 10, and 11 as `OUTPUT` pins.
*   **`loop()`**: This function runs continuously. It calls the `color()` function with different RGB values to display Red, Green, Blue, and White, with a 500ms `delay()` between each color change. It also turns the LED off for 500ms.
*   **`color(R, G, B)`**: This is a helper function that takes three values (from 0 to 255) for Red, Green, and Blue. It uses `analogWrite()` to send a PWM signal to each corresponding LED pin. A value of `255` represents full brightness, while `0` means the LED is off for that color.

## 🧑‍💻 Arduino Code

Here is the complete code to upload to your Arduino Uno.

```cpp
// Define the pins for the RGB LED
int RedPin = 11;
int BluePin = 10;
int GreenPin = 9;

// setup() function runs once when you press reset or power the board
void setup()
{
  // Sets the digital pins as output
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

// loop() function runs over and over again forever
void loop()
{
  // Set color to Red
  color(255, 0, 0);
  delay(500);

  // Set color to Green
  color(0, 255, 0);
  delay(500);

  // Set color to Blue
  color(0, 0, 255);
  delay(500);

  // Set color to White
  color(255, 255, 255);
  delay(500);

  // Turn the LED off
  color(0, 0, 0);
  delay(500);
}

// Custom function to set the LED color
void color(unsigned char Red, unsigned char Green, unsigned char Blue)
{
```
## ✨ Applications

This basic project is the foundation for many creative applications, such as:

*   **Status Indicators:** Use different colors to show the status of a device (e.g., Green for 'Connected', Red for 'Error', Blue for 'Processing').
*   **Ambient Lighting:** Create a mood lamp that slowly fades between different colors.
*   **Visual Feedback:** Change the LED color based on sensor readings, like temperature or humidity.
*   **Decorative Effects:** Fun lighting for models, PC cases, or holiday decorations.
  // Use analogWrite to set the brightness of each color component
  // A value of 255 is full brightness, 0 is off.
  analogWrite(RedPin, Red);
  analogWrite(GreenPin, Green);
  analogWrite(BluePin, Blue);
}
