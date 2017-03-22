/*
 * OPTO +ve to R and to 5V
 * OPTO -ve to gnd
 * R to D11
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13,OUTPUT);pinMode(49,OUTPUT);pinMode(50,INPUT);
  digitalWrite(49,HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(50);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(sensorValue);
  if(sensorValue <1){
    digitalWrite(13,HIGH);
    Serial.println("OPTO WORKING");
  }
  
}
