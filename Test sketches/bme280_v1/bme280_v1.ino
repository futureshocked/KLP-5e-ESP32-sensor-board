#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>  // Include the Adafruit BME280 library

#define SDA_PIN 4  // SDA pin connected to GPIO 04
#define SCL_PIN 3  // SCL pin connected to GPIO 03
#define BME280_ADDRESS 0x76 // Specify the I2C address of the BME280 sensor

Adafruit_BME280 bme;  // Create an instance of the BME280 sensor

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Initialize I2C with custom SDA and SCL pins
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("BME280 Environmental Sensor Test");

  // Initialize the BME280 sensor with the specified address
  if (!bme.begin(BME280_ADDRESS)) {
    Serial.println("Could not find a valid BME280 sensor at address 0x3C, check wiring!");
    while (1);  // Stop the program if no sensor is found
  }

  // Initialize the sensor with default settings
  bme.setSampling(Adafruit_BME280::MODE_NORMAL,
                  Adafruit_BME280::SAMPLING_X16,   // Temperature
                  Adafruit_BME280::SAMPLING_X16,   // Pressure
                  Adafruit_BME280::SAMPLING_X16,   // Humidity
                  Adafruit_BME280::FILTER_X16);    // Filtering
}

void loop() {
  // Get the environmental data from the BME280 sensor
  float temperature = bme.readTemperature();  // Temperature in °C
  float humidity = bme.readHumidity();        // Humidity in %
  float pressure = bme.readPressure() / 100.0F; // Pressure in hPa

  // Print the values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  // Wait a short time before reading again
  delay(2000);  // Adjust the delay as needed (2 seconds here)
}
