// --- Libraries ---------
#include <NewPing.h>

// --- Variables for sensors ---------

#define  TRIGGER_PIN  0
#define  ECHO_PIN     1
#define MAX_DISTANCE 200

int DistanceIn;
int DistanceCm;
int Spause = 100;
int measuringRuntime = 300;
bool isObstacle = false;

// --- Variables for motor shield ---------

int leftmotorForward = 8; // pin 8 --- left motor (+) green wire
int leftmotorBackward = 11; // pin 11 --- left motor (-) black wire
int leftmotorspeed = 9; // pin 9 --- left motor speed signal
int rightmotorForward = 12; // pin 12 --- right motor (+) green wire
int rightmotorBackward = 13; // pin 13 --- right motor (-) black
int rightmotorspeed = 10; // pin 10 --- right motor speed signal

int Mpause = 2000; //Long delay time between steps
int moroRuntime = 1000; // How long motor actions last
int slow = 230; // slow speed (of 255 max)
int fast = 255; // fast speed (of 255 max)

//------------------------------------------------------

void setup() { //---6 Pins being used are outputs--- 

Serial.begin(9600);
pinMode(leftmotorForward, OUTPUT);
pinMode(leftmotorBackward, OUTPUT);
pinMode(leftmotorspeed, OUTPUT);
pinMode(rightmotorForward, OUTPUT);
pinMode(rightmotorBackward, OUTPUT);
pinMode(rightmotorspeed, OUTPUT);
  
}

// --- Main Program Loop -----------------------------

void loop() {
  
goForward();
delay(motorRuntime);
measuring();
delay(measuringRuntime);
if(isObstacle == true) {
  turnLeft();
  delay(motorRuntime);
  measuring();
  delay(measuringRuntime);
}

}

// --- Methods for ultrasonic sound sensor  ---------

void measuring() {

  delay(Spause);
  DistanceCm = sonar.ping_cm();
  delay(Spause);
  if(DistanceCm < 40) {
    isObstacle = true;
  } else {
    isObstacle = false;
  }

}


// --- Methods for motor shield ---------

void turnLeft() {
  analogWrite(leftmotorspeed,Fast);
  digitalWrite(leftmotorBackward,LOW);
  digitalWrite(rightmotorBackward,LOW);
  digitalWrite(rightmotorForward,LOW);
  digitalWrite(leftmotorForward,HIGH);
}

void turnLeft() {
  analogWrite(leftmotorspeed,Fast);
  digitalWrite(leftmotorBackward,LOW);
  digitalWrite(leftmotorForward,LOW);
  digitalWrite(rightmotorBackward,LOW);
  digitalWrite(rightmotorForward,HIGH);
}



void goForward() {

analogWrite(leftmotorspeed,Fast); //Enable left motor by setting speed
analogWrite(rightmotorspeed,Fast); //Enable left motor by setting speed
digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage
digitalWrite(rightmotorBackward,LOW);
digitalWrite(leftmotorForward,HIGH);
digitalWrite(rightmotorForward,HIGH);

}

void goBackward() {

analogWrite(leftmotorspeed,Slow);
analogWrite(rightmotorspeed,Slow);
digitalWrite(leftmotorForward,LOW);
digitalWrite(rightmotorForward,LOW);
digitalWrite(leftmotorBackward,HIGH);
digitalWrite(rightmotorBackward,HIGH);

}

void Stop() { // Sets speed pins to LOW disabling both motors

digitalWrite(leftmotorspeed,LOW);
digitalWrite(rightmotorspeed,LOW);

}
