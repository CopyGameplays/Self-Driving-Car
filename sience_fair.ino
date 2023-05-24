#include <Wire.h>  //including libraries of I2C


int inputPin = A0;   // ultrasonic module   ECHO to A0
int outputPin = A1;  // ultrasonic module  TRIG to A1

int servopin = 3;    //digital port pin 3, connecting to signal line of servo motor
int pinLeft_1 = 2;   //Controls Directon of Left motor (A) ---- IN1 of motor driver board
int pinLeft_2 = 4;   //Controls Directon of Left motor (A) ---- IN2 of motor driver board
int pinRigth_1 = 7;  //Controls Directon of Rigth motor (B) ---- IN3 of motor driver board
int pinRigth_2 = 8;  //Controls Directon of Rigth motor (B) ---- IN4 of motor driver board
#define Lpwm_pin 5   //left Motor Power (motor A) -- ENA of motor driver board
#define Rpwm_pin 10  //Rigth Motor Power (motor B) -- ENB of motor driver board


int Car_state = 0;  //the working state of car
int myangle;        //defining variable of angle
int pulsewidth;     //defining variable of pulse width

unsigned char Lpwm_val = 250;    //initialized left wheel speed at 250
unsigned char Rpwm_val = 250;    //initialized right wheel speed at 250
unsigned char Start_angle = 90;  //initialized angle of motor at 90°

void M_Control_IO_config(void) {
  pinMode(pinLeft_1, OUTPUT);   // /pin 2
  pinMode(pinLeft_2, OUTPUT);   // pin 4
  pinMode(pinRigth_1, OUTPUT);  // pin 7
  pinMode(pinRigth_2, OUTPUT);  // pin 8
  pinMode(Lpwm_pin, OUTPUT);    // pin 11 (PWM)
  pinMode(Rpwm_pin, OUTPUT);    // pin10(PWM)
}

void Set_Speed(unsigned char Left, unsigned char Right)  //function of setting speed
{
  analogWrite(Lpwm_pin, Left);
  analogWrite(Rpwm_pin, Right);
}

void setup() {
  pinMode(servopin, OUTPUT);      //setting motor interface as output
  Serial.begin(9600);             //initialized serial port , using Bluetooth as serial port, setting baud
  M_Control_IO_config();          //motor controlling the initialization of IO
  pinMode(inputPin, INPUT);       //starting receiving IR remote control signal
  pinMode(outputPin, OUTPUT);     //IO of ultrasonic module
  Set_Speed(Lpwm_val, Rpwm_val);  //setting initialized speed
  Set_servopulse(Start_angle);
}


void loop() {

  Self_control();
}
