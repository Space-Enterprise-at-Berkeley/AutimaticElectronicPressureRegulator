//LOX EReg Config 
#pragma once
#include "../FlowProfiles.h"

namespace Config {

    #define MAX_ANGLE 650                                                    
    #define MIN_ANGLE 0
    #define ANTIWINDUP_RANGE_LOWER 150
    #define ANTIWINDUP_RANGE_UPPER 650

    #define OUTER_BUFFER_SIZE 3

    // Controller Constants
    const double p_outer_nominal = 1.8, i_outer_nominal = 0.45e-6, d_outer_nominal = 0.24; // nominal is 4000 -> 500 psi flow
    const double p_inner = 6, i_inner = 3.5e-6, d_inner = 0.10;

    // Flow Parameters
    const float pressureSetpoint = 600;
    const unsigned long loxLead = 0; //time in microseconds

    // Diagnostic configs
    const int servoTestPoints = 5;
    const float servoTravelInterval = 100; // encoder counts
    const unsigned long servoSettleTime =  200UL * 1000UL; // micros
    const float stopDiagnosticPressureThresh = 200; // diagnostic terminates if either tank exceeds this
    const float diagnosticSpeed = 200; // speed at which to run open loop motors
}
