void advance()  //  going forward
{
  digitalWrite(pinRigth_1, LOW);
  digitalWrite(pinRigth_2, HIGH);
  digitalWrite(pinLeft_1, LOW);
  digitalWrite(pinLeft_2, HIGH);
  Car_state = 1;
}

void back()  //  going backwards
{
  digitalWrite(pinRigth_1, HIGH);
  digitalWrite(pinRigth_2, LOW);
  digitalWrite(pinLeft_1, HIGH);
  digitalWrite(pinLeft_2, LOW);
  Car_state = 2;
}

void stopp()  //  going nowere
{
  digitalWrite(pinRigth_1, LOW);
  digitalWrite(pinRigth_2, LOW);
  digitalWrite(pinLeft_1, LOW);
  digitalWrite(pinLeft_2, LOW);
  Car_state = 0;
}

void turnR()  //turning right(dual wheel)
{
  digitalWrite(pinRigth_1, LOW);  //making motor move towards right rear
  digitalWrite(pinRigth_2, HIGH);
  digitalWrite(pinLeft_1, HIGH);
  digitalWrite(pinLeft_2, LOW);  //making motor move towards left front
  Car_state = 4;
}
void turnL()  //turning left(dual wheel)
{
  digitalWrite(pinRigth_1, HIGH);
  digitalWrite(pinRigth_2, LOW);  //making motor move towards right front
  digitalWrite(pinLeft_1, LOW);   //making motor move towards left rear
  digitalWrite(pinLeft_2, HIGH);
  Car_state = 3;
}