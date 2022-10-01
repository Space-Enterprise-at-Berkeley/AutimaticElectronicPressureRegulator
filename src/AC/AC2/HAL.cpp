#include "Hal.h"

namespace HAL {

    // INA219 chan0;
    // INA219 chan1;
    // INA219 chan2;
    // INA219 chan3;
    // INA219 chan4;
    // INA219 chan5;
    // INA219 chan6;
    // INA219 chan7;
    // INA219 chan8;
    // INA219 chan9;
    // INA219 chan10;

    HX711 lcAmp0;
    HX711 lcAmp1;

    MAX31855 tcAmp0;
    MAX31855 tcAmp1; 
    MAX31855 tcAmp2;
    MAX31855 tcAmp3; 
    MAX31855 tcAmp4;

    void initChannel(INA219 *channel, TwoWire *wire, uint8_t address) {
        channel->init(wire, address, chanShuntR, chanCurrMax, INA219_RANGE_32V, INA219_GAIN_160MV, INA219_BUS_RES_12BIT, INA219_SHUNT_RES_12BIT_1S, INA219_MODE_SHUNT_BUS_CONT);
    }

    void initHAL() {
        // Initialize I2C buses
        Wire.begin();
        Wire.setClock(1000000);
        Wire1.begin();
        Wire1.setClock(1000000);

        SPI1.begin();

        // MAX31855 TC amps (cs)
        tcAmp0.init(&SPI1, 8);
        tcAmp1.init(&SPI1, 9);
        tcAmp2.init(&SPI1, 10);
        tcAmp3.init(&SPI1, 13);
        tcAmp4.init(&SPI1, 20);

        // HX711 load cell amps (data out, clk)
        lcAmp0.init(40, 39);
        lcAmp1.init(35, 34);

        // initChannel(&chan4, &Wire, 0x44);
        // initChannel(&chan5, &Wire, 0x45);
        // initChannel(&chan6, &Wire, 0x46);
        // initChannel(&chan7, &Wire, 0x47);
        // initChannel(&chan8, &Wire, 0x48);
        // initChannel(&chan9, &Wire, 0x49);
        // initChannel(&chan10, &Wire, 0x4A);

        // Actuator control
        pinMode(hBrg1Pin1, OUTPUT);
        pinMode(hBrg1Pin2, OUTPUT);
        pinMode(hBrg2Pin1, OUTPUT);
        pinMode(hBrg2Pin2, OUTPUT);
        pinMode(hBrg3Pin1, OUTPUT);
        pinMode(hBrg3Pin2, OUTPUT);
        pinMode(hBrg4Pin1, OUTPUT);
        pinMode(hBrg4Pin2, OUTPUT);
        pinMode(hBrg5Pin1, OUTPUT);
        pinMode(hBrg5Pin2, OUTPUT);
        pinMode(hBrg6Pin1, OUTPUT);
        pinMode(hBrg6Pin2, OUTPUT);
        pinMode(hBrg7Pin1, OUTPUT);
        pinMode(hBrg7Pin2, OUTPUT);

        // Heater control
        pinMode(ctl12vChan1, OUTPUT);
        pinMode(ctl12vChan2, OUTPUT);
        pinMode(ctl24vChan1, OUTPUT);
        pinMode(ctl24vChan2, OUTPUT);
    }
};