/*==================================================================
   Version 1.0b
   TCP Communication between two ESP8266 Module
   This is the server program
   ESP-01 connected to Arduino Mega is set as Server
   ESP-01 has Native AT Commands Firmware
   Date:10/03/2017
   ARDUINO V1.6.10
  ===================================================================*/


#include "SoftwareSerial.h"

SoftwareSerial esp(10, 11); //defining a software port on Arduino to connect the ESP-01 WiFi Modules  (rx,tx)

//#define LeftSensor 4; //Analog Pin A0 for Left Sensor
//#define RightSensor 5; //Digital Pin A1 for Right Sensor
//
//#define LeftMotor 6; //Digital Pin (PWM) 6 for Left Motor
//#define RightMotor 7; //Digital Pin (PWM) 7 for Right Motor

void setup() {
  pinMode(13, OUTPUT);
  //   pinMode(LeftMotor,OUTPUT);
  //   pinMode(RightMotor,OUTPUT);


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



}

void loop() {
  digitalWrite(13, LOW);

  if (esp.available())
  {
    char c = esp.read(); //reading the data received from Client
     Serial.write(c);
    if(esp.find("IPD")) { Serial.println("Node call"); }

     
//    int a = 0; int b = 0; int d = 0;
//    a = esp.find("N1"); b = esp.find("N2"); d = esp.find("N3");
//   // Serial.println (a); Serial.println (b); Serial.println (d); Serial.println();
//    if (a == 1)
//        {
//          Serial.println("\nCall from Node1");
//          digitalWrite(13,HIGH);
//        }
//        if(b==1)
//        {
//          Serial.println("\nCall from Node2");
//          digitalWrite(13,HIGH);
//        }
//       if(d==1)
//        {
//          Serial.println("\nCall from Node3");
//          digitalWrite(13,HIGH);
//        }
//      else { 
//        Serial.println("Waiting for Calls....");  
//}
  }
}

//void motor() //Line Follower programs. Will be added later
//{
//
//
//    digitalWrite(LeftMotor,HIGH);
//    digitalWrite(RightMotor,HIGH);
//
//    digitalWrite(LeftMotor,LOW);
//    digitalWrite(RightMotor,HIGH);
//
//    digitalWrite(LeftMotor,HIGH);
//    digitalWrite(RightMotor,LOW) ;
//
//    digitalWrite(LeftMotor,LOW);
//    digitalWrite(RightMotor,LOW);
//
//
//    }
