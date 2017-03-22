/*===================================================================== 
Version 1.0b
TCP communication between two ESP8266/NodeMCU with Arduino Firmware
This is the client program
Date:10/03/2017
=======================================================================*/
#include <ESP8266WiFi.h>
int i=0;
char* ssid= "ESPsai"; //WiFi SSID (Will be changed later)
char* password= "12345678"; //WiFi password

int port =80; //Server port address where the client connects and talks
WiFiServer ESPServer(); //defining a server named ESPServer
char * host = "192.168.4.1"; // ip of Server
WiFiClient NodeMCU1; //defining a client named NodeMCU1 (Client Name = NodeMCU, ID=1)

const int photo=4; 
void setup() {
  pinMode(photo,INPUT);//Connect Photodiode to D2 of NodeMCU
  
  Serial.begin(115200);
  pinMode(2,OUTPUT);  
  
  delay(15000);
  
  WiFi.mode(WIFI_STA); //Station Mode (Client Mode) in NodeMCU or ESP-01
  WiFi.begin(ssid,password); //Connecting to Server/access point)
 
  Serial.println("connecting to " + WiFi.SSID());
  
  while (WiFi.status() != WL_CONNECTED) {
  Serial.println("Trying to connect");
    delay(5000);
    }
  
  Serial.println("WiFi Connected");
  Serial.println("Signal Strength = " + String(WiFi.RSSI())+" dBm"); //Just to get signal strength
  Serial.print("ServerIP: "); Serial.println(host); //Printing Server IP address
  Serial.print("Port: "); Serial.println(port); //Printing Server Port address
  Serial.print("Client IP: ");Serial.println(WiFi.localIP()); //Printing Client IP assigned by the DHCP

}

void loop() {
  
  if(digitalRead(photo));
  {
    charge();
    }
    else {Serial.println("Waiting for charger....");}
  
  digitalWrite(2,HIGH);//Onboard LED ON if there ESP is connected
  
  
  NodeMCU1.stop(); //Reset previous connections
  if(NodeMCU1.connect(host,port)) //checking if client is connected to server
  
  {
    Serial.println ("Connected to server");
     //Serial.println(i);
  NodeMCU1.println("N1");delay(60000); //Sends message and waits for a min
  //NodeMCU1.println("N2");delay(60000);
  //NodeMCU1.println("N3");delay(60000); //Sending a message to server. This message can be anything like Battery SOC or request for charging or any data transfer to server
  
  digitalWrite(2,LOW); //Onboard LED OFF if there is no connection
  
  }
 else
 {
  //Serial.write("No communication");
  delay(1000);
  }
  
  NodeMCU1.flush(); //closing the connection to server 
  delay(10000); //wait for 10 sec (Can be more too if req) to connect to server again

}

void charge()
{
  Serial.println("Charging.....");
  }
