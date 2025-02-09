# Smart Home Energy Management System
## Introduction
Energy consumption in homes often leads to high utility bills and increased environmental impact due to inefficient usage. Many homeowners lack real-time insights into their electricity consumption, making it difficult to take proactive steps toward energy efficiency. Without proper monitoring and control, excessive energy use results in unnecessary expenses and contributes to carbon emissions, highlighting the need for a smarter approach to home energy management.

The Smart Home Energy Management System offers a real-time solution to this challenge by providing users with data-driven insights, automated alerts, and energy-saving recommendations. By leveraging advanced monitoring and analytics, the system helps homeowners track their energy usage, identify inefficiencies, and optimize consumption patterns. Through a user-friendly mobile app and web dashboard, users can make informed decisions, reduce electricity costs, and contribute to a more sustainable future.
## Overview
The project showcased here introduces an innovative solution for smart energy management, enabling homeowners to monitor and optimize electricity usage in real time. It leverages IoT technology to provide actionable insights, automated alerts, and data-driven recommendations for energy efficiency. By tracking energy consumption and analyzing usage patterns, the system helps users make informed decisions to reduce costs and minimize environmental impact.

- **ARIES MICRO v1.0 (VEGA Processor)**: Acts as the core microcontroller for data processing and decision-making.
- **NodeMCU**:  For transmitting real-time data over WiFi and providing users with instant updates.
- **Optocoupler**: Ensures safe and efficient signal isolation between different circuit components.
- **Real-Time Clock**: Maintains accurate timekeeping for energy usage tracking.
- **DHT11 Sensor**: Monitors temperature and humidity to analyze environmental factors affecting energy consumption.
- **Voltage Sensor**: Measures voltage levels for real-time monitoring of power usage.
- **Current Sensor**: Tracks current flow to identify excessive power consumption.
- **Relay Module**: Controls the switching of electrical appliances based on optimization strategies.

Users can monitor and manage their home’s energy consumption remotely through a mobile app and web dashboard, ensuring smarter energy usage and cost savings. This project exemplifies the practical application of IoT in home automation, promoting sustainable and efficient energy management.
## Components required with Bill of Materials
| Item                   | Quantity | Description                                                   | Links to Products                                      |
|------------------------|----------|---------------------------------------------------------------|---------------------------------------------------|
| Aries Micro v1.0(VEGA Processor)  | 1        | Microcontroller board                                        | [Aries Micro](https://robu.in/product/aries-micro-v1-0-devlopment-board/)           |
| NodeMCU  | 1        | For updating real-time data through WiFi  | [NodeMCU](https://robu.in/product/nodemcu-esp8266-v3-lua-ch340-wifi-dev-board/)        |
| Optocoupler            | 1        | For isolating high and low voltage circuits| [Optocoupler](https://robu.in/product/mct2em-optocoupler-phototransistor-ic-dip-6-package/)       |
| Real-Time Clock        | 1        | Module for keeping track of real-time data| [Real-Time Clock](https://robu.in/product/ds1302-real-time-clock-rtc-module-without-battery/)        |
| DHT11 Sensor| 1| Temperature and humidity sensor for environmental monitoring| [DHT11 Sensor](https://robu.in/product/dht11-temperature-and-humidity-sensor-module-with-led/)|
| Voltage Sensor           | 1|    Sensor for measuring voltage levels in circuits   | [Voltage Sensor](https://robu.in/product/ac-voltage-sensor-module-zmpt101b-single-phase/)       |
| Current Sensor         | 1|  Sensor for measuring electric current in a circuit| [Current Sensor](https://robu.in/product/5a-range-current-sensor-module-acs712/)        |
| 4-channel Relay module           | 1        | Electrically operated switch for controlling high-power devices    | [ 4-channel Relay module ](https://robu.in/product/4-channel-relay-module-5v-high-and-low-level-trigger-relay-module/)        |
| DTH AC 21.V       | 1        | A power supply for DTH (Direct-to-Home)   | [DTH AC 21.V]( https://amzn.in/d/dBb4ZcJ )           |
| PCB          | 1        | For connecting the components  | [PCB](https://robu.in/product/12-x-18-cm-universal-pcb-prototype-board-single-sided-2-54mm-hole-pitch/)         |
| USB Cable  | 1        | For programming and power supply                             | [Micro USB Cable](https://amzn.in/d/1Sg2bNx)        |
## Table for Pin Connections
| Component            | Aries v1.0 Pin | Description                                             |
|----------------------|-----------------------|---------------------------------------------------------|
| Servo Signal         | PC6                   | Servo motor's control signal pin                        |
| Servo VCC            | 5V                    | Servo motor's power supply                              |
| Servo GND            | GND                   | Servo motor's ground                                    |
| Bluetooth RXD        | PD6                   | Bluetooth module's RXD pin (connect directly to 3.3V logic) |
| Bluetooth TXD        | PD7                   | Bluetooth module's TXD pin (connect directly to 5V logic) |
| Bluetooth GND        | GND                   | Bluetooth module's ground pin                           |
| Bluetooth VCC        | 3.3V                  | Bluetooth module's 3.3V pin (connect to microcontroller's 3.3V output pin) |
| Bluetooth State      | PC7                   | Bluetooth module's State pin (indicates connection status) |
| Onboard LED          | LED_BUILTIN           | Onboard LED for status indication                       |

## Pinout Diagram
![image](https://github.com/vls-midhuna/Smart-Home-Energy-Management-System/blob/84fc8145ec4254cac4d6af616fad86aebcbe9dd6/Pinout.png)
## Working Code
## Demo Video
## Acknowledgements






