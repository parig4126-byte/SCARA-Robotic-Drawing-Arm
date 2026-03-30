#include <Servo.h>

Servo s1, s2;

// Apne robot ki arms ki lambai (cm) yahan likhein
const float L1 = 10.0; 
const float L2 = 12.0; 

void setup() {
  Serial.begin(9600);
  s1.attach(10); // Shoulder
  s2.attach(11); // Elbow
  
  // Shuruat mein robot ko ek safe position par rakhein
  moveRobotIK(15, 5); 
}

void moveRobotIK(float x, float y) {
  float d = sqrt(x*x + y*y);
  
  // Agar point reach se bahar hai toh ruk jayein
  if (d > (L1 + L2) || d < abs(L1 - L2)) return; 

  float a = acos((L1*L1 + d*d - L2*L2) / (2 * L1 * d));
  float b = acos((L1*L1 + L2*L2 - d*d) / (2 * L1 * L2));
  float phi = atan2(y, x);

  // Angles calculate karna
  int angleS = (phi + a) * 180.0 / PI;
  int angleE = b * 180.0 / PI;
  
  // Servo limits (0-180) check karna
  if(angleS >= 0 && angleS <= 180 && angleE >= 0 && angleE <= 180) {
    s1.write(angleS);
    s2.write(angleE);
  }
}

void loop() {
  if (Serial.available() > 0) {
    // Processing se "X,Y\n" data padhna
    String data = Serial.readStringUntil('\n');
    int commaIndex = data.indexOf(',');
    
    if (commaIndex != -1) {
      String xStr = data.substring(0, commaIndex);
      String yStr = data.substring(commaIndex + 1);
      
      float targetX = xStr.toFloat();
      float targetY = yStr.toFloat();
      
      // Scale coordinates (Processing ki badi screen ko robot ki choti reach mein badalna)
      // Screen 600px ki hai toh hum 20-25cm tak map karenge
      float mappedX = map(targetX, 0, 600, -15, 15);
      float mappedY = map(targetY, 0, 600, 20, 0); 
      
      moveRobotIK(mappedX, mappedY);
    }
  }
}




//processing aap ke liye code 


import processing.serial.*;

Serial myPort;

void setup() {
  size(400, 400); // Ek window khulegi drawing ke liye
  background(255);
  
  // Apne Arduino ka port select karein. Agar error aaye to 0 ko 1 karke dekhein
  String portName = Serial.list()[0]; 
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (mousePressed) {
    stroke(0);
    line(pmouseX, pmouseY, mouseX, mouseY); // Screen par line dikhegi
    
    // Mouse ki position Arduino ko bhej rahe hain
    myPort.write(int(map(mouseX, 0, width, 0, 255)));
    myPort.write(int(map(mouseY, 0, height, 0, 255)));
  }
}

void keyPressed() {
  background(255); // Keyboard ki koi bhi key dabane se screen saaf ho jayegi
}

