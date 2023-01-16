#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

int sensor = A0;
int buzzer = 2;
int touch = 9;
int value;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensor, INPUT);
pinMode(touch, INPUT);
pinMode(2, OUTPUT);

lcd.begin(16, 2);
lcd.setRGB(colorR, colorG, colorB);
lcd.print("Current Temp...!");

delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
value = analogRead(7);


if (value > 300){
lcd.setCursor(1, 1);
lcd.print("Fire Alert:");
digitalWrite(2, HIGH);
Serial.println(value);

lcd.setCursor(12, 1);
lcd.print(value);
delay(500);}
if (value < 300){
  lcd.setRGB(0, 0, 255);
  lcd.setCursor(1, 1);
  lcd.print("Feels Good:");
  digitalWrite(2, LOW);
  Serial.println(value);

lcd.setCursor(12, 1);
lcd.print(value);
delay(500);
}}
