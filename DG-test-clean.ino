#include<ESP8266WiFi.h>
#define quote(string) Serial.print('"'); Serial.print(string); Serial.print('"');

String location = "";

void setup() {
  Serial.begin(115200);
  delay(2000);
  WiFi.disconnect();
}

void loop() {
  String input = ip();

  if(checkIn(input)==3)
  {
    scanner(input);
  }
  else if(checkIn(input)==2)
  {
    scanner(input);
  }
  else if (checkIn(input)==0)
  {
    ip();
  }
}

String ip()
{
  String input;
  Serial.print("Enter 'scan {location}' to start scanning");
  while(!Serial.available())
  {
    delay(200);
  }
  input= Serial.readStringUntil('\n'); 
  return input;
}

int checkIn(String s) 
{
  if(s== "")
  {
    return 1;
  }
  else if(s=="Stop")
  {
    return 2;
  }
  else 
  {
    s= s[1];
    return 3;
  }
}

void scanner(String location)
{
  int i= 10;
  while(i>0)
  {
    int numNetworks = WiFi.scanNetworks();
    Serial.print('{');
    quote("__location");
    Serial.print(": ");
    quote(location);
    Serial.print(", ");
    for (int i = 0; i < numNetworks; i++) {
      quote(WiFi.SSID(i));
      Serial.print(": ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(i == numNetworks - 1 ? "}\n" : ", ");
    }
      
    delay(1000);
    i--;
  }

}
