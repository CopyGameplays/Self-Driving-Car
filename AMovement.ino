unsigned char LTurn_speed = 220;
unsigned char RTurn_speed = 220;  


void advance()  //  going forward
{
  
  digitalWrite(pinRigth_1, LOW);
  digitalWrite(pinRigth_2, HIGH);
  digitalWrite(pinLeft_1, LOW);
  digitalWrite(pinLeft_2, HIGH);
}

void back()  //  going backwards
{
  digitalWrite(pinRigth_1, HIGH);
  digitalWrite(pinRigth_2, LOW);
  digitalWrite(pinLeft_1, HIGH);
  digitalWrite(pinLeft_2, LOW);
}

void stopp()  //  going nowere
{
  digitalWrite(pinRigth_1, LOW);
  digitalWrite(pinRigth_2, LOW);
  digitalWrite(pinLeft_1, LOW);
  digitalWrite(pinLeft_2, LOW);
}

void turnL()  //turning left(dual wheel)
{
  Set_Speed(LTurn_speed, RTurn_speed);
  digitalWrite(pinRigth_1, LOW);  //making motor move towards right front
  digitalWrite(pinRigth_2, HIGH);
  digitalWrite(pinLeft_1, HIGH);
  digitalWrite(pinLeft_2, LOW);  //making motor move towards left rear
}
void turnR()  //turning rigth(dual wheel)
{
  Set_Speed(LTurn_speed, RTurn_speed);
  digitalWrite(pinRigth_1, HIGH);
  digitalWrite(pinRigth_2, LOW);  //making motor move towards right rear
  digitalWrite(pinLeft_1, LOW);   //making motor move towards left front
  digitalWrite(pinLeft_2, HIGH);
}