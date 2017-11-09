#include <Servo.h>  

Servo myServo;      //The sign servo
int buzzerPin = 8;  //The Buzzer pin
int redLed = 9;     //The led pin
int moisture;       //The moisture value
 
void setup() {
  pinMode(buzzerPin,OUTPUT);   
  pinMode(redLed,OUTPUT);      
  myServo.attach(11;          
}
 
void loop() {
  moisture = analogRead(A0);             //Read the moisture from sensor
  moisture = map(moisture,0,1023,100,1); //Map the moisture values to 1-100. 
  if (moisture < 50) {                   //If moisture is low
    myServo.write(165);                  //Turn motor to "No water" sign
    digitalWrite(redLed,HIGH);           //Turn on the led light
    tone(buzzerPin, 2000, 500);          //Play a buzzer tone for halph a second
    delay(1000);                         //delay for a second
    digitalWrite(redLed,LOW);            //Turn off the led light  
    delay(1000);                         //Delay another second
  } else {                               //If moisture is OK
    digitalWrite(redLed,HIGH);           //Just turn on the led light 
    myServo.write(20);                   //and turn motor to "plant ok" sign
  }
}