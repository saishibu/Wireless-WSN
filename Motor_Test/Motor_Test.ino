const int LEFTEN = 3;
const int LEFT1 = 4;
const int LEFT2 = 5;

const int RIGHTEN = 6;
const int RIGHT1 = 7;
const int RIGHT2 = 8;
int SENSORLEFT = 12;
 int SENSORRIGHT = 13;


void setup() {
  // put your setup code here, to run once:
pinMode(LEFTEN,OUTPUT);
pinMode(LEFT1,OUTPUT);
pinMode(LEFT2,OUTPUT);
pinMode(RIGHTEN,OUTPUT);
pinMode(RIGHT1,OUTPUT);
pinMode(RIGHT2,OUTPUT);
pinMode(SENSORLEFT,INPUT);
pinMode(SENSORRIGHT,INPUT);
Serial.begin(115200);
}

void loop() {
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


