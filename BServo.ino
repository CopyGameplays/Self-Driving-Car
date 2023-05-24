void servopulse(int servopin, int myangle)  //defining a function of pulse
{
  pulsewidth = (myangle * 11) + 500;  //converting angle into pulse width value at 500-2480
  digitalWrite(servopin, HIGH);       //increasing the level of motor interface to upmost
  delayMicroseconds(pulsewidth);      //delaying microsecond of pulse width value
  digitalWrite(servopin, LOW);        //decreasing the level of motor interface to the least
  delay(20 - pulsewidth / 1000);
}

void Set_servopulse(int set_val) {
  for (int i = 0; i <= 10; i++)     //giving motor enough time to turn to assigning point
    servopulse(servopin, set_val);  //invokimg pulse function
}
