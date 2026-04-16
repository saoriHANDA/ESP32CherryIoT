#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington


const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB


Servo myservo;
int angle = 0;
bool swState;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT); 
  myservo.attach(motorPin);
  
}
void loop() {
  if (digitalRead(swPin) == HIGH) {//(swState == 1) {
   swState = !swState;

  }

  if (swState == 1) { 
      digitalWrite(motorPin, HIGH); //ON
      Serial.println("Cleaning the ear");
        for(angle; angle <= 10; angle++) {                        
          myservo.write(angle);
          delay(15);
        }
    delay(200);
  } else {
    for(angle; angle >= 0; angle--) {  
      Serial.println("...");              
      myservo.write(angle);  
      delay(15);      
  }
}
}
