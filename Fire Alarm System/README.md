# 🔥 Arduino Fire Alarm System

A simple yet effective DIY fire alarm system built using an Arduino Uno. This project detects potential fire hazards by monitoring temperature and gas levels, triggering a visual and audible alarm when thresholds are exceeded.

## 🧱 Required Components

*   1x Arduino UNO
*   1x Temperature Sensor (LM35)
*   1x Gas Sensor (MQ-2 or similar)
*   1x LED (any color)
*   1x Piezo Buzzer
*   2x 220Ω Resistors
*   1x Breadboard
*   Jumper Wires

## ⚙️ How It Works

This system continuously reads data from the temperature and gas sensors to detect signs of a fire.

### 🔌 Circuit Setup

1.  **Temperature Sensor (LM35):**
    *   Connect VCC to 5V on the Arduino.
    *   Connect GND to GND on the Arduino.
    *   Connect the Vout pin to Analog pin `A0` on the Arduino.

2.  **Gas Sensor (MQ-2):**
    *   Connect VCC to 5V on the Arduino.
    *   Connect GND to GND on the Arduino.
    *   Connect the Analog Out (A0) pin to Analog pin `A1` on the Arduino.

3.  **LED:**
    *   Connect the longer leg (anode) to one end of a 220Ω resistor.
    *   Connect the other end of the resistor to Digital pin `13` on the Arduino.
    *   Connect the shorter leg (cathode) to GND.

4.  **Piezo Buzzer:**
    *   Connect the positive (+) leg to Digital pin `7` on the Arduino.
    *   Connect the negative (-) leg to GND.

### 🧠 Program Logic

The Arduino code follows a simple logic:

1.  **Initialization (`setup()`):**
    *   The analog pins (`A0`, `A1`) are set as `INPUT` to read sensor data.
    *   The digital pins for the LED (`13`) and Piezo (`7`) are set as `OUTPUT` to control the alarms.
    *   Serial communication is started at 9600 baud rate for debugging.

2.  **Main Loop (`loop()`):**
    *   The code reads the analog value from the temperature sensor, converts it to a Celsius reading.
    *   It also reads the raw analog value from the gas sensor.
    *   **If the temperature exceeds 80°C**, the LED is turned ON as a visual warning.
    *   **If the gas sensor reading exceeds a threshold of 100**, the Piezo buzzer is turned ON to create an audible alarm.
    *   If conditions are normal, the LED and buzzer remain OFF.
    *   The current temperature and gas sensor values are printed to the Serial Monitor for real-time monitoring.
    *   The loop repeats every second.

## 💻 Code

Here is the complete Arduino code for the project.

```cpp
// C++ code
//
float temp;
float vout;
float vout1;
int LED = 13;
int gasSensor;
int piezo = 7;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  vout = analogRead(A0);
  vout1 = (vout / 1023.0) * 5000; 
  temp = (vout1 - 500) / 10; 
  gasSensor = analogRead(A1);
  if (temp >= 80)
      {
        digitalWrite (LED, HIGH) ;
      }
  else
      {
        digitalWrite (LED, LOW) ;
      }
  if (gasSensor >= 100)
      {
        digitalWrite (piezo, HIGH) ;
      }
  else
      {
        digitalWrite (piezo, LOW) ;
      }
  Serial.print ("In Degree = ");
  Serial.print (" ");
  Serial.print (temp);
  Serial.print ("\t");
  Serial.print ("GasSensor = ");
  Serial.print (" ");
  Serial.print (gasSensor);
  Serial.println ();
  
  delay(1000); // Wait for 1000 millisecond(s)
}
```
## 🚀 Applications

This project can be adapted for various uses, including:

*   **Home Safety:** A basic fire alarm for kitchens, living rooms, or garages.
*   **Workshop Monitoring:** To detect overheating equipment or fires in a workshop.
*   **Server Rooms:** To monitor for overheating servers and potential electrical fires.
*   **Educational Tool:** An excellent starter project for learning about sensors, actuators, and basic programming with Arduino.
