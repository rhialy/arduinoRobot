int leftmotorForward = 8; // pin 8 --- left motor (+) green wire

int leftmotorBackward = 11; // pin 11 --- left motor (-) black wire

int leftmotorspeed = 9; // pin 9 --- left motor speed signal

int rightmotorForward = 12; // pin 12 --- right motor (+) green wire

int rightmotorBackward = 13; // pin 13 --- right motor (-) black

int rightmotorspeed = 10; // pin 10 --- right motor speed signal

//--- Speeds and Timers

int pause = 2000; //Long delay time between steps

int runtime = 5000; // How long Runtime actions will last

int slow = 230; // slow speed (of 255 max)

int fast = 255; // fast speed (of 255 max)

//------------------------------------------------------

void setup() //---6 Pins being used are outputs--- 
{

pinMode(leftmotorForward, OUTPUT);

pinMode(leftmotorBackward, OUTPUT);

pinMode(leftmotorspeed, OUTPUT);

pinMode(rightmotorForward, OUTPUT);

pinMode(rightmotorBackward, OUTPUT);

pinMode(rightmotorspeed, OUTPUT);

}

// --- Main Program Loop -----------------------------

void loop()

{

goForward();

delay(runtime);

Stop();

delay(pause);

goBackward();

delay(runtime);

}

//----- "Sub-rutine" Voids called by the main loop

void goForward()

{

analogWrite(leftmotorspeed,Fast); //Enable left motor by setting speed

analogWrite(rightmotorspeed,Fast); //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);

digitalWrite(leftmotorForward,HIGH);

digitalWrite(rightmotorForward,HIGH);

}

void goBackward()

{

analogWrite(leftmotorspeed,Slow);

analogWrite(rightmotorspeed,Slow);

digitalWrite(leftmotorForward,LOW);

digitalWrite(rightmotorForward,LOW);

digitalWrite(leftmotorBackward,HIGH);

digitalWrite(rightmotorBackward,HIGH);

}

void Stop() // Sets speed pins to LOW disabling both motors

{

digitalWrite(leftmotorspeed,LOW);

digitalWrite(rightmotorspeed,LOW);

}
