#ifndef BOOKING_HPP
#define BOOKING_HPP

#include "Vehicle.hpp"
#include <string>

class Booking {
    std::string timestamp;
    Vehicle* vehicle;
    int duration;
    double fare;

public:
    Booking(std::string time, Vehicle* v, int hours);
    void displayBooking() const;
    std::string getTimestamp() const;
    int getDuration() const;
    double getFare() const;
    Vehicle* getVehicle() const;

};

#endif
