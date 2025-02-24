#include<WiFi.h>
const char* ssid="Redmi 9 Prime";
const char* password="12345678";
void setup() {
  // put your setup code here, to run once:
  Serial.println("start");
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to WiFi...");
    }
    Serial.println("connected to the WIFI network");

}

void loop() {
  // put your main code here, to run repeatedly:
   if(WiFi.status()==WL_CONNECTED){
    print("Active");
   }
}
