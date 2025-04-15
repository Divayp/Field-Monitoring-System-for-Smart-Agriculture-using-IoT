
#define BLYNK_TEMPLATE_ID "TMPL6ZQmi74_2"
#define BLYNK_TEMPLATE_NAME "Nodemcu"

// Set your Wi-Fi credentials
char auth[] = "8gU9uTR-mKkuAiIUmEJBF-nbfKqqKl9r";
char ssid[] = "Galaxy";
char pass[] = "9973591772";

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define pins
#define DHTPIN D4        // Pin for DHT11 data
#define DHTTYPE DHT11    // DHT 11
#define SOIL_MOISTURE_PIN A0
#define TRIG_PIN D1
#define ECHO_PIN D2
#define RELAY_PIN D5
#define BUZZER_PIN D6

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Define variables
float temperature;
float humidity;
int soilMoistureValue;
long duration;
int distance;

void setup() {
  Serial.begin(115200);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize DHT sensor
  dht.begin();
  
  // Initialize pins
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Ensure relay and buzzer are off initially
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  Blynk.run();
  
  // Read temperature and humidity from DHT11
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  // Read soil moisture value
  soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  
  // Read distance from ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  
  // Check conditions
  if (distance <= 25) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
  }
  
  // Control relay based on soil moisture value
  if (soilMoistureValue < 500) {  // Example threshold value
    digitalWrite(RELAY_PIN, HIGH);  // Turn on relay (water pump)
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn off relay (water pump)
  }
  
  // Send values to Blynk app
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, soilMoistureValue);
  Blynk.virtualWrite(V4, distance);
  
  // Print values to Serial Monitor
  Serial.println("Temperature: " + String(temperature) + " °C");
  Serial.println("Humidity: " + String(humidity) + " %");
  Serial.println("Soil Moisture: " + String(soilMoistureValue));
  Serial.println("Distance: " + String(distance) + " cm");
  
  // Wait 2 seconds before next loop
  delay(2000);
}