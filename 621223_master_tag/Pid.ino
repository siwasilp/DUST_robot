//========= call_spd =============
void getMotorsSpeed()  {  
  static long countAnt_1 = 0, countAnt_2 = 0, countAnt_3 = 0, countAnt_4 = 0;   
  speed_act1 = ((count_1 - countAnt_1)*(60*(1000/LOOPTIME)))/(3*298);     
  countAnt_1 = count_1;
  speed_act2 = ((count_2 - countAnt_2)*(60*(1000/LOOPTIME)))/(3*298);         
  countAnt_2 = count_2;
}

//=========  SET PID Motor PWM =======
int updatePid(int command, int targetValue, int currentValue)   {             // compute PWM value
  float pidTerm = 0;                                                            // PID correction
  float error = 0;                                  
  static float last_error = 0;
  unsigned long reachTime = 0;
  error = abs(targetValue) - abs(currentValue); 
  pidTerm = (Kp * error) + (Kd * (error - last_error));                            
  last_error = error;
  return constrain(command + int(pidTerm), 0, 255);
}

//========= PID R && L Motor =========
void setMotors(){
  if((millis()-lastMilli) >= LOOPTIME)   {                                    // enter tmed loop
    lastMilli = millis();
    getMotorsSpeed();                                                          // calculate speed, volts and Amps
    PWM_val1 = updatePid(PWM_val1, speed_req1, speed_act1);                   // compute PWM value
    PWM_val2 = updatePid(PWM_val2, speed_req2, speed_act2);                   // compute PWM value
  }
}
