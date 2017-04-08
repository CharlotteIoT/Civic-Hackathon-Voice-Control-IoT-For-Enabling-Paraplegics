// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
// DHT 11
#define DHTTYPE DHT11
// what pin we are connected to
#define DHTPIN 3

// initialize the sensor library
DHT dht(DHTPIN, DHTTYPE);

// variables to hold current temp and current humidity
double tempF = 0;
double humidity = 0;

void setup() {
  // variables
  // temp variable
  Particle.variable("temp", tempF);
  // humidity variable
  Particle.variable("humidity", humidity);
  
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  // Wait 30 seconds between measurements.
  delay(30000);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  humidity = dht.getHumidity();
  // Get temperature - Fahrenheit
  tempF = dht.getTempFarenheit();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // output the humidity
  Serial.print("Humidity: ");
  Serial.println(humidity);
  // output the temperature - Fahrenheit
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println(" *F ");
}