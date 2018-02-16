#include<LiquidCrystal.h>
// Program for Counting Total No. of Parking Space Available in a Parking Area
// Tools Used - LDR sensor, LED lights, ARDUINO NANO, ATmega 328P Microcontroller

const int rs =1, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ledP1 = 8;


const int ledP[2] = {13,12}; //array of  ledP(ledPins) , for connecting n number of leds to the arduino using digital pins 
const int ldrP[2] = {A0,A1}; //array of LdrP(LDR Pins ), for connecting n number of LDR sensors to the Analog Pins of the Arduino

int Parking_Space = 2; // Total Number of Parking Space Available

void Parking_read(int *ledP, int *ldrP) // Function to Read the Status of a Particular Parking Area and Display it on the MAP MODEL
{
  int ldrStatus = analogRead(*ldrP);// analogRead to read the value of LDR sensor and store it to the ldrStatus variable
  if(ldrStatus<4)
    digitalWrite(*ledP, LOW); // if vehicle is Parked the set intensity of light will be low Hence led will be switched off 
  
  else
    digitalWrite(*ledP,HIGH); // if the Parking space is Empty and sensor is receiveing sufficient intensity of light
}


void setup() 
{
  //Configure All the i/p , o/p pins
  lcd.begin(16, 2);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Avail. Space=");
 // Serial.begin(9600);
  pinMode(ldrP[0], INPUT);
  pinMode(ledP[0], OUTPUT);
  pinMode(ldrP[1], INPUT);
  pinMode(ledP[1], OUTPUT);
   
  
  
}

void loop()
{
  digitalWrite(ledP1, LOW);
  int avail = 0, count = 0; // avail for total available parking , count for counting upto Total number of Parking
  Parking_read(&ledP[0], &ldrP[0]); // Function Call
  Parking_read(&ledP[1], &ldrP[1]); // Function Call

  while(count<Parking_Space)
  {
    if(digitalRead(ledP[count])== HIGH)
    avail++;
    count++;
  }
  lcd.setCursor(13,1);
 lcd.print(avail);
if(avail == 0)
 {
   digitalWrite(ledP1,HIGH);
   delay(50);
 }
 // lcd.display();
//Serial.println(avail);

}

