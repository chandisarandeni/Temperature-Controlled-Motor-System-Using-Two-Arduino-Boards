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
