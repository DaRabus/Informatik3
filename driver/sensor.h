#ifndef SENSOR_H
#define SENSOR_H



#include "serial.h"
#include "packet.h"



namespace CedesToF
{



class Sensor
{
public:
    Sensor();

    void open(const std::string &device);
    bool isOpen() const;
    void close();
    void flush();

    std::string getIdAndVersion();
    void setIntegrationTimeAuto();
    void setIntegrationTimeManual(double timeMicroSeconds);
    void setDelayTime(uint16_t delayMilliseconds);

    double getDistanceMillimeters();
    void getDistanceImage(std::vector<double> &distances);
    void getIntensityImage(std::vector<double> &intensities);

private:
    void setKindOfData(uint8_t typeOfData);

    void handleReceive(Id id, Packet &response);
    void handleSendReceive(Packet &request, Packet &response);

    Serial serial;
};



}	// namespace CedesToF



#endif // SENSOR_H
