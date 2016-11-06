/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The value read from Analog pin is also displayed on LCD
 
 The circuit:
*Uses the pot on the board connected to A0
*LED connected to pin 0 is used. 
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 modified July 3rd 2011
 to add LCD support
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,4,5,6,7);
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 0;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  lcd.begin(16, 2);
  lcd.print("Read POT!");
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  
  lcd.setCursor(0, 1); 
  lcd.print("               "); //clears line two
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);                  
}
