#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
int offset_x = 2;
int offset_y = 4;
void setup()
{
  Wire.begin();  
  oled.init();                                                     // Initialze SSD1306 OLED display
  oled.clearDisplay();                                             // Clear screen
  oled.setTextXY( 0 +(offset_x)  ,  0 +(offset_y) );              // Set cursor position, start of line 0
  oled.putString("Hello");
}

void loop()
{
}
