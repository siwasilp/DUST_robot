#include <math.h>
#define SD1     (0)   //left front sensor
#define SD2     (1)   //right front sensor
// Battery Voltage input
#define battery     (4)   //Analog
// IndicatorLED
#define led         (13)
// Fan output
#define fanmotor    (12)  // the number of the LED pin
// Motor1 Right
#define motor1Pin1  (9)
#define motor1Pin2  (10)
#define encodPinA1  (2)   // encoder A pin, interrupt pin of Arduino Uno
#define encodPinB1  (4)   // encoder B pin, read motor direction
// Motor2 Left
#define motor2Pin1  (5)
#define motor2Pin2  (6)
#define encodPinA2  (3)   // encoder A pin, interrupt pin of Arduino Uno
#define encodPinB2  (7)   // encoder B pin, read motor direction

#define pwmMax      (255)
#define pwmMin      (0)
#define LOOPTIME  (100)

const float voltageBatCharged = 12.68; 
const float batteryLimitDischarge = 11.6; 

// Variables will change:
int bumperState = 0;  // variable for reading the pushbutton status
int counter = 0; //   Prevents from being stuck
boolean control = true;
boolean printOnce = true; //For debugging

unsigned long lastMilli = 0;    // loop timing
unsigned long lastMilliPrint = 0;
unsigned long lastErrorMilli = 0;
//Motor 1
float speed_req1 = 200.0;            // speed (Set Point)
float speed_act1 = 0.0;             // speed (actual value)
int PWM_val1 = 0;               // (25% = 64; 50% = 127; 75% = 191; 100% = 255)
volatile long count_1 = 0;      // rev counter
//Motor 2
float speed_req2 = 200.0;
float speed_act2 = 0.0;
int PWM_val2 = 0;
volatile long count_2 = 0;

float Kp =   0.6;// 0.65;        // PID Proportional control Gain   (Good values as well: 0.5)
float Kd =   0.0;// 0.005;       // PID Derivitave control Gain

int ssL, ssR , aaa , x = 0;
