//========= Motor Move =============================================
void moveMotors(int moveTime, int pwmMotor1, int pwmMotor2, char direc) {
  switch (direc) {
    case 'f':
      analogWrite(motor1Pin1, pwmMotor1);
      analogWrite(motor1Pin2, 0);
      analogWrite(motor2Pin1, pwmMotor2);
      analogWrite(motor2Pin2, 0);
      delay(moveTime);
      break;
    case 'b':
      analogWrite(motor1Pin1, 0);
      analogWrite(motor1Pin2, pwmMotor1);
      analogWrite(motor2Pin1, 0);
      analogWrite(motor2Pin2, pwmMotor2);
      delay(moveTime);
      break;
    case 'r':
      analogWrite(motor1Pin1, 0);
      analogWrite(motor1Pin2, pwmMotor1);
      analogWrite(motor2Pin1, pwmMotor2);
      analogWrite(motor2Pin2, 0);
      delay(moveTime);
      break;
    case 'l':
      analogWrite(motor1Pin1, pwmMotor1);
      analogWrite(motor1Pin2, 0);
      analogWrite(motor2Pin1, 0);
      analogWrite(motor2Pin2, pwmMotor2);
      delay(moveTime);
      break;
    case 's':
      analogWrite(motor1Pin1, 0);
      analogWrite(motor1Pin2, 0);
      analogWrite(motor2Pin1, 0);
      analogWrite(motor2Pin2, 0);
      delay(moveTime);
      break;
    default:
      Serial.println("Default");
      break;
  }
}

//======== Logic Move =========================================
void controlRobot() {
  int ssL = sdSHARP(SD1);
  int ssR = sdSHARP(SD2);
//  Serial.print("SD1= ");
//  Serial.print(sdSHARP(SD1));
//  Serial.println();
//  Serial.print("  SD2= ");
//  Serial.print(sdSHARP(SD2));
//  Serial.println();
  if (ssL <= dis_lim && ssR <= dis_lim) {
    moveMotors(500, PWM_val1, PWM_val2,  's');
    moveMotors(1000, PWM_val1, PWM_val2, 'b');
    moveMotors(1000, PWM_val1, PWM_val2, 'l');
    counter = 3;
  }
  else if (ssL <= dis_lim) {
    moveMotors(1000, PWM_val1, PWM_val2, 'b');
    moveMotors(500, PWM_val1, PWM_val2, 'r');
    counter++;
  }
  else if (ssR <= dis_lim) {
    moveMotors(1000, PWM_val1, PWM_val2, 'b');
    moveMotors(500, PWM_val1, PWM_val2, 'l');
    counter++;
  }
  else {
    moveMotors(200, PWM_val1, PWM_val2, 'f');
    aaa++;
  }
  if (counter > 6) { //Corner
    // Serial.println("Corner");
    moveMotors(3800, PWM_val1, PWM_val2, 'l');
    counter = 0;
  }
  else {
  }
}
