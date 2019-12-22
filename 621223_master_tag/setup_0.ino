void setup_0() {
  Serial.begin(9600);
  pinMode(fanmotor, OUTPUT);
  //Motor1
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  //Motor2
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  //LED
  pinMode(led, OUTPUT);
  pinMode(encodPinA1, INPUT_PULLUP);
  pinMode(encodPinB1, INPUT_PULLUP);
  pinMode(encodPinA2, INPUT_PULLUP);
  pinMode(encodPinB2, INPUT_PULLUP);
  //Sensor
  pinMode(SD1, INPUT);
  pinMode(SD2, INPUT);

  //Batt
  pinMode(battery, INPUT);
  attachInterrupt(0, rencoder_1, FALLING);  //Pin 2 of Arduino Uno
  attachInterrupt(1, rencoder_2, FALLING);  //Pin 3 of Arduino Uno
  Serial.println("Starting...");
  waitBlinking(3, 1); 
  if (readBattery(battery) > 12.1) {
    digitalWrite(fanmotor, HIGH); //Turn the Fan ON
    delay(500); //For 1000ms
  }
  else {  }
}
