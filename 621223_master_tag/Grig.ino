int jj = 0;
int cm = m_run * 50;
int dx = n_run*(100/15)+2;  // 6.67

void loop_grid(){
  if (aaa == cm){jj++;Serial.print(jj);}
  if (jj == dx){while(1){    moveMotors(1000, PWM_val1, PWM_val2, 's'); Serial.println("ok");}}
  
  if (x == 0 && aaa > cm ) {
    moveMotors(1450, PWM_val1, PWM_val2, 'r');
    moveMotors(1000, PWM_val1, PWM_val2, 'f');
    moveMotors(1450, PWM_val1, PWM_val2, 'r');
    count_1=0;
    count_2=0;
    aaa = 0;
    x = 1;
  }
  if (x == 1 && aaa > cm) {
    moveMotors(1450, PWM_val1, PWM_val2, 'l');
    moveMotors(1000, PWM_val1, PWM_val2, 'f');
    moveMotors(1450, PWM_val1, PWM_val2, 'l');
    count_1=0;
    count_2=0;
    aaa = 0;
    x = 0;
  }
  
}
