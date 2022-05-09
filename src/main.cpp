#include <Arduino.h>
int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R1 = 100;  // enter the value of the resistor here
float R2 = 0;
float buffer = 0;


//I need to the component for the sensor so that I can create the code for it this week.

void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(13, OUTPUT);
};

void loop() {
  raw = analogRead(analogPin);
  if(raw){
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2 = R1 * buffer;
  };

  Serial.print("Vout: ");
  Serial.println(Vout);
  Serial.print("R2: ");
  Serial.println(R2);

  if(R2 <= 30){
    LED();
  } else if(R2 < 20){
    buzzer();
    LED();
  }; //this will cause an LED to blink as well as make a buzzer sound every 500 seconds
};

void buzzer(){
  tone(11,1000);
  delay(500);
  noTone(11);
  delay(500);
};

void LED(){
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
};

// void Resistance(){
//   raw = analogRead(analogPin);
//   if(raw){
//     buffer = raw * Vin;
//     Vout = (buffer)/1024.0;
//     buffer = (Vin/Vout) - 1;
//     R2 = R1 * buffer;
//     Serial.print("Vout: ");
//     Serial.println(Vout);
//     Serial.print("R2: ");
//     Serial.println(R2);
//     delay(1000);
// };