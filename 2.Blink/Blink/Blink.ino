/*
  DHTServer - ESP8266 with a DHT sensor as an input
*/

String        message = ""; 

/************* Functionname says it all! ******************************/
void setup(void) {

  Serial.begin(115200);                 

  Serial.println("\n\rESP8266 started!");

  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
}

/************* Functionname says it all! ******************************/
void loop(void) {

  message = "\n\rLight On";
  Serial.print(message);
  digitalWrite(BUILTIN_LED, LOW);  
  delay(1000);                     
  
  message = "\n\rLight Off";
  Serial.print(message);
  digitalWrite(BUILTIN_LED, HIGH);      
  delay(1000);                     
  
}
