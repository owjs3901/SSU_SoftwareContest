
#include "Wire.h"
#include "SPI.h"
#include "SparkFunLIS3DH.h"

// #include <Adafruit_Sensor.h>

// #include <Adafruit_LIS3DH.h>

#include <SoftwareSerial.h>


SoftwareSerial blueTooth(10, 11);


LIS3DH sensor;

void setup()
{
  Serial.begin(9600);
  blueTooth.begin(38400);
  // pinMode(button0, INPUT);
  // pinMode(button1, INPUT);

  sensor.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // int finger0 = digitalRead(button0);
  // int finger1 = digitalRead(button1);
  Serial.print("TEST");
  float x=sensor.readFloatAccelX();
  float y=sensor.readFloatAccelY();
  float z=sensor.readFloatAccelZ();
  Serial.print("x : ");
  Serial.print(sensor.readFloatAccelX());
  Serial.print("\n");
  Serial.print("y : ");
  Serial.print(sensor.readFloatAccelY());
  Serial.print("\n");
  Serial.print("z : ");
  Serial.print(sensor.readFloatAccelZ());
  Serial.print("\n");
  if (blueTooth.available())
    Serial.write(blueTooth.read());
  if(Serial.available())
    blueTooth.write(Serial.read());
  blueTooth.write("1;0;1;1;0;");
    
  blueTooth.write(x);
  blueTooth.write(";");
  blueTooth.write(y);
  blueTooth.write(";");
  blueTooth.write(z);
  blueTooth.write(";");
  blueTooth.write("\n");

  delay(45);
}
