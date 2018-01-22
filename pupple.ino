/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

////////초음파/////////////////
const int trigPinFront = 30;
const int echoPinFront = 32;

const int trigPinBack = 22;
const int echoPinBack = 24;

const int trigPinLeft = 26;
const int echoPinLeft = 28;

const int trigPinRight = 38;
const int echoPinRight = 40;

const int forwardMode = 1;
const int backwardMode = 2;
const int waitMode = 3;

int mySpeed = 255;
int minRange = 30;
int midRange = 45;
int maxRange = 170;
int runMode = 1;

long durationFront, durationBack, durationLeft, durationRight;
long distanceFront, distanceBack, distanceLeft, distanceRight;
//////////////////////////////

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor_1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor_2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor_3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_4 = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

   pinMode(trigPinFront, OUTPUT);
   pinMode(echoPinFront, INPUT);
   pinMode(trigPinLeft, OUTPUT);
   pinMode(echoPinLeft, INPUT);
   pinMode(trigPinRight, OUTPUT);
   pinMode(echoPinRight, INPUT);
   pinMode(trigPinBack, OUTPUT);
   pinMode(echoPinBack, INPUT);
   
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor_1->setSpeed(mySpeed);
  myMotor_2->setSpeed(mySpeed);
  myMotor_3->setSpeed(mySpeed);
  myMotor_4->setSpeed(mySpeed);
  
}

void go_forward()
{
  myMotor_1->run(FORWARD);
  myMotor_2->run(FORWARD);
  myMotor_3->run(FORWARD);
  myMotor_4->run(FORWARD);
  myMotor_1->setSpeed(mySpeed);
  myMotor_2->setSpeed(mySpeed);
  myMotor_3->setSpeed(mySpeed);
  myMotor_4->setSpeed(mySpeed);
  Serial.println("forward");
  delay(10);
}

void go_backward()
{
  myMotor_1->run(BACKWARD);
  myMotor_2->run(BACKWARD);
  myMotor_3->run(BACKWARD);
  myMotor_4->run(BACKWARD);
  myMotor_1->setSpeed(mySpeed);
  myMotor_2->setSpeed(mySpeed);
  myMotor_3->setSpeed(mySpeed);
  myMotor_4->setSpeed(mySpeed);
  Serial.println("backward");
  delay(10);
}

void go_right()
{
  //go_stop();  
    myMotor_1->run(FORWARD);
    myMotor_2->run(BACKWARD);
    myMotor_3->run(BACKWARD);
    myMotor_4->run(FORWARD); 
    myMotor_1->setSpeed(mySpeed);
    myMotor_2->setSpeed(mySpeed);
    myMotor_3->setSpeed(mySpeed);
    myMotor_4->setSpeed(mySpeed);
    delay(40);
  //go_stop();  
    Serial.println("right");
}
void go_left()
{
  //go_stop();  
    myMotor_1->run(BACKWARD);
    myMotor_2->run(FORWARD);
    myMotor_3->run(FORWARD);
    myMotor_4->run(BACKWARD); 
    myMotor_1->setSpeed(mySpeed);
    myMotor_2->setSpeed(mySpeed);
    myMotor_3->setSpeed(mySpeed);
    myMotor_4->setSpeed(mySpeed);
    delay(40);
  //go_stop();  
    Serial.println("left");
}
void go_stop()
{
//    myMotor_1->run(FORWARD);
//    myMotor_2->run(FORWARD);
//    myMotor_3->run(FORWARD);
//    myMotor_4->run(FORWARD);
//    myMotor_1->setSpeed(75);
//    myMotor_2->setSpeed(75);
//    myMotor_3->setSpeed(75);
//    myMotor_4->setSpeed(75);
//    delay(15);    
//    myMotor_1->setSpeed(40);
//    myMotor_2->setSpeed(40);
//    myMotor_3->setSpeed(40);
//    myMotor_4->setSpeed(40);    
//    delay(15);
//    myMotor_1->setSpeed(20);
//    myMotor_2->setSpeed(20);
//    myMotor_3->setSpeed(20);
//    myMotor_4->setSpeed(20);
//    delay(15);
//    myMotor_1->setSpeed(0);
//    myMotor_2->setSpeed(0);
//    myMotor_3->setSpeed(0);
//    myMotor_4->setSpeed(0);
//    delay(20);    

  myMotor_1->run(RELEASE);
  myMotor_2->run(RELEASE);
  myMotor_3->run(RELEASE);
  myMotor_4->run(RELEASE);
}

////////초음파/////////////////
 long microsecondsToInches(long microseconds){
   return microseconds /74 /2;
}

long microsecondsToCentimeters(long microseconds){
   return microseconds /29 /2;
}
 /////////////////////////////////

void loop() {
  uint8_t i;
  
  //Serial.print("tick");

  //go_right();
  
  
////////초음파//////////////////////////////////////
   

     
    digitalWrite(trigPinBack, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinBack, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPinBack, LOW);
    durationBack = pulseIn(echoPinBack, HIGH); 
    
    
    
    digitalWrite(trigPinRight, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinRight, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinRight, LOW);
    durationRight = pulseIn(echoPinRight, HIGH);
    
    
    digitalWrite(trigPinFront, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinFront, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFront, LOW);
    durationFront = pulseIn(echoPinFront, HIGH);
    
  
  
    digitalWrite(trigPinLeft, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinLeft, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinLeft, LOW); 
    durationLeft = pulseIn(echoPinLeft, HIGH);

    
    distanceFront = microsecondsToCentimeters(durationFront);
    distanceBack = microsecondsToCentimeters(durationBack);
    distanceLeft = microsecondsToCentimeters(durationLeft);
    distanceRight = microsecondsToCentimeters(durationRight);
////////////////////////////////////////////////////
    Serial.print("Front : ");
    Serial.println(distanceFront);
    Serial.print("Back : ");
    Serial.println(distanceBack);
    Serial.print("Left : ");
    Serial.println(distanceLeft);
    Serial.print("Right : ");
    Serial.println(distanceRight);    
/*
    if(runMode == waitMode)
    {
        if( (distanceFront > maxRange) && (distanceBack > maxRange) )
        {
            Serial.println("Wait : Code -2");    
            Serial.print("runMode : :");
            Serial.println(runMode);    
            go_stop();
            runMode = waitMode;
        }
        else if(distanceFront > distanceBack)
        {
            Serial.println("From Wait Mode, Transfer into Forward Mode : Code -3");
            //go_stop();
            go_forward();
            runMode = forwardMode;          
        }
        else
        {
            Serial.println("From Wait Mode, Transfer into Backward Mode : Code -4");
            //go_stop();
            go_backward();
            runMode = backwardMode;          
        }
    }
*/

/*
    if( ((runMode == forwardMode) && (distanceBack > maxRange)) || ((runMode == backwardMode) && (distanceFront > maxRange)) )
    {
        Serial.println("Stop : Code -1");    
        Serial.print("runMode : :");
        Serial.println(runMode);    
        go_stop();
        //runMode = waitMode;
    }    
*/
    if( (distanceFront <= minRange) && (distanceBack <= minRange) && (distanceLeft <= minRange) && (distanceRight <= minRange) )
    {
        Serial.println("Stop : Code 00");
        Serial.print("runMode : :");
        Serial.println(runMode);
        go_stop();
    }

    else
    {
        if( (distanceFront < midRange) && runMode == forwardMode )
        {
            if( (distanceLeft <= minRange) && (distanceRight <= minRange) )
            {
                Serial.println("Transfer into Backward Mode : Code 01");
                //go_stop();
                go_backward();
                runMode = backwardMode;
            }
            else if(distanceLeft <= distanceRight)
            {
                Serial.println("Turn Right in Forward Mode : Code 02");
                go_right();
            }
            else if(distanceRight <= distanceLeft)
            {
                Serial.println("Turn Left in Forward Mode : Code 03");
                go_left();
            }
        }
        else if(runMode == forwardMode)
        {
            Serial.println("Go Forward : Code 04");
           go_forward();
            runMode = forwardMode;
        }
        else if( (distanceBack < midRange) && runMode == backwardMode )
        {
            if( (distanceLeft <= minRange) && (distanceRight <= minRange) )
            {
                Serial.println("Transfer into Forward Mode : Code 05");
                //go_stop();
                go_forward();
                runMode = forwardMode;
            }
            else if(distanceLeft <= distanceRight)
            {
                Serial.println("Turn Left in Backward Mode : Code 06");              
                go_left();
            }
            else if(distanceRight <= distanceLeft)
            {
                Serial.println("Turn Right in Backward Mode : Code 07");                            
                go_right();
            }
        }
        else if(runMode == backwardMode)
        {
            Serial.println("Go Backward : Code 08");
            go_backward();
            runMode = backwardMode;
        }
  }
  
    delay(1);
    
////////////////////////////////////////////////////
/*
    if(distance <= minRange)
    {
        Serial.println(distance);
        go_forward();
    }
    else
        go_stop();
        
    delay(50);
*/  
  /*for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  
  Serial.print("tock");

  myMotor->run(BACKWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }

  Serial.print("tech");
  myMotor->run(RELEASE);
  delay(1000);*/
}
