int Ultrasonic_Ranging()  //function of ultrasonic distance detecting
{
  delay(50);
  float distance = sonar.ping_cm();  // reading the duration of high level
  if (distance == 0) {
    digitalWrite(outputPin, LOW);
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW);
    float distance = pulseIn(inputPin, HIGH);  // reading the duration of high level
    distance = (distance / 29) / 2; // Transform pulse time to distance (cm)
  }

  return distance;
}


float MIN_distnace = 6.0;
float STOPP_distnace = 4.0;
float front_distance;
float rigth_distance;
float left_distance;

void Self_control() {

  front_distance = Ultrasonic_Ranging();
  Serial.print(front_distance);
  Serial.println("cm");
  if (front_distance < STOPP_distnace) {
    stopp();
    delay(100);
    back();
    delay(50);
  } else if (front_distance <= MIN_distnace) {
    stopp();
    delay(100);
    Set_servopulse(5);  //Moves Servo to left (5°)
    left_distance = Ultrasonic_Ranging();
    delay(300);
    Set_servopulse(177);  //Moves Servo to rigth (177°)
    rigth_distance = Ultrasonic_Ranging();
    delay(300);

    if (left_distance > rigth_distance) {
      back();
      delay(100);
      turnL();
      delay(450);
      stopp();
      delay(50);
      Set_servopulse(Start_angle);
      front_distance = Ultrasonic_Ranging();
      delay(300);
      Set_Speed(Lpwm_val, Rpwm_val);
    } else if (left_distance <= rigth_distance) {
      back();
      delay(100);
      turnR();
      delay(450);
      stopp();
      delay(50);
      Set_servopulse(Start_angle);
      front_distance = Ultrasonic_Ranging();
      delay(300);
      Set_Speed(Lpwm_val, Rpwm_val);
    } else if (left_distance < MIN_distnace && rigth_distance < MIN_distnace) {
      stopp();
      delay(50);
      back();
      delay(50);
      Set_Speed(Lpwm_val, Rpwm_val);
    }
  } else {
    advance();
    
  }
}