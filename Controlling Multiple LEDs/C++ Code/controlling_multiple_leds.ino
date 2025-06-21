// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
// Define the analog pin for the potentiometer
int pot = A5;

// Variable to store the potentiometer value
int val = 0;

// Define digital pins for the LEDs
int led1 = 13; // Red 1
int led2 = 12; // Red 2
int led3 = 11; // Yellow 1
int led4 = 10; // Yellow 2
int led5 = 9;  // Green 1
int led6 = 8;  // Green 2

void setup()
{
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Set all LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  // Set the potentiometer pin as INPUT
  pinMode(pot, INPUT);
}

void loop() 
{
  // Read the analog value from the potentiometer (0-1023)
  val = analogRead(pot);
  
  // Print the value to the Serial Monitor to see what's happening
  Serial.println(val);
  
  // Check the value and control the LEDs accordingly
  if(val==0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else if(val > 0 && val <= 250)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val > 250 && val <= 500)
  {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);  
  }
  else if(val > 500)
  {
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
}
