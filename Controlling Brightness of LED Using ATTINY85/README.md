# ATtiny85 LED Brightness Control with a Potentiometer

This project demonstrates how to control the brightness of an LED using an ATtiny85 microcontroller and a potentiometer. It's a simple yet fundamental electronics project, perfect for learning about Pulse Width Modulation (PWM) and analog inputs with the ATtiny85.

## 🧰 Required Components

*   1x ATtiny85 Microcontroller
*   1x LED (any color)
*   1x 47Ω Resistor (current-limiting for the LED)
*   1x 250kΩ Potentiometer
*   1x Breadboard
*   Jumper Wires
*   An Arduino (or a dedicated programmer) to program the ATtiny85.

## 🧠 How It Works

The project works by reading an analog value from the potentiometer and using that value to control the brightness of the LED via Pulse Width Modulation (PWM).

### 🔌 Circuit Setup

1.  **Potentiometer:**
    *   Connect one of the outer pins to **GND**.
    *   Connect the other outer pin to **VCC (+5V)**.
    *   Connect the middle pin (the wiper) to the ATtiny85's **Analog Pin A3** (Physical Pin 2).

2.  **LED:**
    *   Connect the LED's positive (longer) leg to the ATtiny85's **Pin 0** (Physical Pin 5).
    *   Connect the LED's negative (shorter) leg to one end of the **47Ω resistor**.
    *   Connect the other end of the resistor to **GND**.

3.  **ATtiny85 Power:**
    *   Connect **Pin 8** to **VCC (+5V)**.
    *   Connect **Pin 4** to **GND**.

![A simple diagram or image of the breadboard setup would be great here!]

### 📜 Program Logic

The logic is straightforward:
1.  **Read:** The ATtiny85 continuously reads the analog voltage from the potentiometer's middle pin. This gives a raw value from **0 to 1023**.
2.  **Map:** This 10-bit value (0-1023) is then mapped (or scaled) down to an 8-bit value (**0 to 255**), which is the range required for PWM output.
3.  **Write:** The `analogWrite()` function sends a PWM signal to the LED. A value of `0` means the LED is fully off, `255` means it's at full brightness, and any value in between creates a perceived dimming effect.

## 💻 Code

Here is the simple Arduino sketch to upload to your ATtiny85 (after setting up your environment for ATtiny development).

```cpp
// C++ code
//
int LedPin = 0;      // LED connected to physical pin 5 (PWM capable)
int Pot_Value = 0;   // Variable to store the value from the potentiometer
int SensorPin = A3;  // Potentiometer's middle pin connected to physical pin 2

void setup()
{
  // Set the LED pin as an output
  pinMode(LedPin, OUTPUT);
  // Set the potentiometer pin as an input
  pinMode(SensorPin, INPUT);
}

void loop()
{
  // Read the analog value from the potentiometer (0-1023)
  Pot_Value = analogRead(SensorPin);
  
  // Map the 10-bit analog value to an 8-bit PWM value (0-255)
  Pot_Value = map(Pot_Value, 0, 1023, 0, 255);
  
  // Write the PWM value to the LED to set its brightness
  analogWrite(LedPin, Pot_Value);
}
```
## ✨ Applications

This simple circuit is a building block for many other projects, including:

*   Manual dimmers for custom lighting setups or mood lamps.
*   A simple control knob for motor speed, fan speed, or servo position.
*   Providing visual feedback for a sensor's value.
*   Interactive art installations where users can control light intensity.
