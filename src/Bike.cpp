#include "Bike.hpp"
#include <iostream>

Bike::Bike(const std::string& regNum, const std::string& brand, double rate, bool gear)
    : Vehicle(regNum, brand, rate), hasGear(gear) {}

void Bike::displayInfo() const {
    std::cout << "Bike - " << brand 
              << " [" << registrationNumber << "], Gear: " 
              << (hasGear ? "Yes" : "No") 
              << ", Rate/hr: " << baseRate << "\n";
}

double Bike::calculateFare(int hours) const {
    double gearCharge = hasGear ? 5.0 : 0.0;
    return (baseRate + gearCharge) * hours;
}
