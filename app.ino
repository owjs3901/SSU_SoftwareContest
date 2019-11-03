#include <SoftwareSerial.h>

SoftwareSerial blueTooth(10,11);

#define button0 8
#define button1 9

#define btVCC 13
#define btGND 12



SoftwareSerial bt(bt_rx,bt_tx)

void setup(){
    Serial.begin(9600);
    blueTooth.begin(9600);
    pinMode(button0,INPUT);
    pinMode(button1,INPUT);

    pinMode(btVCC,OUTPUT);
    pinMode(btGND,OUTPUT);
    digitalWrite(btVCC,HIGH);
    digitalWrite(btGND,LOW);
}

void loop(){

	
}
