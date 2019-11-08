int ledState = 0;
int ledPin = 13;
const int analogInPin = A0;
int sensorValue = 0;
int tempo;

long previousMillis = 0;        
long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
    
}

void loop() {
  int sensorValue = analogRead(A0);
  sensorValue = analogRead(analogInPin);
  Serial.print("Sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t Tempo = ");
  Serial.println(tempo);
  delay(100);
  tempo = map(sensorValue, 0, 1023, 40, 210);
  
  int interval = (1000/tempo)*60; //algorithm to convert tempo into BPM
  
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;   

   //if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
