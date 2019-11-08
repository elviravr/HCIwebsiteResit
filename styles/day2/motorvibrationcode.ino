void setup() {
  pinMode( 3 , OUTPUT);  // Must be a PWM pin
}

void loop() {

  analogWrite( 3 , 80 );
  delay(1000);

  analogWrite( 3 , 255 );    // 0% duty cycle (off)
  delay(1000);           

  analogWrite( 3 , 80 );
  delay(1000);
}
