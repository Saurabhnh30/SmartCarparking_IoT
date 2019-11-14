#include <Servo.h>
const int analogInPin5 = A5;
int sensorrValue = 0;
int servooPin = 8;

int out1 = 2;
int out2 = 3;
int out3 = 4;
int out4 = 5;

Servo servoo;

void setup() 
{
servoo.attach(servooPin = 8);
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(A3, INPUT);

 pinMode(out1, OUTPUT);
 pinMode(out2, OUTPUT);
 pinMode(out3, OUTPUT);
 pinMode(out4, OUTPUT);
}

void loop() 
{
  int detect0 = digitalRead(A0);
  int detect1 = digitalRead(A1);
  int detect2 = digitalRead(A2);
  int detect3 = digitalRead(A3);
 
  { 
   sensorrValue = analogRead(analogInPin5);
   
    if (sensorrValue <600) // entrance Gate
      {
        for (int j=0;j<=90;j++)
          {
            servoo.write(j);
            delay(30);
          }
        delay(3000);
      }
 } 
   
 if(sensorrValue >600)
  {
  for (int j=90;j>0;j--)
    servoo.write(j);
    delay(60);
  }
   
 if(detect0 == LOW)               // IR 0
  {
    Serial.println("Obastacle on the way 0 "); 
   digitalWrite(out1,0);
  }
  else
  {
    Serial.println("All clear 0");
     digitalWrite(out1,1);  
  }
  delay(300);   
  
  if(detect1 == LOW)              // IR 1
  {
    Serial.println("Obastacle on the way 1 "); 
   digitalWrite(out2,0);
  }
  else
  {
    Serial.println("All clear 1");
     digitalWrite(out2,1);  
  }
  delay(300);  

  if(detect2 == LOW)            // IR 2
  {
    Serial.println("Obastacle on the way 2 "); 
   digitalWrite(out3,0);
  }
  else
  {
    Serial.println("All clear 2");
     digitalWrite(out3,1);  
  }
  delay(300);

   if(detect3 == LOW)            // IR 3
  {
    Serial.println("Obastacle on the way 3 "); 
   digitalWrite(out4,0);
  }
  else
  {
    Serial.println("All clear 3");
     digitalWrite(out4,1);  
  }
  delay(300);

}
