#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
#include "DHT.h"
int offset_x = 4;
int offset_y = 2;
int DHTPIN = 2;                       //setpin of DHT at D4
//////กำหนดค่าอื่นๆ define sth //////////////
int DHTTYPE = DHT11;                  //set Dht Type 
DHT dht(DHTPIN, DHTTYPE);             //define DHT type and pin
void setup()
{
  Wire.begin();  
  oled.init();                                                     // Initialze SSD1306 OLED display
  oled.clearDisplay();
  dht.begin();// Clear screen
  
}

void loop()
{
  float h = dht.readHumidity();      //Read Humidity
  float t = dht.readTemperature();   //Read Temperature
  Serial.print("TEMPERATURE : ");
  Serial.println(t);
  Serial.print("HUMIDITY    : ");
  Serial.println(h);
  Serial.println("--------------------------");
  oled.setTextXY( 0 +(offset_y)  ,  0 +(offset_x) );              // Set cursor position, start of line 0
  oled.putString("T :"+String(t));
  oled.setTextXY( 1 +(offset_y)  ,  0 +(offset_x) );
  oled.putString("H :"+String(h)); 
  delay(1000);
}
