#include "config.h"

int dis_lim = 5; 

int m_run = 1;
int n_run = 1;

void setup() {
  //========== 0/5 : Setup_loop =======
  setup_0();
} 

void loop(){
  //Serial.println(aaa);
  //=========== 1/5 : Check ============
  batteryControl(battery); 
  //=========== 2/5 : setMotors ========
  setMotors(); 
  //=========== 3/5 : Sensor Run =======
  controlRobot(); 
  //=========== 4/5 : Grid Run =========
  loop_grid();
  //=========== 5/5 : Debug Pg. ========
  //printMotorsInfo();
}
