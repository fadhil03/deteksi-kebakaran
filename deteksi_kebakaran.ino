#include <LiquidCrystal_I2C.h>
const int led = 13;
const int led2 = 12;
const int led3 = 11;
const int  flame = A0;
const int  buzzer = 9;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int flameVar;

void setup() {;
pinMode(flame,INPUT);
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
lcd.init(); 
lcd.backlight();
Serial.begin(9600);
lcd.setCursor(0, 0);         
lcd.print("Sensor Kebakaran");        
lcd.setCursor(2, 1);         
lcd.print("ON");
delay(3000);
lcd.clear(); 
delay(2000);
}

void loop() {
int flameVar = analogRead(flame);

if (flameVar < 980){
  tone(buzzer, 700, 800);
  digitalWrite(led,HIGH);
  digitalWrite(led3,LOW);
  lcd.setCursor(4, 0);         
  lcd.print("AWAS !!!");        
  lcd.setCursor(3, 1);         
  lcd.print("KEBAKARAN"); 
  Serial.println("TERBAKAR");
  Serial.println(flameVar);
  delay(200);
  noTone(buzzer);
  digitalWrite(led,LOW);
  lcd.clear();
}
else if (flameVar < 1000){
  tone(buzzer, 600, 800);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  lcd.setCursor(0, 0);         
  lcd.print("ALARM KEBAKARAN");    
  lcd.setCursor(1, 1);         
  lcd.print("TERDETEKSI API"); 
  Serial.println("Terdeteksi Api");
  Serial.println(flameVar);
  delay(500);
  noTone(buzzer);
  digitalWrite(led2,LOW);
  lcd.clear();
} 

else{
  noTone(buzzer);
  digitalWrite(led3,HIGH);
  lcd.setCursor(0, 0);         
  lcd.print("ALARM KEBAKARAN");        
  lcd.setCursor(4, 1);         
  lcd.print("STANDBY");  
  Serial.println("AMAN");
  Serial.println(flameVar);
 
}
//  Serial.println(flameVar);
  delay(100);
 
}
