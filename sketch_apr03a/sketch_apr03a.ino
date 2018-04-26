#include <Servo.h>
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int S0= A0;
int S1= A1;
int S2= A2;
int S3= A3;
int Out= A4;


Servo topServo;
Servo bottomServo;

int frequency = 0;
void setup() {
   lcd.begin(16, 2);
   lcd.setCursor(0,0);
   lcd.print("Sorting Machine");
   delay(1500);
   lcd.clear();
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Out, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(6);
  bottomServo.attach(5);

  Serial.begin(9600);
}
int GREEN=0;
int YELLOW=0;
int RED=0;
int BROWN=0;
int BLUE=0;
int ORANGE=0;
int TRASH=0;
int r;
void loop() 
{  
  


  topServo.write(10);
  delay(1500);
  topServo.write(86);
  delay(500);
 
  
  for(int i=86; i>=40; i--) {
      topServo.write(i);
      delay(2);}
    delay(500);   
    digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(Out, HIGH);
  int R = frequency;
  Serial.print("R=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(500);
  
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(Out, HIGH);
  int G = frequency;
  Serial.print("G=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(500);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(Out, HIGH);
  int B = frequency;
  Serial.print("B=");
  Serial.print(frequency);
  Serial.println("  ");
  delay(500);
  
  if (R>=78 & R<=85 & G>=100 & G<=110)
   {
    bottomServo.write(12);
    BROWN++;
   }
  else if (G>=80 & G<=92)
   {
    bottomServo.write(25);
    GREEN++; 
   }  
  else if (B>=70 & B<=83)
   {
    bottomServo.write(38);
    BLUE++;
   }
  else if (R>=60 & R<=64)
   {
    bottomServo.write(51);
    ORANGE++;
   }
  else if (R>=50 & R<59)
   {
    bottomServo.write(64);
    YELLOW++;
   }
  else if(R>=66 & R<=72)
   {
    bottomServo.write(77);
    RED++;
   }
  else 
   {
    bottomServo.write(90);
    TRASH++;
   }
  
  for(int i=40; i>=10; i--) 
    {
      topServo.write(i);
      delay(10);
    }

        lcd.setCursor(0,0);
        lcd.print("Y=");
        lcd.print(YELLOW);
        lcd.setCursor(4,0);
        lcd.print("G=");
        lcd.print(GREEN);
        lcd.setCursor(8,0);
        lcd.print("BL=");
        lcd.print(BLUE);
        lcd.setCursor(0,1);
        lcd.print("O=");
        lcd.print(ORANGE);
        lcd.setCursor(4,1);
        lcd.print("R=");
        lcd.print(RED);
        lcd.setCursor(8,1);
        lcd.print("B=");
        lcd.print(BROWN);
        lcd.setCursor(12,1);
        lcd.print("T=");
        lcd.print(TRASH);
        

  
}
