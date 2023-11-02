#include <SoftwareSerial.h>

//Bluetooth Tx pin to Arduino 2
//Bluetooth Rx pin to Arduino 3
#define rxPin 2
#define txPin 3
SoftwareSerial Bluetooth(rxPin,txPin);

#define RELAY_1 8
#define RELAY_2 9

String data = "";

void setup() {
  
  pinMode(RELAY_1, OUTPUT); //Relay 1
  pinMode(RELAY_2, OUTPUT); //Relay 2
  
  Serial.begin(115200);
  Serial.println("Arduino serial initialize");
  
  Bluetooth.begin(9600);
  Serial.println("Bluetooth software serial initialize");
}

void loop() {
  
  while(Bluetooth.available() > 0){
    data = Bluetooth.readString();
    Serial.println(data);
    
    data.toLowerCase();
    //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
    //Control Light 1
    //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
    if(data == "light1 on")
      digitalWrite(RELAY_1, HIGH);
    else if(data == "light1 off")
      digitalWrite(RELAY_1, LOW);
      
    //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
    //Control Light 2
    //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
    else if(data == "light2 on")
      digitalWrite(RELAY_2, HIGH);
    else if(data == "light2 off")
      digitalWrite(RELAY_2 , LOW);
    //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
  }
}
