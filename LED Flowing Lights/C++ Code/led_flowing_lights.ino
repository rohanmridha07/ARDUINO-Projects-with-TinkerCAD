// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
unsigned char LED;
void setup() 
{
  // Loop to set pins 1 through 8 as outputs
  for (LED = 1; LED <= 8; LED++)
  {
    pinMode(LED, OUTPUT);
  }
}
void loop() {
  
  // Turn LEDs on one by one
  for (LED = 1; LED <= 8; LED++) {
    digitalWrite(LED, HIGH);
    delay(300);
  }
  
  // Turn LEDs off one by one
  for (LED = 1; LED <= 8; LED++) {
    digitalWrite(LED, LOW);
    delay(300);
  }
}
