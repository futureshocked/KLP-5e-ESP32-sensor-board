#include <EEPROM.h>

#define EEPROM_SIZE 512  // Size of the EEPROM (in bytes)
#define CS_PIN 10        // Chip Select (CS) pin for SPI flash (GPIO10)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Initialize EEPROM with the defined size
  if (!EEPROM.begin(EEPROM_SIZE)) {
    Serial.println("Failed to initialize EEPROM");
    return;
  }

  // Write a value to EEPROM (SPI flash)
  int address = 0;       // Starting address
  byte value = 42;       // Value to write to flash (for example)

  EEPROM.write(address, value);  // Write the byte to the flash memory

  // Commit changes to the EEPROM (actually write to flash)
  EEPROM.commit();

  Serial.print("Wrote value ");
  Serial.print(value);
  Serial.print(" to address ");
  Serial.println(address);

  // Read back the value to verify
  byte readValue = EEPROM.read(address);
  Serial.print("Read back value: ");
  Serial.println(readValue);
}

void loop() {
  // Nothing to do here
}
