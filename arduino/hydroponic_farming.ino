#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define WATER_LEVEL_PIN 3
#define PUMP_RELAY_PIN 7
#define LIGHT_RELAY_PIN 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(WATER_LEVEL_PIN, INPUT);
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  pinMode(LIGHT_RELAY_PIN, OUTPUT);

  digitalWrite(PUMP_RELAY_PIN, LOW);
  digitalWrite(LIGHT_RELAY_PIN, LOW);
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int waterLevel = digitalRead(WATER_LEVEL_PIN);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (waterLevel == HIGH) {
    digitalWrite(PUMP_RELAY_PIN, HIGH);
    Serial.println("Water Level OK - Pump ON");
  } else {
    digitalWrite(PUMP_RELAY_PIN, LOW);
    Serial.println("Low Water Level - Pump OFF");
  }

  digitalWrite(LIGHT_RELAY_PIN, HIGH);
  Serial.println("Grow Light ON");

  Serial.println("----------------------");

  delay(2000);
}
