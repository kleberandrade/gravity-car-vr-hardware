#include "GravityCar.h"

#define PIN_LEFT_BRAKE      A1
#define PIN_RIGHT_BRAKE     A3
#define PIN_STEERING_ANGLE  A2

#define PIN_BLUETOOTH_RX  2
#define PIN_BLUETOOTH_TX  3

#define SERIAL_BAUD_RATE    9600
#define INTERVAL            10

SoftwareSerial BTSerial(PIN_BLUETOOTH_RX, PIN_BLUETOOTH_TX);
GravityCar car(PIN_LEFT_BRAKE, PIN_RIGHT_BRAKE, PIN_STEERING_ANGLE);

long previousMillis = 0;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  BTSerial.begin(SERIAL_BAUD_RATE);
}

void loop() {
  car.writeSerialJson(BTSerial);
  delayMicroseconds(INTERVAL);
}
