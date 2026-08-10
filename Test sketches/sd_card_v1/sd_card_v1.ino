#include <SPI.h>
#include <SD.h>

#define SD_CS_PIN 0  // Chip Select (CS) pin for SD card (GPIO0)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Initialize the SPI bus for the SD card (reset SPI pins)
  SPI.begin(6, 2, 7, SD_CS_PIN);  // SCK, MISO, MOSI, CS pins for SD card

  // Attempt to initialize the SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialized successfully.");

  // Create and write to a file
  File myFile = SD.open("/test.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("Hello, SD card!");
    myFile.close();  // Close the file after writing
    Serial.println("Data written to test.txt.");
  } else {
    Serial.println("Error opening test.txt for writing.");
  }

  // Read the file back
  myFile = SD.open("/test.txt");
  if (myFile) {
    Serial.println("Reading from test.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();  // Close the file after reading
  } else {
    Serial.println("Error opening test.txt for reading.");
  }
}

void loop() {
  // Nothing to do here
}
