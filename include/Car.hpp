#ifndef CAR_HPP
#define CAR_HPP

#include "Vehicle.hpp"

class Car : public Vehicle {
    int seatCount;

public:
    Car(std::string regNum, std::string brand, double rate, int seats);
    void displayInfo() const override;
    double calculateFare(int hours) const override;
};

#endif

