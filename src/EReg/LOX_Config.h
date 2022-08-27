//LOX EReg Config 
#pragma once

namespace Config {

    // Controller Constants
    const double p_outer_nominal = 1.0, i_outer_nominal = 0.7e-6, d_outer_nominal = 0.06; // nominal is 4000 -> 500 psi flow
    const double p_inner = 11, i_inner = 3.5e-6, d_inner = 0.10;

    // Flow Parameters
    const float pressureSetpoint = 600;
    const unsigned long loxLead = 0; //time in milliseconds

    const float PT_C = 0.96;
    const float PT_M = 1.1889;
    // true = (measured - PT_C) / PT_M


}
