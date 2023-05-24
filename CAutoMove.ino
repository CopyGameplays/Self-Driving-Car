int Ultrasonic_Ranging()  //function of ultrasonic distance detecting
{

  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  float distance = pulseIn(inputPin, HIGH);  // reading the duration of high level
  distance = (distance / 29) / 2;            // Transform pulse time to distance (cm)
  return distance;
}

float front_distance;
float rigth_distance;
float left_distance;

void Self_control() {

  front_distance = Ultrasonic_Ranging();

  if (front_distance < 2.5) {
    stopp();
    delay(100);
    back();
    delay(50);
  } else if (front_distance <= 3.5) {
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
      delay(400);
      stopp();
      delay(50);
      Set_servopulse(90);
      front_distance = Ultrasonic_Ranging();
      delay(300);
    } else if (left_distance <= rigth_distance) {
      back();
      delay(100);
      turnR();
      delay(400);
      stopp();
      delay(50);
      Set_servopulse(90);
      front_distance = Ultrasonic_Ranging();
      delay(300);
    } else if (left_distance < 3.5 && rigth_distance < 3.5) {
      stopp();
      delay(50);
      back();
      delay(50);
    }
  } else {
    advance();
  }
}