#include <SoftwareSerial.h>
#include <Servo.h>


//Define hc-05 bluetooth module
SoftwareSerial BTSerial(10,11);


//Camera Bracket
int pos1 = 0;
Servo servo_13;

int pos2 = 0;
Servo servo_12;

//Motors A
int motorApin1= 6;
int motorApin2= 5;
int ENmotorA = 7;

//Motors B

int motorBpin1= 4;
int motorBpin2 = 3;
int ENmotorB= 2;

// Define Speed

int speed=210;
int forwardSpeed=120;

String message="";


void setup()
{

  Serial.begin(9600); // set the baud rate for the USB serial connection
  BTSerial.begin(9600);
  BTSerial.setTimeout(10);
  pinMode(motorApin1, OUTPUT);
  pinMode(motorApin2, OUTPUT);
  pinMode(ENmotorA, OUTPUT);

  pinMode(motorBpin1, OUTPUT);
  pinMode(motorBpin2, OUTPUT);
  pinMode(ENmotorB, OUTPUT);

  servo_13.attach(13, 500, 2500);
  servo_12.attach(12, 500, 2500);

  servo_12.write(50);
  
}





void moveForward() {
      digitalWrite(motorApin1, HIGH);
      digitalWrite(motorApin2, LOW);
      digitalWrite(motorBpin1, HIGH);
      digitalWrite(motorBpin2, LOW);
      analogWrite(ENmotorA, forwardSpeed);
      analogWrite(ENmotorB, forwardSpeed);
}

void moveBackward() {
      digitalWrite(motorApin1, LOW);
      digitalWrite(motorApin2, HIGH);
      digitalWrite(motorBpin1, LOW);
      digitalWrite(motorBpin2, HIGH);
      analogWrite(ENmotorA, forwardSpeed);
      analogWrite(ENmotorB, forwardSpeed);
}

void turnLeft() {
      digitalWrite(motorApin1, LOW);
      digitalWrite(motorApin2, LOW);
      digitalWrite(motorBpin2, LOW);
      digitalWrite(motorBpin1, HIGH);
      analogWrite(ENmotorB, speed);
}

void turnRight() {
      digitalWrite(motorApin1, HIGH);
      digitalWrite(motorApin2, LOW);
      digitalWrite(motorBpin1, LOW);
      digitalWrite(motorBpin2, LOW);
      analogWrite(ENmotorA, speed);
}

void reverseRight() {
      digitalWrite(motorApin1, LOW);
      digitalWrite(motorApin2, HIGH);
      digitalWrite(motorBpin1, LOW);
      digitalWrite(motorBpin2, LOW);
      analogWrite(ENmotorA, speed);
}

void reverseLeft() {
      digitalWrite(motorApin1, LOW);
      digitalWrite(motorApin2, LOW);
      digitalWrite(motorBpin2, HIGH);
      digitalWrite(motorBpin1, LOW);
      analogWrite(ENmotorB, speed);
}

void stopMotors() {
      digitalWrite(motorApin1, LOW);
      digitalWrite(motorApin2, LOW);
      digitalWrite(motorBpin1, LOW);
      digitalWrite(motorBpin2, LOW);
      analogWrite(ENmotorA, 0);
      analogWrite(ENmotorB, 0);
}

void loop() 
{



  /* if(BTSerial.available()>0)
    {
      
      Serial.print("Received from Bluetooth: ");
      Serial.print(BTSerial.read());
      Serial.print('\n');
    } */
   
  
    

//test 4

while(BTSerial.available())
{

  
  message=BTSerial.readString();
  char msg=message.charAt(0);
  Serial.println(msg);
  
  if(msg=='F')
{
  
  moveForward();
 delay(200);
 stopMotors();
  
  
}
  else if(msg=='S')
{
  
  stopMotors();
  
}
else if(msg=='B')
{
  
  moveBackward();
  delay(200);
  stopMotors();

}
else if(msg=='L')
{
  turnLeft();
  delay(300);
  //delay(200);
  stopMotors();
  

}
else if(msg=='R')
{
  turnRight();
  delay(300);
  //delay(200);
  stopMotors();
  

}
else if(msg=='K')
{
  reverseRight();
  delay(300);
  //delay(200);
  stopMotors();
  
}
else if(msg=='Q')
{
  reverseLeft();
  delay(300);
  //delay(200);
  stopMotors();
}




} 








  




  if(Serial.available())
  {
    BTSerial.write(Serial.read());
  }
  // BTSerial.println("Nirvanaa");

    delay(500); 


  
}
