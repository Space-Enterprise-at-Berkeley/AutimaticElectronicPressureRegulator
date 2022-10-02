#include "Ereg.h"

namespace EReg {

    Comms::Packet generalAbortPacket = { .id = HAL::eregAbortID }; //TODO figure out if this will broadcast to all?

    Comms::Packet eregStartFlowPacket = {.id = HAL::eregStartFlowID};
    Comms::Packet eregAbortPacket = {.id = HAL::eregAbortID};

    ERegBoard fuelTankBoard(HAL::fuelTankEndIp, 1);
    ERegBoard loxTankBoard(HAL::loxTankEndIp, 2); //TODO dont need id anymore
    ERegBoard fuelInjectorBoard(HAL::fuelInjectorEndIp, 3);
    ERegBoard loxInjectorBoard(HAL::loxInjectorEndIp, 4);


    ERegBoard *eregBoards[4] = { &fuelTankBoard, &loxTankBoard, &fuelInjectorBoard, &loxInjectorBoard };

    float fuelTankPTValue;
    float loxTankPTValue;
    float fuelInjectorPTValue;
    float loxInjectorPTValue;

    void initEReg() {
        Comms::registerCallback(1, interpretTelemetry);
    }

    void abort() {
        for(ERegBoard *board : eregBoards)
            Comms::emitPacket(&eregAbortPacket, (uint8_t) board->ip_address);
        Comms::emitPacket(&generalAbortPacket, HAL::daqEndIp);
    }

    void startFlow() {
        for(ERegBoard *board : eregBoards)
            Comms::emitPacket(&eregStartFlowPacket, (uint8_t) board->ip_address);
        Comms::emitPacket(&generalAbortPacket, HAL::daqEndIp);    
    }

    void interpretTelemetry(Comms::Packet packet, uint8_t ip) {
        //read PT Values
        float highPT = Comms::packetGetFloat(&packet, 0);
        float lowPT = Comms::packetGetFloat(&packet, 4);

        if (ip == fuelTankBoard.ip_address) {
            fuelTankPTValue =  lowPT;
        } else if (ip == loxTankBoard.ip_address) {
            loxTankPTValue = lowPT;
        } else if (ip == fuelInjectorBoard.ip_address) {
            fuelInjectorPTValue = fuelInjectorPTValue;
        } else if (ip == loxInjectorBoard.ip_address) {
            loxInjectorPTValue = loxInjectorPTValue;
        }
    }

}

