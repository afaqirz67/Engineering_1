#include <Servo.h>

Servo myservo; // create servo object to control a servo


int switchpin= 6; // connect the anolog pin to the switch
int switchstate; // variable to read the value from the analog pin

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(switchpin, INPUT);
}

void loop()  {
  switchstate = digitalRead(switchpin);
  if (switchstate == HIGH)  { // if the switch is on move 
    Serial.println(switchstate); 
    myservo.write(0); // move the servo to o degree
    delay(15); wait 
    myservo.write(90); // move the servo to 90 degree
  } else {
    Serial.println(switchstate);
  }
  

}
