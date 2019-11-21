#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include "serial.h"
#include "crc16.h"
#include "packet.h"
#include "sensor_constants.h"



int main()
{



    CedesToF::Serial serial;
    serial.open("/dev/ttyUSB0", 921600);
    while(true){
    if(serial.readByte() == uint8_t(CedesToF::StartByte::SOH)){
        std::cout << "Nice" << std::endl;}
        else if(serial.readByte() == uint8_t(CedesToF::StartByte::NAK)){
            std::cout << "Nicht OK" << std::endl;}

CedesToF::Packet mylovelypacket;
mylovelypacket.receiveFromSerial(serial);
mylovelypacket.print();
mylovelypacket.crcIsOkay();

}



    }



/*
 *
 *


        for (std::vector<uint8_t>::const_iterator i = ID_Buffer.begin(); i != ID_Buffer.end(); ++i){
            std::cout << *i << std::endl;
        }


    // Read 300 bytes and dump them as hex numbers on the console
	try
	{
		CedesToF::Serial serial;
		serial.open("/dev/ttyUSB0", 921600);
		for (unsigned int i = 0; i < 500; i++)
		{
			std::cout << std::hex << std::setfill('0') <<
				std::setw(2) << (int)serial.readByte() << " ";
		}
		serial.close();
	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << "\n";
	}
	return 0;

    */


