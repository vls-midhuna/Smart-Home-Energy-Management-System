# Smart Home Energy Management System
## Introduction
Energy consumption in homes often leads to high utility bills and increased environmental impact due to inefficient usage. Many homeowners lack real-time insights into their electricity consumption, making it difficult to take proactive steps toward energy efficiency. Without proper monitoring and control, excessive energy use results in unnecessary expenses and contributes to carbon emissions, highlighting the need for a smarter approach to home energy management.

The Smart Home Energy Management System offers a real-time solution to this challenge by providing users with data-driven insights, automated alerts, and energy-saving recommendations. By leveraging advanced monitoring and analytics, the system helps homeowners track their energy usage, identify inefficiencies,switching between the power lines and optimize consumption patterns. Through a user-friendly mobile app and web dashboard, users can make informed decisions, reduce electricity costs, and contribute to a more sustainable future.
## Overview
The project showcased here introduces an innovative solution for smart energy management, enabling homeowners to monitor and optimize electricity usage in real time. It leverages IoT technology to provide actionable insights, automated alerts, and data-driven recommendations for energy efficiency. By tracking energy consumption and analyzing usage patterns, the system helps users make informed decisions to reduce costs and minimize environmental impact. The power lines can be switched between AC line and solar line based on the availabity of the power in the respective sources.

- **ARIES MICRO v1.0 (VEGA Processor)**: Acts as the core microcontroller for data processing and decision-making.
- **NodeMCU**:  For transmitting real-time data over WiFi and providing users with instant updates.
- **Optocoupler**: Ensures safe and efficient signal isolation between different circuit components.
- **Real-Time Clock**: Maintains accurate timekeeping for energy usage tracking.
- **DHT11 Sensor**: Monitors temperature and humidity to analyze environmental factors affecting energy consumption.
- **Voltage Sensor**: Measures voltage levels for real-time monitoring of power usage.
- **Current Sensor**: Tracks current flow to identify excessive power consumption.
- **Relay Module**: Controls the switching of power lines.

Users can monitor and manage their home’s energy consumption remotely through a mobile app and web dashboard, ensuring smarter energy usage and cost savings. This project exemplifies the practical application of IoT in home automation, promoting sustainable and efficient energy management.
## Components required with Bill of Materials
| Item                   | Quantity | Description                                                   | Links to Products                                      |
|------------------------|----------|---------------------------------------------------------------|---------------------------------------------------|
| Aries Micro v1.0(VEGA Processor)  | 1        | Microcontroller board                                        | [Aries Micro](https://robu.in/product/aries-micro-v1-0-devlopment-board/)           |
| NodeMCU  | 1        | For updating real-time data through WiFi  | [NodeMCU](https://robu.in/product/nodemcu-esp8266-v3-lua-ch340-wifi-dev-board/)        |
| Optocoupler            | 1        | For isolating high and low voltage circuits| [Optocoupler](https://robu.in/product/mct2em-optocoupler-phototransistor-ic-dip-6-package/)       |
| Real-Time Clock        | 1        | Module for keeping track of real-time data| [Real-Time Clock](https://robu.in/product/ds1302-real-time-clock-rtc-module-without-battery/)        |
| DHT11 Sensor| 1| Temperature and humidity sensor for environmental monitoring| [DHT11 Sensor](https://robu.in/product/dht11-temperature-and-humidity-sensor-module-with-led/)|
| Voltage Sensor           | 1|    Sensor for measuring voltage level of Solar battery   | [Voltage Sensor](https://robu.in/product/ac-voltage-sensor-module-zmpt101b-single-phase/)       |
| Current Sensor         | 1|  Sensor for measuring electric current in a circuit| [Current Sensor](https://robu.in/product/5a-range-current-sensor-module-acs712/)        |
| 4-channel Relay module           | 1        | To switch the power lines between AC line Solar power line| [ 4-channel Relay module ](https://robu.in/product/4-channel-relay-module-5v-high-and-low-level-trigger-relay-module/)        |
| DTH AC 21.V       | 1        | To convert AC to DC for Power supply to th circuit  | [DTH AC 21.V]( https://amzn.in/d/dBb4ZcJ )           |
| PCB          | 1        | For connecting the components  | [PCB](https://robu.in/product/12-x-18-cm-universal-pcb-prototype-board-single-sided-2-54mm-hole-pitch/)         |
| USB Cable  | 1        | For programming and power supply                             | [Micro USB Cable](https://amzn.in/d/1Sg2bNx)        |
## Table for Pin Connections
| Component            | Pin Name on Component | Connected to (Aries v1.0)                                      |
|----------------------|-----------------------|---------------------------------------------------------|
| I2C LCD        |           VCC         |           3.3V / 5V      |
|                |           GND         |              GND         |
|                |            SDA        |             SDA1 (I2C)       |
|                |            SCL        |         SCL1 (I2C)              |
|ACS712 Current Sensor|      VCC             |          3.3V / 5V    |
|                |              GND      |         GND              |
|                |             OUT       |     A0 (Analog Input)                  |
|    DHT11 Sensor|            VCC        |         3.3V / 5V              |
|                |           GND         |              GND         |
|                |           Data         |            D7 (Digital Pin 7)           |
|         DS1307 RTC Module	       |           VCC         |         3.3V / 5V              |
|                |         GND           |           GND            |
|                |         SDL           |             SDA0 (I2C)          |
|                |           SCL         |       SCL0 (I2C)                |
|         Relays	       |         Relay (AC Line)	           |       D2                |
|                |                Relay (Solar Line)	    |              D4         |
|                |             Relay (Switching Line)	       |          D5             |
|                |               Relay (Neutral)	     |           D6            |
|         Voltage Measurement	       |            Analog Voltage Sensor	        |      A7                 |


## Pinout Diagram
![image](https://github.com/vls-midhuna/Smart-Home-Energy-Management-System/blob/87bc3f32092ac5b353d463afb93c81fc666be144/Pinout.png)

## Working Code
```
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
```

## Demo Video
![Watch Video](https://drive.google.com/file/d/1DZKWxJaV9uT9lNJgN7TYlKBFm8v8cqvh/view?usp=drivesdk)
<video width="640" height="360" controls>
  <source src="https://github.com/yourusername/repo/blob/main/video.mp4?raw=true" type="video/mp4">
  Your browser does not support the video tag.
</video>


## Acknowledgements
I’m grateful for the opportunity to participate in the DIRV Hackathon 2025, organized by IIT Madras in collaboration with VSD, as part of the 2nd Digital India RISC-V (DIR-V) Symposium. It’s exciting to be part of this 4th Product-based Hackathon PAN India and the 3rd RISC-V-focused event, especially with such a reputed institute. This experience has been a great learning opportunity, allowing me to apply my skills, work with like-minded individuals, and contribute to real-world innovation. A big thanks to the organizers for making this possible!






