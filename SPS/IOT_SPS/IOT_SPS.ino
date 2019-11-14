#include <Servo.h>
#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 11 
#define DIO 12
#define TEST_DELAY   2000
TM1637Display display(CLK, DIO);

const int analogInPin5 = A5; // entry Gate IR
const int analogInPin4 = A4; // Exit Gate IR
int sensorrValue = 0;
//int sensorrValue1 = 1;
int servooPin1 = 8; // entry servo 
int servooPin2 = 9; //exit servo

int out1 = 1; //led
int out2 = 2; //led
int out3 = 3; //led
int out4 = 4; //led

const int trigger=6; // ult
const int echo=7;
int buzzer = 13;
float duration,inches,cm;

int count=0;
Servo servoo ;
Servo servoo1 ;

void setup() 
{
 Serial.begin(9600);
 
servoo.attach(servooPin1 = 8); //enrty 8
pinMode(analogInPin5, INPUT);  // entry IR analogInPin5 (A5)

servoo1.attach(servooPin2 = 9); //exit 9
pinMode(analogInPin4, INPUT);  // exit IR analogInPin4 (A4)

 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(A3, INPUT);

 pinMode(out1, OUTPUT);
 pinMode(out2, OUTPUT);
 pinMode(out3, OUTPUT);
 pinMode(out4, OUTPUT);


   pinMode(trigger,OUTPUT);
   pinMode(echo,INPUT);
   pinMode(buzzer, OUTPUT);
   
}

void loop() 
{
  int detect0 = digitalRead(A0);
  int detect1 = digitalRead(A1);
  int detect2 = digitalRead(A2);
  int detect3 = digitalRead(A3);
  
  int detect5 = digitalRead(A5); //enrty  analogInPin5
  int detect6 = digitalRead(A4); //Exit analogInPin4
  
  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };

  
//********************************************************************************************************* 
  sensorrValue = analogRead(analogInPin5); // IR sensor Enrty gate
   if (sensorrValue <600) // entrance Gate
      {
        for (int j=0;j<=90;j++)
          {
            servoo.write(j);
            delay(30);
            Serial.print("Servo working 1");
          }
        delay(3000);
      }
  
   
 if(sensorrValue >600)
  {
  for (int j=90;j>0;j--)
    servoo.write(j);
    Serial.println("Servo working try 2 ");
    delay(60);
  }
//*********************************************************************************************************

  
//*********************************************************************************************************
display.showNumberDec(count);
//*********************************************************************************************************


//*********************************************************************************************************
int sensorrValue1 = analogRead(analogInPin4); // IR sensor Enrty gate
   if (sensorrValue1 > 600) // entrance Gate
      {
        for (int i=0;i<=90;i++)
          {
            servoo1.write(i);
            delay(30);
            Serial.print("Servo working 2 ");
          }
        delay(3000);
      }
 if(sensorrValue1 <600)
  {
  for (int i=90;i>0;i--)
    servoo1.write(i);
    Serial.println("Servo working try 2 ");
    delay(60);
  }

  if(detect6 != LOW)               // IR 5
  {
    Serial.println("Obastacle on the way exit "); 
    display.setSegments(data);
    count--;
    delay(TEST_DELAY);
 }
  else
  {
//    Serial.println("All clear 0");
//    display.setSegments(data);
//    display.showNumberDec(2);
//    delay(TEST_DELAY); 
  }
//*********************************************************************************************************  

//*********************************************************************************************************
if(detect5 == LOW)               // IR 5
  {
    Serial.println("Obastacle on the way Gate "); 
    display.setSegments(data);
    count++;
    delay(TEST_DELAY);
 }
  else
  {
//    Serial.println("All clear 0");
//    display.setSegments(data);
//    display.showNumberDec(2);
//    delay(TEST_DELAY); 
  }
//********************************************************************************************************* 




//*********************************************************************************************************   
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
//*********************************************************************************************************

//**********************************************************************************************************
digitalWrite(trigger,LOW);
   delayMicroseconds(100);
   digitalWrite(trigger,HIGH);
   delayMicroseconds(100);
   digitalWrite(trigger,LOW);
   pinMode(echo,INPUT);
   duration=pulseIn(echo,HIGH);
   cm=(duration/2)/29.1;
  inches=(duration/2)/74;

  if(inches <= 0.70)
  {
   
    tone(buzzer, 1000,1000);
    }
   else
   {
   
     noTone(buzzer);
    } 

      Serial.print("Duration:");
       Serial.print(inches);
        Serial.print(" inches ");
         Serial.print(cm);
          Serial.println(" cm");
          delay(1000);
//*************************************************************************************************************
  

}
