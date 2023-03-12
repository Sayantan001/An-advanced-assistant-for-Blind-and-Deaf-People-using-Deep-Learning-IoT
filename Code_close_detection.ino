#include <Arduino.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 6, 5, 4, 3, 2);

static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connectsto module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

int left_trigPin = 14;

int left_echoPin = 15;

int right_trigPin = 16;

int right_echoPin = 17;

int left_trigPinn = 18;

int left_echoPinn = 19;

int right_trigPinn = 9;

int right_echoPinn = 8;


void setup() {


  pinMode(left_trigPin,OUTPUT);

  pinMode(left_echoPin,INPUT);

  pinMode(right_trigPin,OUTPUT);

  pinMode(right_echoPin,INPUT);
  pinMode(left_trigPinn,OUTPUT);

  pinMode(left_echoPinn,INPUT);

  pinMode(right_trigPinn,OUTPUT);

  pinMode(right_echoPinn,INPUT);  


  Serial.begin(115200);

  
  softwareSerial.begin(9600);
  player.volume(50);
  player.begin(softwareSerial);

 
}

void loop(){

     left();

     right();

     leftt();

     rightt();


}

void left(){

  delay(50);// reading will be taken after ....miliseconds

  Serial.println("\n");

  int duration, distance;

    digitalWrite (left_trigPin, HIGH);

    delayMicroseconds (10);

    digitalWrite (left_trigPin, LOW);

    duration = pulseIn (left_echoPin, HIGH);

    distance = (duration/2) / 29.1;

    //distance= duration*0.034/2;  

    if (distance < 55) {  // Change the number for long or short distances.    

    Serial.print("Left Distance");

    Serial.print(distance);
    player.play(1);
     lcd.begin(16, 2);
   lcd.setCursor(0,0);
  lcd.print("Something at");
  lcd.setCursor(0,1);
 lcd.print("Your Frontside!!"); 
     

 

    }

}

void right(){

   delay(50);// reading will be taken after ....miliseconds

   Serial.println("\n");

   int duration, distance;

    digitalWrite (right_trigPin, HIGH);

    delayMicroseconds (10);

    digitalWrite (right_trigPin, LOW);

    duration = pulseIn (right_echoPin, HIGH);

    distance = (duration/2) / 29.1; 

    if (distance < 55) {  // Change the number for long or short distances.

    Serial.print("Right Distance");

    Serial.print(distance);
    player.play(2);
 lcd.begin(16, 2);    
     lcd.setCursor(0,0);
  lcd.print("Something at");
  lcd.setCursor(0,1);
 lcd.print("Your Backside!!");  



    }

 }
 void rightt(){

   delay(50);// reading will be taken after ....miliseconds

   Serial.println("\n");

   int duration, distance;

    digitalWrite (right_trigPinn, HIGH);

    delayMicroseconds (10);

    digitalWrite (right_trigPinn, LOW);

    duration = pulseIn (right_echoPinn, HIGH);

    distance = (duration/2) / 29.1; 

    if (distance < 55) {  // Change the number for long or short distances.

    Serial.print("Right Distance");

    Serial.print(distance);
    player.play(2);
 lcd.begin(16, 2);    
     lcd.setCursor(0,0);
  lcd.print("Something at");
  lcd.setCursor(0,1);
 lcd.print("Your Backside!!");  



    }

 }
 void leftt(){

  delay(50);// reading will be taken after ....miliseconds

  Serial.println("\n");

  int duration, distance;

    digitalWrite (left_trigPinn, HIGH);

    delayMicroseconds (10);

    digitalWrite (left_trigPinn, LOW);

    duration = pulseIn (left_echoPinn, HIGH);

    distance = (duration/2) / 29.1;

    //distance= duration*0.034/2;  

    if (distance < 55) {  // Change the number for long or short distances.    

    Serial.print("Left Distance");

    Serial.print(distance);
    player.play(1);
     lcd.begin(16, 2);
   lcd.setCursor(0,0);
  lcd.print("Something at");
  lcd.setCursor(0,1);
 lcd.print("Your Frontside!!"); 
     

 

    }

}




 

