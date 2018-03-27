  #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
  #include <RedBot.h> //add Line Follower sensor library
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); 
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); 
  AF_DCMotor motor3 (3, MOTOR12_1KHZ);  
  AF_DCMotor motor4 (4, MOTOR12_1KHZ);
  RedBotSensor left_sen = RedBotSensor(A3);   
  RedBotSensor center_sen = RedBotSensor(A4); 
  RedBotSensor right_sen = RedBotSensor(A5);  
  int lineStandard = 800;

void setup()
{ Serial.begin(9600);
  Serial.println("IR Sensor Readings:: ");
  delay(100);
}

void loop()
{
  Serial.print(left_sen.read());
  Serial.print("\t");  
  Serial.print(center_sen.read());
  Serial.print("\t"); 
  Serial.print(right_sen.read());
  Serial.println();

  // if on the line drive left and right at the same speed (left is CCW / right is CW)
  if(center_sen.read() > lineStandard)
  {//right
   right_car();
  }
  //data_sheet
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right_sen.read() > lineStandard)
  {//left
  left_car();
  }
  //data_sheet
  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left_sen.read() > lineStandard)
  {//right
  right_car();
  }
  //data_sheet
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left_sen.read() > lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    //stop
    stop_car ();
  }
  else
  {
  //any dir
    forward_car();
  }
  delay(0);  // add a delay to decrease sensitivity.
}

 void forward_car()
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  }
  void back_car()
  {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  }
  void right_car()
  {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  }
  void left_car()
  {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  }
  void stop_car ()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
