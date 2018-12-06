/*
Holocron Particle Firmware V1.0
Dave Clarke
18/02/16

IR Proximty circuit modified from instructables
http://www.instructables.com/id/Simple-IR-proximity-sensor-with-Arduino
All other rights reserved.
*/

int readIR();           // prototype
void ServoControl();    // prototype
void ServoControlReset(); // prototype

Servo myservo;          // Create servo object

bool toggle = false;    // Used as a one shot
bool TheForce = false;  // Variable to know cloud function used.
bool powerON = true;    // initial start up flag

int pos = 0;            // initial servo position
int IRemitter = D1;     // IR Emiter LED on D1
int IRpin = A0;         // IR Photodiode on pin A0
int ambientIR;          // variable to store the IR coming from the ambient
int obstacleIR;         // variable to store the IR coming from the object
int value[10];          // variable to store the IR values
int distance = 0;       // variable that will tell if there is an obstacle or not
int mainLED = A6;       // control for the main lights
int closed = 20;         // Servo closed angle
int open = 155;         // servo open angle

void setup()
{
  // Initialise pin modes and assign servo pin
  myservo.attach(D0);
  pinMode(mainLED, OUTPUT);
  pinMode(IRemitter, OUTPUT);

  // Debug - Variables published to Cloud Variables
  Particle.variable("distance", distance);
  Particle.variable("ambientIR", ambientIR);
  Particle.variable("obstacleIR", obstacleIR);

  // Cloud function interface
  Particle.function("force", RemoteSwitch);

  //initial states
  digitalWrite(mainLED, LOW);
  digitalWrite(IRemitter, LOW);
  myservo.write(closed);

}

void loop()
{
  distance = readIR(10);                                      // Read value from IR sensor and store in distance Variable
  if ((distance > 15 || TheForce == true) && toggle == false) // open up lamp and turn on the lights
  {
    for(pos = closed; pos <= open; pos++)                     // goes from 5 degrees to 115 degrees
    {                                                         // in steps of 1 degree
      ServoControl(pos);                                      // Set Servo Position and Control LED Brightness
    }
      ServoControlReset();                                      // When finished, reset variables etc.
  }
  if ((distance > 15 || TheForce == true) && toggle == true)  // turn off lamp and close
  {
    for(pos = open; pos > closed; pos--)                     // goes from 115 degrees to 5 degrees
    {
      ServoControl(pos);                                      // Set Servo Position and Control LED Brightness
    }
    ServoControlReset();                                      // When finished, reset variables etc.
  }
}

// Function to read IR Proximity sensor
int readIR(int times)
{
  for(int x = 0; x < times; x++)
  {
    digitalWrite(IRemitter,LOW);    // turning the IR LEDs off to read the IR coming from the ambient
    delay(1);                       // minimum delay necessary to read values
    ambientIR = analogRead(IRpin);  // storing IR coming from the ambient
    digitalWrite(IRemitter,HIGH);   // turning the IR LEDs on to read the IR coming from the obstacle
    delay(1);                       // minimum delay necessary to read values
    obstacleIR = analogRead(IRpin); // storing IR coming from the obstacle
    value[x] = ambientIR-obstacleIR; // calculating changes in IR values and storing it for future average
  }
  for(int y = 0; y < times; y++)
  {
    distance+=value[y];              // calculating the average based on the "accuracy"
  }
  if (powerON == true)
  {
    delay(1000);                    // prevent bogus readings from servo noise on power up
    powerON = false;
  }
  else
  {
    //no start up delay
  }
  return(distance/times);            // return the final value
}

// Function for Cloud Variable Remote Switch
bool RemoteSwitch(String command)
{
  if (command == "theforce")
  {
    return TheForce = true;
  }
}

// Servo position control and LED brightness
void ServoControl(int ServoPosition)
{
  int LEDmap = ServoPosition;
  LEDmap = map(LEDmap, closed, open, 0, 255);  // Map servo position to LED brightness
  myservo.write(ServoPosition);                // tell servo to go to position in variable 'pos'
  delay(26);                                   // waits 25ms for the servo to reach the position
  analogWrite(mainLED, LEDmap);                //ramp light on using PWM Pin
}

// After servo has reached final position, reset variables and wait.
void ServoControlReset(void)
{
  toggle = !toggle;                           // toggle switch state
  TheForce = false;                           // Toggle The Force when using could remote switch on
  distance = 0;                               // reest distance to stop accidental operation
  if (toggle == false)                        // Make sure LED is High for open and low for closed
  {
      digitalWrite(mainLED, LOW);
  }
  else
  {
     digitalWrite(mainLED, HIGH);
  }
  delay(1000);                                // prevent operation too quickly
}
