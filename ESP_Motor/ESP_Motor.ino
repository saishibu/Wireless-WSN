#include "SoftwareSerial.h"

SoftwareSerial esp(10, 11); //defining a software port on Arduino to connect the ESP-01 WiFi Modules  (rx,tx)

const int LEFTEN = 3;
const int LEFT1 = 4;
const int LEFT2 = 5;

const int RIGHTEN = 6;
const int RIGHT1 = 7;
const int RIGHT2 = 8;
int SENSORLEFT = 12;
int SENSORRIGHT = 13;


void setup() {
  //ESP Setup

  Serial.begin(115200);
  Serial.write("start.....\n");
  esp.begin(115200);
  esp.write("AT+RST\r\n"); //Reset the old settings in ESP-01
  Serial.write(esp.read());
  delay (1000);
  esp.write("ATE0\r\n"); //Disable ECHO
  delay (1000);
  esp.write("AT+CWMODE=2\r\n"); // Set as Access Point Mode
  delay(1000);
  esp.write("AT+CIFSR\r\n"); //Get Server IP and MAC Address
  delay(1000);
  esp.write("AT+CIPMUX=1\r\n");//Set for Multiple Client connection
  delay(1000);
  esp.write("AT+CIPSERVER=1,80\r\n"); //Set as server mode and make a port
  delay(1000);

  //Motor Setup
pinMode(LEFTEN,OUTPUT);
pinMode(LEFT1,OUTPUT);
pinMode(LEFT2,OUTPUT);
pinMode(RIGHTEN,OUTPUT);
pinMode(RIGHT1,OUTPUT);
pinMode(RIGHT2,OUTPUT);
pinMode(SENSORLEFT,INPUT);
pinMode(SENSORRIGHT,INPUT);
Serial.begin(115200);
 //charging IR setup
 pinMode(50,INPUT);
 digitalWrite(50,HIGH);

}

void loop() {
  
  if (esp.available()) //to detect nodes
  
  {
    char c = esp.read(); //reading the data received from Client
     Serial.write(c);
    if(esp.find("IPD")) { Serial.println("Node call"); }
    delay(3000);
    STOP();}
    else {motor();}
    }
  

void FRONT() {
  // put your main code here, to run repeatedly:

digitalWrite(LEFTEN,HIGH);//EN HIGH
digitalWrite(LEFT1,HIGH);//LEFT1 HIGH
digitalWrite(LEFT2,LOW);//LEFT2 LOW
digitalWrite(RIGHTEN,HIGH);//EN HIGH
digitalWrite(RIGHT1,HIGH);//LEFT1 HIGH
digitalWrite(RIGHT2,LOW);//LEFT2 LOW
}

void LEFT() {
  // put your main code here, to run repeatedly:

digitalWrite(LEFTEN,LOW);//LEFT EN LOW
digitalWrite(LEFT1,HIGH);//LEFT1 HIGH
digitalWrite(LEFT2,LOW);//LEFT2 LOW
digitalWrite(RIGHTEN,HIGH);//EN HIGH
digitalWrite(RIGHT1,HIGH);//LEFT1 HIGH
digitalWrite(RIGHT2,LOW);//LEFT2 LOW
}



void RIGHT() {
  // put your main code here, to run repeatedly:

digitalWrite(LEFTEN,HIGH);//LEFT EN LOW
digitalWrite(LEFT1,HIGH);//LEFT1 HIGH
digitalWrite(LEFT2,LOW);//LEFT2 LOW
digitalWrite(RIGHTEN,LOW);//EN HIGH
digitalWrite(RIGHT1,HIGH);//LEFT1 HIGH
digitalWrite(RIGHT2,LOW);//LEFT2 LOW
}

void STOP() {
  digitalWrite(LEFTEN,LOW);//LEFT EN LOW
  digitalWrite(RIGHTEN,LOW);//LEFT EN LOW
  digitalWrite(LEFT1,LOW);//LEFT1 HIGH
digitalWrite(LEFT2,LOW);//LEFT2 LOW
digitalWrite(RIGHT1,LOW);//LEFT1 HIGH
digitalWrite(RIGHT2,LOW);//LEFT2 LOW


}

void motor() {  
  int SLV=digitalRead(SENSORLEFT);
  int SRV=digitalRead(SENSORRIGHT);
  Serial.println( SLV);Serial.println( SRV);
  
  if(SLV ==1 && SRV==1)
  {
    
    Serial.print("front");
    FRONT();
    }
    if(SLV ==0 && SRV==1)
  {
        Serial.print("left");
    LEFT();
    }
    if(SLV ==1 && SRV==0)
  {
        Serial.print("right");
    RIGHT();
    }
if(SLV ==0 && SRV==0)
  {
        Serial.print("stop");
    STOP();
    }
  
}
  


