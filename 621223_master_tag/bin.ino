//==================== Encoder ==============================
void rencoder_1()  {
  if (PIND & 0b00010000)    count_1++;
  else                      count_1--;
}
void rencoder_2()  {
  if (PIND & 0b10000000)    count_2++;
  else                      count_2--;
}

//===================== LED Blink ===========================
void waitBlinking(int n, int frequency) {
  //blink for n seconds at frequency hz
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= frequency; j++) {
      digitalWrite(led, HIGH);
      delay((1000 / frequency) / 2); //Half time on
      digitalWrite(led, LOW);
      delay((1000 / frequency) / 2); //Half time off
    }
  }
}

//===================== Convert Sensor to ___cm. =============
double sdSHARP(int Sensor) {
  double dist = pow(analogRead(Sensor), -0.857);
  return (dist * 1167.9);   //Returns the distance in cm
}

//==================== Batterry Convest 12v ==================
float  readBattery(int input) {
  int readInput;
  float voltage;
  readInput = analogRead(input);
  voltage = (((readInput * 4.9) / 1000) * voltageBatCharged ) / 5;
//  Serial.print(" Battery= ");
//  Serial.print(voltage);
  return voltage;
}

//=================== Battrry Control ========================
void batteryControl(int input) {
  float v_battery;
  v_battery = readBattery(input);
  if (v_battery <= batteryLimitDischarge) {
    control = false;
  }
  else {
  }
}

//=================== Debug ===============================
void printMotorsInfo()  {                                                      
  if((millis()-lastMilliPrint) >= 500)   {                     
    lastMilliPrint = millis();
    Serial.print("  SP_1:");            Serial.print(speed_req1);  
    Serial.print("  RPM_1: ");          Serial.print(speed_act1);
    Serial.print("  PWM_1: ");          Serial.print(PWM_val1);
    Serial.print(", SP_2: ");           Serial.print(speed_req2);  
    Serial.print("  RPM_2: ");          Serial.print(speed_act2);
    Serial.print("  PWM_2: ");          Serial.print(PWM_val2);    
    Serial.println();
  }
}
