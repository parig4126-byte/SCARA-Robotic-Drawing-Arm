# SCARA-Robotic-Drawing-Arm
An Arduino-based 2-DOF robotic arm that mimics mouse movements from a computer screen onto paper using Inverse Kinematics and Processing IDE.

# Components Used
1. Arduino Uno
2. ​Actuators: 2x SG90 Servo Motors (Shoulder & Elbow)
3. ​Software: Arduino IDE, Processing 4.0
4. ​Power: 5V 2A Power Adapter (External)
5. Jumper wiers
6. Breadboard 

​# Circuit Connections
1. ​Shoulder Servo (joint 1) : Pin 11 (signal )
2. ​Shoulder Servo (joint 2) : 5V (VCC)
3. Shoulder Servo (joint 3) : GND (GND)
4. ​Elbow Servo (joint 1) : Pin 10 (signal)
5. ​Elbow Servo (joint 2) : 5V (VCC)
6. ​Elbow Servo (joint 3) : GND (GND)
7. External Power: 5V to Servos (Common Ground with Arduino)

​# How to Use
​1. Arduino: ' sketch_mar27plotter.ino ' ko upload karein.
2. ​Processing: DrawingPad.pde ko kholin aur apna COM port select karein.
3. ​Run: Processing mein 'Run' dabayein aur mouse se canvas par draw karein. 

