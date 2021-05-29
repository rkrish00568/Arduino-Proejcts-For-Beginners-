#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
const int trigPin = 3;
const int echoPin = 2;
long time;
int distance;
void setup() {
  lcd.init();
  lcd.begin(16, 2); // Initializes the interface to the LCD display
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance= time* 0.0340 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  Serial.println(distance);
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
}
