#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "Vehicle.hpp"

class Truck : public Vehicle {
    double loadCapacity; // in tons

public:
    Truck(const std::string& regNum, const std::string& brand, double rate, double load);
    void displayInfo() const override;
    double calculateFare(int hours) const override;
};

#endif
