/*
 @file I2C_LCD.ino
 @brief Interfacing I2C LCD with Aries V2
 @detail This program will display messages within a delay of 2 seconds in I2C LCD 

 * Reference arduino code: https://arduinogetstarted.com/tutorials/arduino-lcd-i2c
 * Refrence aries board: https://vegaprocessors.in/blog/bmp180-digital-pressure-sensor-with-aries-v2-board/
 * Library Name : LiquidCrystal I2C
 * Library Version: 1.1.2
 * 
 * I2C LCD
 * Device address -0x27
 * Connections:
 * I2C LCD     Aries Board
 * VCC      -   3.3V/5V
 * GND      -   GND
 * SDA      -   SDA1
 * SCL      -   SCL1
 * For connecting to port 0 (SCL 0 and SDA0) of aries board use the default variable TwoWire Wire(0) instead of TwoWire Wire(1);
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ACS712.h>
#include <DFRobot_DHT11.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

TwoWire Wire(1);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
ACS712 sensor(ACS712_30A, A0);
DFRobot_DHT11 DHT;
#define DHT11_PIN 7 
#define relay_ac_line 2
#define relay_solar_line 4
#define relay_switching_line 5
#define relay_neutral 6
#define voltage 7

tmElements_t tm;

float time = 1.5;
float energy = 0; 
float Voltage; 
float resolution = 0.002;

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  sensor.calibrate();
  
}

void loop()
{
  

//  read_RTC();
 
  float I = sensor.getCurrentAC();
  //ignoring the value below 0.09
  if (I < 0.09) {
    I = 0;
  }
  
  energy = energy + (220 * I * time)/(3600*1000);
  DHT.read(DHT11_PIN);
 // 
  Voltage = resolution * (float)analogRead(voltage);
  
  if (Voltage>=20){
    digitalWrite(relay_neutral,LOW);
    digitalWrite(relay_switching_line,LOW);
  }
  else{
    digitalWrite(relay_neutral,HIGH);
    digitalWrite(relay_switching_line,HIGH);
  }
  
  
  // FINAL PART OF THE CODE TO DISPLAY THE OUTPUT
 TwoWire Wire(1);
  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Energy Meter");        // print message at (0, 0)
//  lcd.print("Time:");
//  lcd.print(tm.Hour);
//  lcd.print(":");
//  lcd.print(tm.Minute);
//  lcd.print(":");
//  lcd.print(tm.Second);
  lcd.setCursor(0, 1);         // move cursor to   (2, 1)
  lcd.print("Temparature:");
  lcd.print(DHT.temperature);// print message at (2, 1)
  lcd.print(" C");
  delay(750);                 // display the above for two seconds

  lcd.clear();                  // clear display
  lcd.setCursor(0, 0);          // move cursor to   (3, 0)
  lcd.print("Energy consumed:");        // print message at (3, 0)
  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
  lcd.print(energy);
  lcd.print("  KWH"); // print message at (0, 1)
  delay(750);                  // display the above for two seconds
}

//void read_RTC(){
//  tmElements_t tm1;
//  TwoWire Wire(0);
//  if (RTC.read(tm1)){
//  tm = tm1;
//  }
//}