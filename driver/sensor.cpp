#include <algorithm>
#include <cmath>
#include <iostream>
#include "packet.h"
#include "sensor.h"



namespace CedesToF
{



Sensor::Sensor()
{
}



void Sensor::open(const std::string &device)
{
	serial.open(device, 921600);
	setKindOfData(KindOfDataDistanceOnly);
}



bool Sensor::isOpen() const
{
	return serial.isOpen();
}



void Sensor::close()
{
	serial.close();
}



void Sensor::flush()
{
	serial.flush();
}



std::string Sensor::getIdAndVersion()
{
	Packet request(Id::GetIdAndVersion);
	Packet response;
	handleSendReceive(request, response);
	std::string result;
	for (size_t i = 0; i < response.getLength(); i++)
		result += static_cast<char>(response.getData(i));
	return result;
}



void Sensor::setIntegrationTimeAuto()
{
	// TODO
}



void Sensor::setIntegrationTimeManual(double timeMicroSeconds)
{
    Serial sIT;
    sIT.writeByte(timeMicroSeconds);
	// TODO
}



void Sensor::setDelayTime(uint16_t delayMilliseconds)
{
   // Serial setDelayTime; //Programm crashes?
    // setDelayTime.writeByte(delayMilliseconds);
}



double Sensor::getDistanceMillimeters()
{
    Packet request(Id::DistanceOnly);
    Packet response;
    handleSendReceive(request, response);
    double result;
    for (size_t i = 0; i < response.getLength(); i++)
        result += static_cast<double>(response.getData(i));
    return result;
}



void Sensor::getDistanceImage(std::vector<double> &distances)
{
	// TODO
}



void Sensor::getIntensityImage(std::vector<double> &intensities)
{
	// TODO
}



void Sensor::setKindOfData(uint8_t typeOfData)
{
	Packet request(Id::SetKindOfData, { typeOfData });
	Packet response;
	handleSendReceive(request, response);
}



void Sensor::handleReceive(Id id, Packet &response)
{
	while (true)
	{
		if (!response.receiveFromSerial(serial))
		{
			continue;
		}
		if (response.getId() == id)
		{
			return;
		}
		std::cout << "Skipping packet: ";
		response.print();
		std::cout << std::endl;
	}
}



void Sensor::handleSendReceive(Packet &request, Packet &response)
{
	int skipCounter = 0;
	while (true)
	{
		// Send request
		if (skipCounter == 0)
		{
			request.sendToSerial(serial);
            //std::cout << "Request: ";
            request.print();
            //std::cout << std::endl;
			skipCounter = 3;
		}
		// Try to get reply
		if (!response.receiveFromSerial(serial))
		{
			continue;
		}
		// If we got one with the same Id: great, we are done
		if (response.getId() == request.getId())
		{
            //std::cout << "Response: ";
			response.print();
            //std::cout << std::endl;
			return;
		}
		skipCounter--;
        //std::cout << "Skipping packet: ";
		response.print();
        //std::cout << std::endl;
	}
}



} // namespace CedesToF
