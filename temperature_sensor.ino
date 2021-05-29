#include<LiquidCrystal_I2C.h>
const int sensor=A0; 
float tempc;  
float vout;  

LiquidCrystal_I2C lcd(0x27 ,16, 2);

void setup()
{
pinMode(sensor,INPUT);
pinMode(2,OUTPUT);
Serial.begin(9600);
lcd.init();
lcd.backlight();

}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; 
Serial.println(tempc);
lcd.setCursor(0,0);
lcd.print("Temp=       C");
lcd.setCursor(6,0);
lcd.print(tempc);



delay(1000); //Delay of 1 second for ease of viewing 
}
