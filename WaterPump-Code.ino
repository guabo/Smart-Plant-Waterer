/*
 */
int moisturePin = A5;
int knobPin = A2; 
int pumpPin = 2;

void setup() {
  pinMode(moisturePin, INPUT);
  pinMode(knobPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  //read moisture sensor data (the greater the value, the lower the moisture content)
  int moistureValue = analogRead(moisturePin);
  //read potentiometer data
  int knobValue = analogRead(knobPin);
  Serial.println(knobValue);
  Serial.println(moistureValue);

  //Turn on the pump when the moisture value is larger than the threshold
    if(moistureValue>knobValue){
      digitalWrite(pumpPin, HIGH);
      Serial.println("pump on");
    }else{
      digitalWrite(pumpPin, LOW);
      Serial.print("pump off");
    }
    delay(1000);
}
