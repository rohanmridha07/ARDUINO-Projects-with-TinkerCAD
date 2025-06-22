// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirPin = 13;
int ledPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  // Give the sensor time to calibrate
  Serial.print("Calibrating Sensor ");
  for (int i = 0; i < calibrationTime; i++)
  {
    Serial.print(".");
    delay(1000);
  }
    Serial.println("\nDONE");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void loop()
{
  if (digitalRead(pirPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    if(lockLow)
    { 
     // A new motion event has been detected
     lockLow = false;
     Serial.println("---");
     Serial.print("Motion detected at ");
     Serial.print(millis()/1000);
     Serial.println(" sec");
     delay(50);
    }
    takeLowTime = true;
  }
  
  if (digitalRead(pirPin) == LOW)
  {
    digitalWrite(ledPin, LOW);
    if(takeLowTime)
    { 
      // Start the timer for the end of the motion
      lowIn = millis();
      takeLowTime = false;
    }
  }
    // If motion has stopped for the specified pause duration
    if(!lockLow && millis() - lowIn > pause)
    { 
     lockLow = true;
     Serial.print("Motion ended at ");
     Serial.print((millis() - pause) / 1000);
     Serial.println(" sec");
     Serial.println("---");
     delay(50);
    } 
}
