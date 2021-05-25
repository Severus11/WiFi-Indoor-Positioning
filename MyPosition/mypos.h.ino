#include "WiFi.h"
#include "converter1.h"
#include "classifier1.h"

Eloquent::Projects::WifiIndoorPositioning positioning;
Eloquent::ML::Port::DecisionTree classifier;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up...");
}

void loop() {
  Serial.println("Now in void loop");
  positioning.scan();
  Serial.print("You're in ");
  Serial.println(classifier.predictLabel(positioning.features));
  delay(3000);
}
