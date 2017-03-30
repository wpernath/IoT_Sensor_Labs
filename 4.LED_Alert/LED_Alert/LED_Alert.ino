/*
  DHTServer - ESP8266 with a DHT sensor as an input
*/

#include <DHT.h>

/************************* DHT22 Sensor *********************************/
#define DHTTYPE DHT22
#define DHTPIN  12

DHT dht(DHTPIN, DHTTYPE, 11);

float         humidity, temp_c;           // Values read from sensor
unsigned long previousMillis = 0;         // will store last temp was read
const long    interval = 2000;            // interval at which to read sensor
unsigned long count = 0;                  // counter for messagepoints
String        message = "";               // message to display


/************* Utility function to retrieve data from DHT22 ******************************/
void gettemperature() {
  // Wait at least 2 seconds seconds between measurements.
  // if the difference between the current time and last time you read
  // the sensor is bigger than the interval you set, read the sensor
  // Works better than delay for things happening elsewhere also
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    // save the last time you read the sensor
    previousMillis = currentMillis;

    // Reading temperature for humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
    humidity = dht.readHumidity();          // Read humidity (percent)
    temp_c = dht.readTemperature();         // Read temperature as Celsius
    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity) || isnan(temp_c)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}

/************* Functionname says it all! ******************************/
void setup(void) {

  Serial.begin(115200);
  
  dht.begin();

  Serial.println("\n\rESP8266 & DHT22 based temperature and humidity sensor working!");

  pinMode(BUILTIN_LED, OUTPUT);

  digitalWrite(BUILTIN_LED, HIGH);      // turn off
}

/************* Functionname says it all! ******************************/
void loop(void) {

  gettemperature();           // read sensordata
 
  // Now we can publish stuff!
  message = String((int)temp_c) + ", " + String(count);

  Serial.print(F("\nReceived temperature value in Celsius <"));
  Serial.print(message);
  Serial.print(">");
  
  message = String((int)humidity) + ", " + String(count);

  Serial.print(F("\nReceived humidity value <"));
  Serial.print(message);
  Serial.print(">");

  if ( ( humidity > 60 ) || ( temp_c > 25 ) ){
    digitalWrite(BUILTIN_LED, LOW); 
  } else {
    digitalWrite(BUILTIN_LED, HIGH); 
  }
  
  delay(1000);
}
