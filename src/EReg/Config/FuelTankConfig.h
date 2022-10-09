//Fuel EReg Config 
#pragma once
#include "../FlowProfiles.h"

namespace Config {

    #define MAX_ANGLE 500                                                    
    #define MIN_ANGLE 0
    #define ANTIWINDUP_RANGE_LOWER 150
    #define ANTIWINDUP_RANGE_UPPER 500

    // Controller Constants
    const double p_outer_nominal = 1.0, i_outer_nominal = 0.7e-6, d_outer_nominal = 0.06; // nominal is 4000 -> 500 psi flow
    const double p_inner = 11, i_inner = 3.5e-6, d_inner = 0.10;

    // Flow Parameters
    const float pressureSetpoint = 550; // hotfire 7 was 495
    const unsigned long loxLead = 105UL * 1000UL; //time in milliseconds

    // Diagnostic configs
    const int servoTestPoints = 5;
    const float servoTravelInterval = 100; // encoder counts
    const unsigned long servoSettleTime =  200UL * 1000UL; // micros
    const float stopDiagnosticPressureThresh = 200; // diagnostic terminates if either tank exceeds this
    const float diagnosticSpeed = 200;
    
    // const float LOW_PT_C = 13.482;
    // const float LOW_PT_M = 1.2407;

    // const float HIGH_PT_C = 5.0;
    // const float HIGH_PT_M = 0.7973;
    // true = (measured - LOW_PT_C) / LOW_PT_M
}
