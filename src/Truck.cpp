#include "Truck.hpp"
#include <iostream>


Truck::Truck(const std::string& regNum, const std::string& brand, double rate, double load) : Vehicle(regNum, brand, rate), loadCapacity(load) {};

void Truck::displayInfo() const {
    std::cout << "Truck - " << brand
              << "[" << registrationNumber << "], Load: "
     	      << loadCapacity << " tons. Rate/hr: " << baseRate << "/n";
}


double Truck::calculateFare(int hours) const{
    return baseRate * hours + (loadCapacity * 2);

}
