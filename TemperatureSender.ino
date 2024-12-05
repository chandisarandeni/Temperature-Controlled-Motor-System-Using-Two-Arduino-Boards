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
