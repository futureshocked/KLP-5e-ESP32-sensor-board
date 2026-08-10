#include <Wire.h>

#define SDA_PIN 4  // SDA pin connected to GPIO 04
#define SCL_PIN 3  // SCL pin connected to GPIO 03

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Initialize I2C with custom pins (SDA on GPIO 04, SCL on GPIO 03)
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("I2C Scanner");

  // Scan for I2C devices
  byte address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    // Start I2C transmission
    Wire.beginTransmission(address);

    if (Wire.endTransmission() == 0) {
      // Device found, print its address
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");  // Print leading zero for single-digit addresses
      }
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found.");
  } else {
    Serial.print("Total I2C devices found: ");
    Serial.println(nDevices);
  }
}

void loop() {
  // Nothing to do in the loop
}
