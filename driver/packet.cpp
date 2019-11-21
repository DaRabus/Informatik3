#include "packet.h"
#include "serial.h"
#include "crc16.h"
#include "sensor_constants.h"
#include <iostream>


namespace CedesToF
{




Packet Packet(Id id){

}

bool Packet::receiveFromSerial(Serial &serial){

}

Id getId(){

return getId();

}
size_t getLength(){

}

uint8_t getData(size_t index){

}
bool crcIsOkay(){
    CedesToF::Serial CRC;
    size_t length = 1;
    std::vector<uint8_t> CRC_Buffer;
    CRC.readBuffer(CRC_Buffer,length);
    //std::cout << CedesToF::CalculateCrc16(CRC_Buffer) << std::endl; //Printout the Sum before checking it.

    //Code for calculating Checksum
    unsigned char ser_data;
    static unsigned int crc;
    CRC_Buffer.front() = crc;
    crc = (unsigned char)(crc >> 8) | (crc << 8);
    crc ^= ser_data;
    crc ^= (unsigned char)(crc & 0xff) >> 4;
    crc ^= (crc << 8) << 4;
    crc ^= ((crc & 0xff) << 4) << 1;

    if(crc == 0){ //Check chesum and return boolean result
        std::cout << "Wir sind OK" << std::endl;
        return true;
    }
    else{
        std::cout << "Wir sind NichtOK" << std::endl;
        return false;
    }
}

void sendToSerial(Serial &serial){

}
void print(){

}
}
