# 🌡️ DIY Thermometer Using ATtiny85

A simple, low-cost DIY thermometer project using an ATtiny85 microcontroller. This project reads the ambient temperature from a sensor and indicates different temperature ranges by blinking an LED at various speeds. It's a great project for beginners looking to get started with microcontrollers and sensors.

## ⚙️ Required Components

*   **Microcontroller:** 1x ATtiny85
*   **Sensor:** 1x Analog Temperature Sensor (e.g., TMP36)
*   **LED:** 1x 5mm LED (any color)
*   **Resistor:** 1x 220Ω Resistor
*   **Hardware:** Breadboard and Jumper Wires
*   **Power:** 3V - 5V Power Source
*   **Programmer:** An Arduino Uno or a dedicated AVR programmer to upload the code.

## 🔧 How It Works

This project is built around the ATtiny85, which reads analog data from the temperature sensor and controls an LED to display the temperature range.

### 🔌 Circuit Setup

1.  **Power:** Connect the VCC and GND pins of the ATtiny85 to your 5V and GND rails, respectively.
2.  **Temperature Sensor:**
    *   Connect the VCC pin of the sensor to 5V.
    *   Connect the GND pin of the sensor to GND.
    *   Connect the Vout (Output) pin of the sensor to the ATtiny85's **PB2** (Pin 7, Analog Input 1).
3.  **LED:**
    *   Connect the positive (long) leg of the LED to one end of the 220Ω resistor.
    *   Connect the other end of the resistor to the ATtiny85's **PB0** (Pin 5).
    *   Connect the negative (short) leg of the LED to GND.

<!-- Placeholder for a circuit diagram -->

### 💡 Program Logic

The logic of the program is straightforward:

1.  **Read Analog Value:** The ATtiny85 continuously reads the analog voltage from the temperature sensor via pin PB2. This gives a value between 0 and 1023.
2.  **Convert to Temperature:** This raw value is converted into a temperature reading.
    *   First, it's converted to a voltage (0-5V).
    *   Then, it's converted from voltage to Celsius using the sensor's specifications `(Voltage - 0.5) * 100`.
    *   Finally, the Celsius value is converted to Fahrenheit.
3.  **Indicate Temperature Range:** The program checks the calculated Fahrenheit temperature and blinks the LED on pin PB0 at different rates to indicate the range:
    *   **-40°F to 68°F:** Fast blink (cold).
    *   **70°F to 116°F:** Medium blink (moderate).
    *   **123°F to 238°F:** Slow blink (hot).
    *   **Other ranges:** The LED stays on continuously, indicating an out-of-range or error state.

## 💻 Code

Here is the complete Arduino C++ code to be uploaded to the ATtiny85.

```cpp
// C++ code
// Define pin numbers for clarity
int ledPin = 0;      // Physical Pin 5 (PB0)
#define sensorPin A1 // Physical Pin 7 (PB2)

double fahrenheit;

void setup()
{
  pinMode(ledPin, OUTPUT);
  fahrenheit = 0.0;
}

void loop()
{
  // Read the raw analog value from the sensor
  int sensorValue = analogRead(sensorPin);

  // Convert the analog reading (0-1023) to a voltage (0-5V)
  double voltage = (double)sensorValue / 1024.0;
  voltage *= 5.0;

  // Convert voltage to temperature in Celsius
  // (assumes a sensor like TMP36 with 10mV per degree C and 500mV offset)
  double celsius = (voltage - 0.5) * 100;

  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  // Check the temperature range and blink the LED accordingly
  if (fahrenheit >= -40 && fahrenheit <= 68)
  {
    // Fast blink for cold temperatures
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  else if (fahrenheit >= 70 && fahrenheit <= 116)
  {
    // Medium blink for moderate temperatures
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (fahrenheit >= 123 && fahrenheit <= 238)
  {
    // Slow blink for hot temperatures
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else
  {
    // Solid ON for out-of-range temperatures
    digitalWrite(ledPin, HIGH);
  }
}
```
## 🚀 Applications

This simple thermometer can be used in or adapted for various applications:

*   **Room Temperature Monitor:** A simple visual indicator for your room's comfort level.
*   **Educational Tool:** A great hands-on project for teaching basic electronics, programming, and sensor integration.
*   **Weather Station:** Can serve as the temperature-sensing module in a larger DIY weather station.
*   **Enclosure Monitor:** Monitor the temperature inside a 3D printer enclosure, a server rack, or a terrarium.
*   **Basic Alert System:** The logic can be modified to trigger a solid light or a buzzer when a certain temperature threshold is crossed.
