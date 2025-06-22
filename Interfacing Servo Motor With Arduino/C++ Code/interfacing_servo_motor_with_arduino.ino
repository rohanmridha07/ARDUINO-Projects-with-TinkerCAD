// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// Include the servo library
#include <Servo.h>
// Create a servo object
Servo Myservo;
// Variable to store the servo position
int pos;

void setup()
{
  // Attach the servo on pin 7 to the servo object
  Myservo.attach(7);
}
void loop()
{
  // Sweep from 0 degrees to 180 degrees
  for (pos = 0; pos <= 180; pos++) {
    Myservo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(40);           // Wait 40ms for the servo to reach the position
  }
  delay(1000); // Wait for a second
  // Sweep from 180 degrees to 0 degrees
  for (pos = 180; pos >= 0; pos--) {
    Myservo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(40);           // Wait 40ms for the servo to reach the position
  }
  delay(3000); // Wait for three seconds
}
