#ifndef BIKE_HPP
#define BIKE_HPP

#include "Vehicle.hpp"

class Bike : public Vehicle {
    bool hasGear;

public:
    Bike(const std::string& regNum, const std::string& brand, double rate, bool hasGear);
    void displayInfo() const override;
    double calculateFare(int hours) const override;
};

#endif
