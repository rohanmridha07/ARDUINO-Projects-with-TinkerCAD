# Interfacing a 4x4 Keypad with Arduino Uno ⌨️

A simple Arduino project to demonstrate how to read inputs from a 4x4 matrix keypad and display the pressed key on the Serial Monitor. This is a fundamental building block for many projects that require user input.

## ✅ Required Components

*   Arduino UNO
*   4x4 Matrix Keypad
*   Jumper Wires

## ⚙️ How It Works

### 🔌 Circuit Setup

The 4x4 keypad has 8 pins. The first 4 pins are for the rows, and the next 4 are for the columns. Connect these pins to the digital I/O pins on the Arduino Uno as follows:

*   **Row 1 (R1)** → Arduino Pin 9
*   **Row 2 (R2)** → Arduino Pin 8
*   **Row 3 (R3)** → Arduino Pin 7
*   **Row 4 (R4)** → Arduino Pin 6
*   **Column 1 (C1)** → Arduino Pin 5
*   **Column 2 (C2)** → Arduino Pin 4
*   **Column 3 (C3)** → Arduino Pin 3
*   **Column 4 (C4)** → Arduino Pin 2

### 🧠 Program Logic

The program uses the `Keypad.h` library, which simplifies the process of reading from a matrix keypad.

1.  **Initialization:** A 2D character array `keys[ROWS][COLS]` is created to map the physical layout of the keypad to its corresponding character value (e.g., '1', 'A', '#').
2.  **Pin Mapping:** The Arduino pins connected to the keypad's rows and columns are defined in the `rowPins` and `colPins` arrays.
3.  **Keypad Object:** An instance of the `Keypad` class is created using the key map and pin definitions.
4.  **Main Loop:** In the `loop()` function, `keypad.getKey()` is called continuously. This function scans the keypad for any key presses. If a key is pressed, its character value is returned and printed to the Serial Monitor.

## 💻 Arduino Code

Here is the complete code to upload to your Arduino Uno.

```cpp
// C++ code
#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keymap
char keys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {9, 8, 7, 6};

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = {5, 4, 3, 2};

// Create the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Get the pressed key
  char key = keypad.getKey();

  if (key)
  {
    Serial.print("Key Pressed : ");
    Serial.println(key);
  }
}
```
## 💡 Applications

This basic setup can be extended for various applications, such as:

*   Security systems (Password-based door lock)
*   DIY Calculators
*   Menu navigation for LCD-based projects
*   Phone-style dialing systems
*   Game controllers
