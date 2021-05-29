#include<Arduino.h>
#include<TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display (CLK,DIO);


int count=0;

void setup()
{
 Serial.begin(9600);
 display.setBrightness(0x0f);
}

void loop()
{
  

  count++;
  display.showNumberDec(count);
  delay(100);

  if (count==9999)
  {
    count=0;
    display.clear();
    delay(1000);
    display.showNumberDec(0,true);
    delay(500);
  }
}

