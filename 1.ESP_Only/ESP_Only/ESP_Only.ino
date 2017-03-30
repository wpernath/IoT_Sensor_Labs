/*
  
  */

String        message = "";               // message to display

/************* Functionname says it all! ******************************/
void setup(void) {

  Serial.begin(115200);                 // prepare serial for debug messages

  Serial.println("\n\rESP8266 started!");
}

/************* Functionname says it all! ******************************/
void loop(void) {

  message = "\n\rStill working";

  Serial.print(message);
  
  delay(1000);                          // Sleep a second
}
