////นำเข้า ชุดคำสั่ง import libary/////
#include <Arduino.h>
#include "DHT.h"
///////define pin กำหนดขา/////
int DHTPIN = 2;          //setpin of DHT at D4
//////กำหนดค่าอื่นๆ//////////////
int DHTTYPE = DHT11;                  //set Dht Type 
DHT dht(DHTPIN, DHTTYPE);             //define DHT type and pin
void setup() 
{
  Serial.begin(115200);
  dht.begin();                        //start DHT
}

void loop() 
{
  float h = dht.readHumidity();      //Read Humidity
  float t = dht.readTemperature();   //Read Temperature
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("FaiLed to read from DHT");
  } 
  else 
  {
    Serial.print("TEMPERATURE : ");
    Serial.println(t);
    Serial.print("HUMIDITY    : ");
    Serial.println(h);
    Serial.println("--------------------------");
    delay(1000);
  }

}
