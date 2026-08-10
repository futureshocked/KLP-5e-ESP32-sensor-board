#define TEMT6000_PIN 1  // GPIO pin connected to the TEMT6000X01 sensor

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  while (!Serial);

  // Configure the analog pin
  pinMode(TEMT6000_PIN, INPUT);
}

void loop() {
  // Read the value from the TEMT6000X01 sensor (analog reading)
  int sensorValue = analogRead(TEMT6000_PIN);

  // Print the sensor value to the Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Wait a bit before reading again
  delay(500);
}
