#include "SPIFFS.h"
 
void listAllFiles(){
 
  File root = SPIFFS.open("/");
 
  File file = root.openNextFile();
 
  while(file){
 
      Serial.print("FILE: ");
      Serial.println(file.name());
 
      file = root.openNextFile();
  }
 
}
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
  Serial.println("\n\n---BEFORE REMOVING---");
  listAllFiles();
 
  SPIFFS.remove("/index.html");
  SPIFFS.remove("/style.css");
  SPIFFS.remove("/wifimanager.html");
  SPIFFS.remove("/ssid.txt");
  SPIFFS.remove("/pass.txt");
  SPIFFS.remove("/ip.txt");
  SPIFFS.remove("/gateway.txt");
  
  Serial.println("\n\n---AFTER REMOVING---");
  listAllFiles();
 
}
 
void loop() {}
