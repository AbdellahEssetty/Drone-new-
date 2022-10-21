#include <Arduino.h>
#include "Motor.h"

Motor m = Motor(7);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(m.getSpeed());

  if(Serial.available() > 0)
  {
    size_t iSpeed = Serial.read();
    Serial.print(iSpeed - 48);
    Serial.print(',');
    m.updateSpeed(iSpeed - 48);
  }

  delay(1000);
}