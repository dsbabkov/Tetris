#include "NokiaLCD.h"

NokiaLCD<7, 6, 5, 11, 13> lcd;

void setup()
{
  Serial.begin(9600);

  lcd.initialize(); // This will setup our pins, and initialize the LCD

  lcd << "Send message\nto serial\n";
}

void loop()
{
  if (!Serial.available())
  {
    return;
  }

  const char c = Serial.read();
  Serial.println(c, HEX);  
  
  lcd << c;
}

