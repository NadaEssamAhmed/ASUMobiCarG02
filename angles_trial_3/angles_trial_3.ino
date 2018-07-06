 #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
 
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency

float x;
float g;
float sp=180;
  
 void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //start serial IN CASE WE NEED TO PRINT DEBUGGING INFO
}


void loop() {
  // put your main code here, to run repeatedly:
  
   
//currentMillis=millis();  //get the current time (actually the number of milliseconds since the program started)
if (Serial.available()>0)
{   x=Serial.parseFloat();  //enter the degree
    Serial.println(x);
    
     if (Serial.available()>0)
     {    g= Serial.parseInt();
          Serial.println(g);
      
          if(g=='1')                 //turn right with x degrees
         {      right_angle();   }
   
  
          if (g='2')              //turn left with x degrees
         {      left_angle();    }
      
     }
}
       
}
     

  void right_angle()
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(sp-x);
  motor2.run(FORWARD);
  motor2.setSpeed(sp);
  motor3.run(BACKWARD);
  motor3.setSpeed(sp-x);
  motor4.run(FORWARD);
  motor4.setSpeed(sp);
  }
  void left_angle()
  {
  motor1.run(FORWARD);
  motor1.setSpeed(sp);
  motor2.run(BACKWARD);
  motor2.setSpeed(sp-x);
  motor3.run(FORWARD);
  motor3.setSpeed(sp);
  motor4.run(BACKWARD);
  motor4.setSpeed(sp-x);
  }
