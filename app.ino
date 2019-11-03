#include <Adafruit_Sensor.h>

#include <Adafruit_LIS3DH.h>
#include <SoftwareSerial.h>


SoftwareSerial blueTooth(10, 11);

#define button0 8
#define button1 9

#define btVCC 13
#define btGND 12


Adafruit_LIS3DH sensor;

void setup()
{
	Serial.begin(9600);
	blueTooth.begin(9600);
	pinMode(button0, INPUT);
	pinMode(button1, INPUT);

	sensor.begin();

	pinMode(btVCC, OUTPUT);
	pinMode(btGND, OUTPUT);
	digitalWrite(btVCC, 1);
	digitalWrite(btGND, LOW);
}

void loop()
{
	// put your main code here, to run repeatedly:
	int finger0 = digitalRead(button0);
	int finger1 = digitalRead(button1);
	Serial.write("x : ");
	Serial.write(sensor.x);
	Serial.write("\n");
	Serial.write("y : ");
	Serial.write(sensor.y);
	Serial.write("\n");
	Serial.write("z : ");
	Serial.write(sensor.z);
	Serial.write("\n");

	if (blueTooth.available())
		Serial.write(blueTooth.read());
	//if(Serial.available())
	//bt.write(Serial.read());

	if (finger0 == HIGH && finger1 == LOW)
		blueTooth.write("1;0;1;1;0;\n");
	else if (finger0 == LOW && finger1 == HIGH)
		blueTooth.write("1;0;0;1;1;\n");
	else if (finger0 == HIGH && finger1 == HIGH)
		blueTooth.write("1;0;1;1;1;\n");
	else
		blueTooth.write("1;0;0;1;0;\n");

	delay(45);
}
