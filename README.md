# Temperature-Controlled Motor System Using Two Arduino Boards

## Overview  
This project demonstrates a system using two Arduino boards, an LM35 temperature sensor, and an L298N motor driver to control a DC motor's speed and direction based on temperature readings. The setup involves serial communication between the two Arduinos for data transfer and hardware control.  

## System Description  

### Arduino 1 (Sender - Left):  

```cpp

int tempPin = A0;
int temperature;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  // Read the temperature from the LM35
  temperature = analogRead(tempPin);
  temperature = map(temperature, 0, 1023, 0, 100);  // Convert to temperature range 0-100°C

  // Send the temperature data via serial communication
  Serial.println(temperature);

  delay(500);
}

```

- **Purpose:** Reads temperature data from the LM35 sensor and transmits it to Arduino 2 via serial communication.  
- **Connections:**  
  - LM35 sensor connected to analog pin A0 for temperature input.  
  - Processes the temperature value and sends it serially to the receiver Arduino.  

### Arduino 2 (Receiver - Right):  

```cpp

int enablePin1 = 9; 
int inputPin1 = 2; 
int inputPin2 = 3; 
int temperature; 

void setup() {
  pinMode(enablePin1, OUTPUT);  // Set the enable pin as output
  pinMode(inputPin1, OUTPUT);   // Set input pin 1 as output
  pinMode(inputPin2, OUTPUT);   // Set input pin 2 as output
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {
    // Read the temperature data sent by Arduino 1
    temperature = Serial.parseInt();
    
    // Map temperature to PWM motor speed (0-255)
    int motorSpeed = map(temperature, 0, 100, 0, 255);
    
    // Set motor speed using PWM on the Enable pin
    analogWrite(enablePin1, motorSpeed);
    
    // Control motor direction
    if (temperature > 0) { // If temperature is positive, rotate in one direction
      digitalWrite(inputPin1, HIGH);
      digitalWrite(inputPin2, LOW);
    } else { // Else rotate in reverse direction (for simplicity)
      digitalWrite(inputPin1, LOW);
      digitalWrite(inputPin2, HIGH);
    }

    Serial.print("Temperature: ");
    Serial.println(temperature);  // Print the received temperature to the serial monitor
  }
}

```

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
