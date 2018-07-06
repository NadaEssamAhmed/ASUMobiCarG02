 #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
 
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency


char g;
float sp;
float max_sp=180;
float MPR=1/max_speed   //MPR=1/RPM  ....fixed
float Millis_Per_Degree=MPR*(60*1000*360); 
float Millis=Millis_Per_Degree*x;//time needed to rotate x degrees
float Millis_Per_Degree =Millis/x;
float MPR =Millis_Per_Degree/(60*1000*360)
float sp=1/MPR // minuit per revolution
    
  
 void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); //start serial IN CASE WE NEED TO PRINT DEBUGGING INFO
}

void loop() {
  // put your main code here, to run repeatedly:
  
    while(1)
    {
//currentMillis=millis();  //get the current time (actually the number of milliseconds since the program started)
if (Serial.available()>0)
{   float x=Serial.parseFloat();   // enter the degree
 
    
     if (Serial.available()>0)
     {    g= Serial.read();

     
          if(g=='r')                 //turn right with x degrees
         {         }
   
  
          if (g='l')              //turn left with x degrees
         {       }
      
     }
}       
}
}




