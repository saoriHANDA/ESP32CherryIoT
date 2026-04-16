const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

bool swState;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(vibPin, OUTPUT);// スイッチは安定させるために INPUT_PULLUP 
  
}
void loop() {
  if (digitalRead(swPin) == HIGH) {//(swState == 1) {
   swState = !swState;

  }

  if (swState == 1) { 
    digitalWrite(vibPin, HIGH); //ON
    Serial.println("ON");
    delay(300);
  } else {
    digitalWrite(vibPin, LOW); //OFF
    Serial.println("OFF");
    delay(300);
  }
}
