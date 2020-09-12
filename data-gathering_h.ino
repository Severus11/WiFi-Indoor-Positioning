
#include<ESP8266WiFi.h>
//#define print(string) Serial.print(string);
#define quote(string) Serial.print('"'); Serial.print(string); Serial.print('"');

String location= "";


void setup() {
  Serial.begin(115200);
  delay(3000);

  WiFi.disconnect();

}

void loop() {
  int q=0;
  if(location != ""  && q<2)
  {
    int number= WiFi.scanNetworks();

    Serial.print('{');
    quote("__location");
    Serial.print(": ");
    quote(location);
    Serial.print(", ");

    for(int i=0; i< number; i++)
    {
      quote(WiFi.SSID(i));
      Serial.print(": ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(i == number  - 1 ? "}\n" : ", ");
    }
    delay(1000);
    q++;
  } 
  else
  {
    String input;
    Serial.print("Enter 'scan {location}' to start scanning");
    while(!Serial.available())
    {
      delay(200);
    }

    input= Serial.readStringUntil('\n');

    if(input.indexOf("scan")==0)
    {
      input.replace("scan", "");
      location = input;
    }
    else if (input == "stop")
    {
      location = "";
    }
   
  }  

}
