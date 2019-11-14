#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
lcd.begin(16, 2);
 lcd.backlight(); 

}
void loop() 
{
lcd.print("  ZENO MODIFF"); 
lcd.setCursor(0, 0);
delay(1500);
lcd.clear();
lcd.print("ARDUINO PROJECTS");
lcd.setCursor(0, 1);
delay(1500);
lcd.setCursor(6, 1);
lcd.print("SUBSCRIBE ");
delay(1500);
lcd.clear();
lcd.print("TO MY CHANNEL");
lcd.setCursor(0, 1);
delay(1500);
lcd.print("FOR MORE VIDEOS");
delay(1500);
lcd.clear();
}
