#include <iostream>
#include <iomanip>
#include "packet.h"
#include "crc16.h"



namespace CedesToF
{



Packet::Packet() :
    startByte(StartByte::NAK),
    id(Id::NotAllowed),
    data(),
    crc(0)
{
}



Packet::Packet(Id id) :
    startByte(StartByte::SOH),
    id(id),
    data()
{
    crc = CalculateCrc();
}



Packet::Packet(Id id, const std::vector<uint8_t> &data) :
    startByte(StartByte::SOH),
    id(id),
    data(data)
{
    crc = CalculateCrc();
}



Id Packet::getId()
{
    return id;
}



size_t Packet::getLength()
{
    return data.size();
}



uint8_t Packet::getData(size_t index)
{
    return data[index];
}



bool Packet::crcIsOkay()
{
    return crc == CalculateCrc();
}



bool Packet::receiveFromSerial(Serial &serial)
{
    // Start byte
    while (true)
    {
        uint8_t byte = serial.readByte();
        if ((byte == static_cast<uint8_t>(StartByte::ACK)) ||
            (byte == static_cast<uint8_t>(StartByte::NAK)))
        {
            startByte = static_cast<StartByte>(byte);
            break;
        }
        // Skip non-start-bytes
        std::cout << "Skipping byte " << std::hex << std::setfill('0') <<
            std::setw(2) << (int)byte << "(" << byte << ")\n";
    }
    // ID
    id = (Id)serial.readByte();
    if (!IdIsValid(id))
    {
        std::cout << "Unknown id " << std::hex << std::setfill('0') <<
            std::setw(2) << (int)id << "\n";
        return false;
    }
    // Length
    uint16_t length = serial.readByte() << 8;
    length |= serial.readByte();
    if (length < sizeof(uint16_t))
    {
        std::cout << "Insufficient length " << length << "\n";
        return false;
    }
    length -= sizeof(uint16_t);
    if (length != IdToExpectedResponseLength(id))
    {
        std::cout << "Unexpected length for " << IdToString(id) << ": " << length << " vs. "
            << IdToExpectedResponseLength(id) << "\n";
        return false;
    }
    // Data
    data.clear();
    for (uint16_t i = 0; i < length; i++)
    {
        data.push_back(serial.readByte());
    }
    // Crc
    crc = serial.readByte() << 8;
    crc |= serial.readByte();
    if (!crcIsOkay())
        return false;
    return true;
}



void Packet::sendToSerial(Serial &serial)
{
    std::vector<uint8_t> sendBuffer;
    // Start byte
    sendBuffer.push_back(static_cast<uint8_t>(startByte));
    // ID
    sendBuffer.push_back(static_cast<uint8_t>(id));
    // Length
    uint16_t length = data.size() + sizeof(uint16_t);
    sendBuffer.push_back(static_cast<uint8_t>((length >> 8) & 0xff));
    sendBuffer.push_back(static_cast<uint8_t>(length & 0xff));
    // Data
    sendBuffer.insert(sendBuffer.end(), data.begin(), data.end());
    // Crc
    sendBuffer.push_back(static_cast<uint8_t>((crc >> 8) & 0xff));
    sendBuffer.push_back(static_cast<uint8_t>(crc & 0xff));
    // Send to serial
    serial.writeBuffer(sendBuffer);
}



void Packet::print()
{
    // Start byte
    std::cout << StartByteToString(startByte) << " (" << std::hex << std::setfill('0')
              << std::setw(2) << (int)startByte << "), ";
    // ID
    std::cout << IdToString(id) << " (" << std::hex << std::setfill('0')
              << std::setw(2) << (int)id << "), ";
    // Data
    if (data.empty())
    {
        std::cout << "No data, ";
    }
    else
    {
        std::cout << "Data " << std::dec << data.size() << " bytes: ( ";
        std::string sep = "";
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << sep << std::hex << std::setfill('0')
                      << std::setw(2) << (int)data[i];
            sep = ", ";
        }
        std::cout << " ), ";
    }
    // Crc
    std::cout << std::hex << std::setfill('0')
              << std::setw(4) << crc;
    if (crcIsOkay())
    {
        std::cout << " (OK)";
    }
    else
    {
        std::cout << " (ERROR)";
    }
}



uint16_t Packet::CalculateCrc()
{
    Crc16 calculatedCrc;
    calculatedCrc.update(static_cast<uint8_t>(startByte));
    calculatedCrc.update(static_cast<uint8_t>(id));
    // For CRC calculation, length is data length plus length of CRC!
    uint16_t length = data.size() + sizeof(uint16_t);
    calculatedCrc.update(length >> 8);
    calculatedCrc.update(length & 0xff);
    for (const uint8_t &byte : data)
        calculatedCrc.update(byte);
    return calculatedCrc.get();
}



} // namespace CedesToF
