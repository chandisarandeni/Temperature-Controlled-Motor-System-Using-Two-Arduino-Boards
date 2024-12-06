# Temperature-Controlled Motor System Using Two Arduino Boards

## Overview  
This project demonstrates a system using two Arduino boards, an LM35 temperature sensor, and an L298N motor driver to control a DC motor's speed and direction based on temperature readings. The setup involves serial communication between the two Arduinos for data transfer and hardware control.  

## System Description  

### Arduino 1 (Sender - Left):  
- **Purpose:** Reads temperature data from the LM35 sensor and transmits it to Arduino 2 via serial communication.  
- **Connections:**  
  - LM35 sensor connected to analog pin A0 for temperature input.  
  - Processes the temperature value and sends it serially to the receiver Arduino.  

### Arduino 2 (Receiver - Right):  
- **Purpose:** Receives temperature data from Arduino 1 and controls the DC motor's speed and direction based on the temperature.  
- **Connections:**  
  - L298N motor driver connected to control motor speed (via PWM on the enable pin) and direction (via input pins).  
  - Adjusts motor operation dynamically based on the received temperature value.  

### Inter-Arduino Communication:  
- Serial communication enables real-time data transfer between the two Arduinos, allowing synchronized operation of the system.  

## Components  
- 2 Arduino Uno boards  
- LM35 temperature sensor  
- L298N motor driver  
- DC motor  
- Breadboard and jumper wires  

## Applications  
- Temperature-controlled motor systems  
- Automation and IoT projects  
- Educational purposes for learning Arduino communication and motor control  

This system combines real-time sensor data processing, communication, and motor control, making it a versatile learning project for beginners and enthusiasts.  
