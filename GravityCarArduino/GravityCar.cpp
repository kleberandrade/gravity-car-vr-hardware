#include "GravityCar.h"

GravityCar::GravityCar(int leftBrakePin, int rightBrakePin, int steeringAnglePin) {
  pinMode(leftBrakePin, INPUT);
  pinMode(rightBrakePin, INPUT);
  pinMode(steeringAnglePin, INPUT);

  mLeftBrakePin = leftBrakePin;
  mRightBrakePin = rightBrakePin;
  mSteeringAnglePin = steeringAnglePin;
}

void GravityCar::writeSerialJson(SoftwareSerial bluetooth) {
  document[JSON_LEFT_BRAKE_TAG] = getLeftBrake();
  document[JSON_RIGHT_BRAKE_TAG] = getRightBrake();
  document[JSON_STEERING_ANGLE_TAG] = getSteeringAngle();

  serializeJson(document, bluetooth);
  bluetooth.print("\n");
  bluetooth.flush();

  serializeJson(document, Serial);
  Serial.print("\n");
  Serial.flush();
}
