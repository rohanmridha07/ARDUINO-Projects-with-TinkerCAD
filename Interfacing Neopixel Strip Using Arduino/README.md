# 💡 Interfacing Neopixel Strip with Arduino

A simple project demonstrating how to control a WS2812B (Neopixel) LED strip using an Arduino Uno. This code creates a colorful "chase" effect, cycling through red, green, and blue.

## 🛠️ Required Components

*   **Arduino Uno:** The microcontroller to run the code.
*   **Neopixel Strip (WS2812B):** This project uses a 4-LED strip.
*   **Jumper Wires:** To connect the components.
*   **Breadboard (Optional):** Makes connections easier.
*   **(Recommended) 1000µF Capacitor:** To place across the power and ground lines to smooth out the power supply.
*   **(Recommended) 300-500 Ohm Resistor:** To place on the data line to protect the first Neopixel.

## ⚙️ How It Works

### 🔌 Circuit Setup

1.  Connect the **5V** pin on the Arduino to the **5V** or **VCC** pin on the Neopixel strip.
2.  Connect the **GND** pin on the Arduino to the **GND** pin on the Neopixel strip.
3.  Connect the **Digital Pin 6** on the Arduino to the **Data In (DI or DIN)** pin on the Neopixel strip.
    *   *Best Practice:* Place the 300-500 Ohm resistor between the Arduino's Pin 6 and the strip's Data In pin.

<!-- You can add an image of your circuit here -->
<!-- ![Circuit Diagram](path/to/your/circuit_diagram.png) -->
*A diagram showing the connection between the Arduino Uno and the Neopixel strip. Remember to place the capacitor across 5V and GND near the strip for best results.*

### 🧠 Program Logic

*   **Include Library:** The `Adafruit_NeoPixel.h` library is included to simplify communication with the LEDs.
*   **Initialization:** In `setup()`, we initialize the Neopixel strip object, specifying the number of LEDs (4) and the Arduino pin (6) it's connected to. `strip.begin()` prepares the pin for output and `strip.show()` clears the strip, ensuring all LEDs are off at the start.
*   **Main Loop:** The `loop()` function continuously calls the `chase()` function with three different colors: red, green, and blue.
*   **Chase Effect:** The `chase()` function creates the animation. It iterates through each pixel, lighting it up with the specified color (`c`) and then turning off the pixel that is 4 positions behind it. This creates the illusion of a single light "chasing" its way down the strip. The `delay(25)` controls the speed of the chase.

## 💻 Code

Here is the complete Arduino sketch for this project. You will need to install the **Adafruit NeoPixel** library from the Arduino IDE's Library Manager.

```cpp
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 4

// Initialize the Neopixel strip object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Function prototype for the chase effect
static void chase(uint32_t c);

void setup()
{
  strip.begin();           // Prepare the data pin for output
  strip.show();            // Initialize all LEDs to 'off'
}

void loop()
{
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

// Creates a chasing light effect
static void chase(uint32_t c)
{
  // The loop runs longer than the number of pixels
  // to make the chase "run off" the end of the strip.
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++)
  {
    strip.setPixelColor(i, c);         // Turn on the current LED
    strip.setPixelColor(i - 4, 0);     // Turn off the trailing LED
    strip.show();                      // Update the strip to show changes
    delay(25);                         // A short pause to control the speed
  }
}
```
## 💡 Applications

Addressable LEDs like Neopixels can be used in a wide variety of fun and practical projects, including:

*   **🖥️ PC Case and Desk Lighting:** Create custom ambient lighting for your gaming or work setup.
*   **🚦 Status Indicators:** Use different colors to indicate build status, new notifications, or sensor readings.
*   **🎭 Wearable Tech & Cosplay:** Integrate dynamic lighting into costumes and props.
*   **✨ Holiday Decorations:** Animate Christmas lights or create spooky Halloween effects.
*   **📊 Data Visualization:** Represent data physically with light and color.
