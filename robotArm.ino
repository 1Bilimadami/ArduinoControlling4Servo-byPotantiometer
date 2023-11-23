//Ek-8 ) Robotun Sıçramalarını Önlemek İçin Yapılan Optimize Yazılım

//This software is for making robotic arm by controlling 4 servo motor -HakanAtes

#include<Servo.h>

Servo servom1;
Servo servom2;
Servo servom3;
Servo servom4; // creating 4 servo object

int potansPin1 = A0;
int potansPin2 = A1;
int potansPin3 = A2;
int potansPin4 = A3; // potantiometer variables for their connecting pins to Arduino

int pozisyon1 = 0;
int pozisyon2 = 0;
int pozisyon3 = 0;
int pozisyon4 = 0; // creating variables for positions of servos

voidsetup() {

servom1.attach(9);
servom2.attach(10);
servom3.attach(11);
servom4.attach(3); //connecting pins of servos to arduino
{
Serial.begin(9600); } }

voidloop() {

int deger1 = analogRead(potansPin1);
int deger2 = analogRead(potansPin2);
int deger3 = analogRead(potansPin3);
int deger4 = analogRead(potansPin4); //Potantiometer Reading

pozisyon1 = map(deger1, 0, 1023, 45, 135);
pozisyon2 = map(deger2, 0, 1023, 50, 77);
pozisyon3 = map(deger3, 0, 1023, 60, 120);
pozisyon4 = map(deger4, 0, 1023, 75, 115); //scaling analog values to angles of servos

Serial.println(pozisyon1); Serial.print("-");
Serial.print(pozisyon2); Serial.print("-");
Serial.print(pozisyon3); Serial.print("-");
Serial.print(pozisyon4); Serial.print("-"); //debugging with serial monitor

servom1.write(pozisyon1);
servom2.write(pozisyon2);
servom3.write(pozisyon3);
servom4.write(pozisyon4); //servo motions as positions variables

delay(200); //it is for precaution

}