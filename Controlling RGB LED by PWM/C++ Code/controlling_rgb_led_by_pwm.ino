// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
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
  // Use analogWrite to set the brightness of each color component
  // A value of 255 is full brightness, 0 is off.
  analogWrite(RedPin, Red);
  analogWrite(GreenPin, Green);
  analogWrite(BluePin, Blue);
}
