#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 int ledPIN = 6;
 int lastMessage = 0;

  
void setup() {
   lcd.begin(16, 2);
   Serial.begin(9600);
   pinMode(ledPIN, OUTPUT);
}

void loop() {


 int brightness = map(analogRead(A1), 0, 1023, 0, 255);
 analogWrite(ledPIN, brightness);
//Serial.print("Brightness: ");
//Serial.println(brightness);
  
   if (Serial.available()) {
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) {
      int newMessage = Serial.read();
      lcd.write(newMessage);
      Serial.write(newMessage);
//      lcd.write(lastMessage);
//      int lastMessage = newMessage;

    }
  }
   }


