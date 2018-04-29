#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(4,5); // RX | TX
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "........................";
char ssid[] = "xxxxxxxx";
char pass[] = "xxxxxxxx";
WidgetMap myMap(V1);
WidgetLCD lcd(V2);

void notifyOnButtonPress()
{
    Serial.println("Button is pressed.");
    //   We allow 1 notification per 15 seconds for now.
    Blynk.notify("OBSTUCLE DETECTED");
    delay(1000);

}

void setup() {
Serial.begin(115200);
ESPserial.begin(115200);
Blynk.begin(auth, ssid, pass);
  int index = 1;
  float lat = 51.5074;
  float lon = 0.1278;
  myMap.location(index, lat, lon, "value");

}

void loop() 
{
  if ( ESPserial.available() >= 0 ) 
  { while(ESPserial.available()){
    int c = ESPserial.read();
    if(c==49)
    {
       notifyOnButtonPress();
      lcd.clear();
      lcd.print(4, 0, "OBSTACLE");
      lcd.print(4, 1, "DETECTED"); 
    }
        if(c==50)
    {
      lcd.clear();
      lcd.print(5, 0, "CRACK");
      lcd.print(4, 1, "DETECTED"); 
    }
    else
    {
      lcd.clear();
      lcd.print(5, 0, "SCANNING");
     // lcd.print(4, 1, "DETECTED");      
    }
    Serial.println(c);
  }}

Blynk.run();


}
