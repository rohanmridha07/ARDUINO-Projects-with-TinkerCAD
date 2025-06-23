# Interfacing Temperature Sensor With Arduino 🌡️

This repository contains a simple Arduino project that demonstrates how to interface an analog temperature sensor (like a TMP36) with an Arduino Uno. The project reads the ambient temperature and displays the values in Celsius and Fahrenheit on the Serial Monitor.

## ⚙️ Required Components
*   **Arduino Uno:** The microcontroller board.
*   **Temperature Sensor:** An analog sensor like the **TMP36**. The provided code is calibrated for this sensor's output characteristics.
*   **Breadboard:** For creating the circuit.
*   **Jumper Wires:** To connect the components.

## 🔌 How It Works

### Circuit Setup
The setup is straightforward. You need to connect the three pins of the temperature sensor to the Arduino Uno.

1.  **VCC / Power Pin:** Connect to the `5V` pin on the Arduino.
2.  **GND Pin:** Connect to the `GND` pin on the Arduino.
3.  **Vout / Data Pin:** Connect to an analog input pin on the Arduino, in this case, `A0`.

> **Note:** Always check the pinout diagram for your specific temperature sensor model before connecting it!

### Program Logic
The Arduino's built-in Analog-to-Digital Converter (ADC) reads the voltage from the sensor's data pin. This voltage is directly proportional to the ambient temperature. The program then takes this raw analog reading and converts it into a human-readable temperature value in both Celsius and Fahrenheit.

## 👨‍💻 Brief Program Logic
The `loop()` function continuously performs the following steps:

1.  Reads the raw analog value (an integer from 0 to 1023) from pin `A0`.
2.  Converts this raw value into a voltage reading (0V to 5V).
3.  Applies the sensor-specific formula to convert the voltage into a temperature in Celsius. The formula `temp_celsius = 100 * (Voltage - 0.5)` is used for the TMP36 sensor, which has a 10mV/°C scale factor and a 500mV offset.
4.  Converts the Celsius temperature into Fahrenheit.
5.  Prints all the readings (Analog, Voltage, Celsius, and Fahrenheit) to the Serial Monitor for you to see.
6.  Waits for 3 seconds before taking the next reading.

## 📝 Code
Here is the complete Arduino sketch used in this project.

```cpp
// C++ code
//
int temp = A0;
float temp_celsius;
float Voltage;
float analog_reading;
float temp_far;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  analog_reading = analogRead(A0);
  Serial.print("Analog reading:");
  Serial.println(analog_reading);
  
  // Use 1024.0 to ensure floating-point division for accuracy
  Voltage = (analog_reading * 5.0) / 1024.0;
  Serial.print("Voltage reading:");
  Serial.println(Voltage);
  
  temp_celsius = 100 * (Voltage - 0.5);
  Serial.println("Celsius reading:" + String (temp_celsius) + ("C"));
  
  temp_far = (temp_celsius * 1.8) + 32;
  Serial.println("Fahrenheit reading:" + String (temp_far) + ("F\n"));
  
  delay(3000); 
}
```
## 🚀 Applications
This simple project is a great starting point and can be expanded for many real-world applications, such as:

*   **Home Weather Station:** To monitor local temperature conditions.
*   **Smart Thermostat:** As a core component for a DIY room temperature control system.
*   **Overheating Alarm:** To monitor the temperature of electronic devices like PCs or amplifiers and trigger a fan or an alarm.
*   **Environmental Data Logging:** For scientific experiments or garden monitoring.
*   **Process Control:** To ensure a process is running within a specific temperature range.
