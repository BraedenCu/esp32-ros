#include "WiFi.h"
#include "SPI.h"

const char* ssid = "CullieMax";
const char* password = "cullen120";
//can also just use ip instead of dns to decrease sketch size
char server[] = "192.168.86.26"; 

WiFiClient client;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  // run until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connecting...");
  }
  Serial.println("connected");

  if (client.connect(server, 20)) {
    Serial.println("connected");
    client.println("test");
    
  }
  
}

void loop() {
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  if (!client.connected()) {
    Serial.println("disconnected from server.");
    client.stop();
  }
}
