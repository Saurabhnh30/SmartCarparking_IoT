#include<Wire.h>
#include <MQ2.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Analog_Input = A0;
int buzzer = 10;
int sensorThres = 100;

int lpg, co, smoke;
MQ2 mq2(Analog_Input);
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(Analog_Input, INPUT);
  lcd.backlight();
  lcd.init();

}
void loop(){
  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();
  lcd.setCursor(0,0);
  lcd.print("LPG:");
  lcd.print(lpg);
  lcd.print(" CO:");
  lcd.print(co);
  lcd.setCursor(0,1);
  lcd.print("SMOKE:");
  lcd.print(smoke);
//  lcd.print(" PPM");
  delay(1000);

  int analogSensor = analogRead(Analog_Input);
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000,1000);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
