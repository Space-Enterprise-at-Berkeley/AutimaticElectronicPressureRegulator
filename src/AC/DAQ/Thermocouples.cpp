#include "Thermocouples.h"

namespace Thermocouples {
    uint32_t tcUpdatePeriod = 100 * 1000;
    Comms::Packet readingPacket = {.id = 110};
    Comms::Packet tcAbortPacket = {.id = 30};
    float tempBuffer[Config::numberOfTC][Config::tempBufferSize];
    int buffer_i;

    void initThermocouples() {
        buffer_i = 0;
    }

    uint32_t checkForAbort() {
        //check thermocouple temperatures to be below a threshold
        
        for (int tcNumber = 0; tcNumber < Config::numberOfTC; tcNumber++) {
            int aboveThresholdCount = 0;

            for(int i = 0; i < Config::tempBufferSize; i++){
                if (tempBuffer[tcNumber][i] >= Config::temperatureThreshold) {
                    aboveThresholdCount++;
                }
            }

            if (aboveThresholdCount >= Config::tempNumberThreshold) {
                DEBUGF("Temperature abort triggered by TC %d!\n", tcNumber);
                // Comms::emitPacket(&tcAbortPacket, 21);
                sendTCAbortPackets();
            }
        }
        
        return tcUpdatePeriod;
    }

    void sendTCAbortPackets() {
        // Comms::Packet abortMessage = {.id = 1, .len = 0};
        // Comms::emitPacket(&abortMessage, FUEL_TANK_EREG_ADDR);
        // Comms::emitPacket(&abortMessage, FUEL_INJECTOR_EREG_ADDR);
        // Comms::emitPacket(&abortMessage, LOX_TANK_EREG_ADDR);
        // Comms::emitPacket(&abortMessage, LOX_INJECTOR_EREG_ADDR);
        // Comms::emitPacket(&abortMessage, AC_EREG_ADDR);
        // Comms::emitPacket(&abortMessage, DAQ_EREG_ADDR);
    }

    uint32_t sendTCReadingPacket(){

        MAX31855* amps[] = {&HAL::tcAmp0, &HAL::tcAmp1, &HAL::tcAmp2};
        // DEBUGLN("TC readings ");
        for(int i = 0; i < Config::numberOfTC; i++){
            tempBuffer[i][buffer_i] = amps[i]->readCelsius();
            Comms::packetAddFloat(&readingPacket, tempBuffer[i][buffer_i]);            
            DEBUG(" " + String(tempBuffer[i][buffer_i]));
        }
        DEBUGLN("");
        buffer_i = (buffer_i + 1) % Config::tempBufferSize;
        // Serial.println("emitting packet");
        Comms::emitPacket(&readingPacket);
        // Serial.println("emitted packet " + String(millis()));
        return tcUpdatePeriod;

    }
    

};
