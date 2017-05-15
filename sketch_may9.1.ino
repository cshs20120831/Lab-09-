#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 6, 5, 4, 3); 
#include <Ultrasonic.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() 
{
   Serial.begin(9600);
   lcd.begin(16, 2); 
 }
 void loop() 
{
  String val;
   lcd.setCursor(0,0);
   float cmMsec, inMsec;
   long microsec = ultrasonic.timing();
   cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); 
      lcd.print("MS: ");
      lcd.print(microsec);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(", CM: ");  
      lcd.print(cmMsec);
      lcd.setCursor(0,1);
      lcd.print(", IN: "); 
      lcd.print(inMsec);
      delay(1000); 
 }
