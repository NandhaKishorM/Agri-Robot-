/*
Program: Receive Integers From Raspberry Pi
File: receive_ints_from_raspberrypi_strings.ino
Description: Receive integers from a Raspberry Pi
Author: Addison Sears-Collins
Website: https://automaticaddison.com
Date: July 5, 2020
*/
// Initialize the integer variables
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


int pos = 0;
// Initialize the integer variables
int servo_0_angle = 180;
int servo_1_angle = 180;

 
// Initialize the String variables
String servo_0_angle_str = "";
String servo_1_angle_str = "";

 
int sum = 0;
 
// Get ready to accept comma-separated values
int comma_position;
 
void setup(){
   
  // Set the baud rate  
  Serial.begin(9600);
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
   
}
 
void loop(){
 
  if(Serial.available() > 0) {
 
    // Read string until the new line character
    String data = Serial.readStringUntil('\n');
 
    // There are 2 integers we will be receiving from the
    // Raspberry Pi
 
    // Integer 0
    comma_position = data.indexOf(',');   
    servo_0_angle_str = data.substring(0,comma_position);
    servo_0_angle = servo_0_angle_str.toInt();
    data = data.substring(comma_position+1, data.length());
 
    // Integer 1
    comma_position = data.indexOf(',');   
    servo_1_angle_str = data.substring(0,comma_position);
    servo_1_angle = servo_1_angle_str.toInt();
    data = data.substring(comma_position+1, data.length());

 
    // Compute a sum to prove we have integers
    sum = servo_0_angle + servo_1_angle;
 
    // We do println to add a new line character '\n' at the end
    // of the comma-separated stream of integers
    // The stuff below is ready by the Raspberry Pi
    Serial.print(servo_0_angle); Serial.print(",");
    Serial.print(servo_1_angle); Serial.print(",");
    Serial.println(sum); 
    
    for (pos = 0; pos <=   servo_0_angle; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
     }
    for (pos = servo_1_angle; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }

   
  }
}
