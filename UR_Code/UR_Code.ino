#include <Servo.h> // Includes the Servo library

#define trigPin 7 // attach the trigPin to pin 7
#define echoPin 6 // attach the echoPin to pin 6


Servo right;// creat servo object to control
Servo left; // creat servo object to control
int duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //trigpin is set as output
  pinMode(echoPin, INPUT); // echopin is set as input
  right.attach(9); // attach the right servo to pin 9
  left.attach(8);  // attach the left servo to pin 8

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);//sets the trigpin to give low pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//sets the trigpin1 to give high pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);//sets the trigpin1 to give low pulse
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;// convert time to distance

  if (distance <= 20) { // if distance is less than or equal to 20
    if (random(10) < 5) // randomly between 1 to 5 choose wheither
      rightturn(); // to turn right
    else           //
      leftturn(); // turn left
    delay(200);   // dellay for 200 milliseconds
    Serial.println(distance);
  } else {  // if distance is not less than or equal to 20 
    drive(); // drive forwaeds
  }
}


void drive() {
  right.write(20);//sets the servo to scaled direction (20)
  left.write(110);//sets the servo to scaled direction (110)
}

void rightturn() {
  right.write(110);//sets the servo to scaled direction (110)
  left.write(110);//sets the servo to scaled direction (110)
}

void leftturn() {
  right.write(20);//sets the servo to scaled direction (20)
  left.write(20);//sets the servo to scaled direction (20)
}
