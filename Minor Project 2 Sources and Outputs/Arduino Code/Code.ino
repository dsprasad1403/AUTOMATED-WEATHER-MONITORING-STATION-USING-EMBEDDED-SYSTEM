// Include the required libraries
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Initialize the LCD display (I2C Address: 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT11 Sensor Setup
#define DHTPIN D3      // Pin connected to DHT11 data pin
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Rain and LDR sensor pins
#define RAIN_SENSOR_PIN A0  // Analog pin for rain sensor
#define LDR_SENSOR_PIN D0   // LDR sensor connected to D0

// Blynk credentials
char auth[] = "XXXXXXXXXXXXXXXXXX";  // Enter your Blynk Auth Token
char ssid[] = "I am Bat Man 4G";  // Enter your WiFi Name (SSID)
char pass[] = "KINGS008";         // Enter your WiFi Password

// Initialize Blynk Timer
BlynkTimer timer;

// Variables for sensor values
float temperature, humidity;
int rainLevel;
int ldrReading;  // Variable to hold LDR sensor reading

// Thresholds for light detection
const int lightThreshold = 500; // Adjust this value based on your testing

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Initialize Blynk connection
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Initialize DHT11 sensor
  dht.begin();

  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();

  // Display a startup message on LCD
  lcd.setCursor(0, 0);
  lcd.print("Weather Monitor");
  lcd.setCursor(4, 1);
  lcd.print("System");
  delay(3000);  // Hold message for 3 seconds
  lcd.clear();

  // Set LDR pin as input
  pinMode(LDR_SENSOR_PIN, INPUT);

  // Set timer to call sensor reading functions every second (1000ms)
  timer.setInterval(1000L, readSensors);
}

// Function to read sensors and update values
void readSensors() {
  // Read temperature and humidity from DHT11
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read rain sensor values (mapped to 0-100)
  rainLevel = analogRead(RAIN_SENSOR_PIN);
  rainLevel = map(rainLevel, 0, 1024, 0, 100);

  // Read LDR sensor value
  ldrReading = analogRead(LDR_SENSOR_PIN);
  Serial.print("LDR Reading: ");
  Serial.println(ldrReading);  // Debugging output

  // Determine if light is detected based on LDR reading
  if (ldrReading < lightThreshold) {  // Light detected
    Serial.println("Light Level: HIGH");
    Blynk.virtualWrite(V4, 1);  // Set virtual pin V4 to 1 for light detected (HIGH)
  } else {  // Light not detected
    Serial.println("Light Level: LOW");
    Blynk.virtualWrite(V4, 0);    // Set virtual pin V4 to 0 for no light detected (LOW)
  }

  // Send data to Blynk app
  Blynk.virtualWrite(V0, temperature);  // Send temperature to Virtual Pin V0
  Blynk.virtualWrite(V1, humidity);     // Send humidity to Virtual Pin V1
  Blynk.virtualWrite(V2, rainLevel);    // Send rain level to Virtual Pin V2

  // Display values on LCD
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C ");   // Space after temperature
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("% ");    // Space after humidity

  lcd.setCursor(0, 1);
  lcd.print("R:");
  lcd.print(rainLevel);
  lcd.print("%  ");    // Space after rain level

  // Display light status on LCD
  lcd.setCursor(8, 1);
  if (ldrReading < lightThreshold) {
    lcd.print("L:HIGH   ");  // Display "L:HIGH" for light detected
  } else {
    lcd.print("L:LOW    ");   // Display "L:LOW" for light not detected
  }
}

void loop() {
  Blynk.run();  // Run Blynk library
  timer.run();  // Run Blynk timer
}
