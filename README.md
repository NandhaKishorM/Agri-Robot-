# Agri robot using openCV OAK-D, NVIDIA Jetson Nano, Arduino powered by deep learning
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1_K5FxxWU_yEn9JHKa6AOHjoY5Z5Prclv?usp=sharing)
# Demo
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/lSZ1eWDyfjs/0.jpg)](https://www.youtube.com/watch?v=lSZ1eWDyfjs)

# Agri Robot snapshots
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_151716.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133147.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133209.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_135119.JPG)

![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133056.jpg)
# Training the model using colab and coverting to openVINO model
use this colab link 
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1_K5FxxWU_yEn9JHKa6AOHjoY5Z5Prclv?usp=sharing)
The model is found in pest-detection folder
## Running the model 
1. git clone https://github.com/luxonis/depthai
2. install dependencies
3. move the folder in resources/nn directory and run
```
`python3 depthai.py -dd -cnn pest-detection
```
# arduino programming and inverese kinematics
## the robotic arm arduino code
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133542.JPG)

```
 // Initialize the integer variables
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

Servo myservo1;
int pos = 0;
// Initialize the integer variables
int servo_0_angle = 90;
int servo_1_angle = 90;
int counter =0;
 
// Initialize the String variables
String servo_0_angle_str = "";
String servo_1_angle_str = "";

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
int sum = 0;
 
// Get ready to accept comma-separated values
int comma_position;
 
void setup(){
   
  // Set the baud rate  
  Serial.begin(9600);
   myservo.attach(3);
   myservo1.attach(2);
   
}
 
void loop(){
 
  if(Serial.available() > 0) {
 
    // Read string until the new line character
    String data = Serial.readStringUntil('\n');
 
    // There are 6 integers we will be receiving from the
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
     Serial.print("steps:");
  Serial.println(counter);
  counter++;
  
    Serial.println(sum); 
   
      
   
 
    myservo.write(servo_0_angle);   
    delay(500);
              
    myservo.write(-servo_0_angle);   
    delay(500);
    myservo1.write(servo_1_angle);
    delay(500);      
    myservo1.write(-servo_1_angle);  
        delay(5000);   
    
             

    }
  }
```


