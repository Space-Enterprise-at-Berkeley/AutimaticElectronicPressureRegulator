#pragma once

namespace Config {

    #define MAX_SPD 255
    #define MIN_SPD -255
    // #define STATIC_SPD 60
    #define STATIC_SPD 0
    //old max angle = 1296
    //3200*48/26
    #define MAX_ANGLE 363
    #define MIN_ANGLE 0

    #define OPEN_LOOP_SPEED 200

    const double p_outer = 1.50, i_outer = 2.25e-6, d_outer = 0.125;
    const double p_inner = 11.5, i_inner = 1.5e-6, d_inner = 0.35e-6;

    const float pressureSetpoint = 500;
    const unsigned long flowDuration = 10UL * 1000UL * 1000UL; // time in microseconds TODO change to 5s
    const unsigned long rampDuration = 300UL * 1000UL; // time in microseconds

    // Diagnostic configs
    const float minAngleMovement = 300;
    const int servoTestPoints = 5;
    const float servoTravelInterval = 100; // encoder counts
    const unsigned long servoSettleTime = 200UL * 1000UL; // micros
    const float servoSettleThresh = 10; // encoder counts
}