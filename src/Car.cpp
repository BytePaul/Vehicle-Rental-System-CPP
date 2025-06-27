#include "Car.hpp"
#include <iostream>

Car::Car(std::string regNum, std::string brand, double rate, int seats)
    : Vehicle(regNum, brand, rate), seatCount(seats) {}

void Car::displayInfo() const {
    std::cout << "Car - " << brand << " [" << registrationNumber << "], Seats: " << seatCount
              << ", Rate/hr: " << baseRate << "\n";
}

double Car::calculateFare(int hours) const {
    return baseRate * hours;
}
