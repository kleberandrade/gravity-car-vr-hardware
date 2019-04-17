#ifndef __GRAVITY_CAR_H__
#define __GRAVITY_CAR_H__

#include <ArduinoJson.h>
#include "Arduino.h"

#define JSON_BUFFER_SIZE          128
#define JSON_LEFT_BRAKE_TAG       "LB"
#define JSON_RIGHT_BRAKE_TAG      "RB"
#define JSON_STEERING_ANGLE_TAG   "SA"

#define JSON_LEFT_MOTOR_TAG       "LM"
#define JSON_RIGHT_MOTOR_TAG      "RM"
#define JSON_FAN_SPEED_TAG        "FA"

class GravityCar {
  public:
    GravityCar(int leftBrakePin, int rightBrakePin, int steeringAnglePin, int leftMotorPin, int rightMotorPin, int fanSpeedPin);

    void writeSerialJson(void);
    void readSerialJson(void);

    int getLeftBrake() const { return analogRead(mLeftBrakePin); }
    int getRightBrake() const { return analogRead(mRightBrakePin); }
    int getSteeringAngle() const { return analogRead(mSteeringAnglePin); }

    int getLeftMotor() const { return mLeftMotor; }
    int getRightMotor() const { return mRightMotor; }
    int getFanSpeed() const { return mFanSpeed; }

    String getIncomingCommand() const { return incomingCommand; }

    void setLeftMotor(int leftMotor);
    void setRightMotor(int rightMotor);
    void setFanSpeed(int fanSpeed);

  private:
    int mLeftBrakePin;
    int mRightBrakePin;
    int mSteeringAnglePin;

    int mLeftMotorPin;
    int mRightMotorPin;
    int mFanSpeedPin;

    int mLeftBrakeOffset;
    int mRightBrakeOffset;
    int mSteeringAngleOffset;

    int mLeftMotor;
    int mRightMotor;
    
    volatile int mFanSpeed;

    String incomingCommand;
};

#endif  /* __GRAVITY_CAR_H__ */
