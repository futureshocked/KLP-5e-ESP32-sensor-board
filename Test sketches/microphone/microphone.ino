#define MIC_PIN 5  // GPIO 5 is connected to the microphone

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Configure GPIO 5 as input for the microphone signal
  pinMode(MIC_PIN, INPUT);
}

void loop() {
  // Read the value from the microphone (analog reading)
  int micValue = analogRead(MIC_PIN);

  // Print the microphone reading to the Serial Monitor
  Serial.print("Microphone Value: ");
  Serial.println(micValue);

  // Wait a short time before reading again
  delay(10);  // Adjust the delay for the sampling rate (10ms)
}
