# Agri robot using openCV OAK-D, NVIDIA Jetson Nano, Arduino powered by deep learning
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1_K5FxxWU_yEn9JHKa6AOHjoY5Z5Prclv?usp=sharing)
# Demo video
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/lSZ1eWDyfjs/0.jpg)](https://www.youtube.com/watch?v=lSZ1eWDyfjs)
## Project report link: https://drive.google.com/file/d/1x037wt5zMpPY5sJrARwPup604T6NJgay/view?usp=sharing

# Agri Robot snapshots
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_151716.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133147.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133209.JPG)
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_135119.JPG)

![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133056.jpg)
# Training the model using colab and coverting to openVINO model
use this colab link 
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1_K5FxxWU_yEn9JHKa6AOHjoY5Z5Prclv?usp=sharing)

The resulting models are found in pest-detection folder.
## Running the model 
1. git clone https://github.com/luxonis/depthai
2. install dependencies.
3. move the pest-detection folder in resources/nn directory.
4. move the depthai.py from scripts directory to the cloned directory, and also move the script mobilenet_ssd_handler.py from depthai_helpers to cloned directory depthai_helpers.
and run
```
`python3 depthai.py -dd -cnn pest-detection

```
5. The changes include taking the x,y,z location from mobilenet_ssd_handler.py. From depthai.py, calculating the servo rotation angle using inverese kinematics. sending the angle data to the arduino using serial communication.
# Arduino programming and inverese kinematics
## The robotic arm
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133542.JPG)

### Inverese kinematics
![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/Screenshot%20from%202020-10-31%2001-30-34.png)

Th arduino codes are found under the scripts/arduino folder. Use the arduino file under communication. That is communication.ino to control the robotic arm. We used Arduino Mega for the control.
## The Z axis motion, rail system

![alt text](https://github.com/kishorkuttan/Agri-Robot-/blob/master/IMG_20201101_133256.JPG)

 Use the arduino file under communication. That is stepper.ino to control the rail system. We used seperate arduino UNO for the control.
### Agri robot using OAK-D

- [x] Build a robotic arm and stepper controll system.
- [x] Trained a pest detection model using SSD mobilenet and converted it to a openVINO model.
- [x] Build 2 program one to move the system in z axis using stepper motor and other to move the arm. These two programs work asynchronously.
- [ ] Rover movement controll.
- [ ] pesticide spraying mechanism synchronous with the arm.
- [ ] Field testing and eliminate all the wires. We didn't eliminate the OAK-D powering cord due to the power need for the module.



