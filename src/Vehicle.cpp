#include "Vehicle.hpp"

Vehicle::Vehicle(std::string regNum, std::string brand, double rate)
    : registrationNumber(regNum), brand(brand), baseRate(rate), isAvailable(true) {}

bool Vehicle::getAvailability() const {
    return isAvailable;
}

void Vehicle::setAvailability(bool status) {
    isAvailable = status;
}

std::string Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}
