#ifndef __GRAVITY_CAR_H__
#define __GRAVITY_CAR_H__

#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "Arduino.h"

#define JSON_BUFFER_SIZE          64
#define JSON_LEFT_BRAKE_TAG       "leftBrake"
#define JSON_RIGHT_BRAKE_TAG      "rightBrake"
#define JSON_STEERING_ANGLE_TAG   "steerAngle"

class GravityCar {
  public:
    GravityCar(int leftBrakePin, int rightBrakePin, int steeringAnglePin);

    void writeSerialJson(SoftwareSerial bluetooth);

    int getLeftBrake() const { return analogRead(mLeftBrakePin); }
    int getRightBrake() const { return analogRead(mRightBrakePin); }
    int getSteeringAngle() const { return analogRead(mSteeringAnglePin); }

  private:
    int mLeftBrakePin;
    int mRightBrakePin;
    int mSteeringAnglePin;

    StaticJsonDocument<JSON_BUFFER_SIZE> document;
};

#endif  /* __GRAVITY_CAR_H__ */
