#include <Servo.h> // Import Servo Library

Servo my_servo;
 

void setup() {
 my_servo.attach(12); // Assigns the my_servo to a number on the ariduino board (in this case 12)
 my_servo.write(0);
}

 void loop () {
  my_servo.write(0);
  delay(333);  
  my_servo.write(180);
  delay(333);  
 }
