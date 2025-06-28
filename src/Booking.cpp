#include "Booking.hpp"
#include <iostream>

Booking::Booking(std::string time, Vehicle* v, int hours)
    : timestamp(time), vehicle(v), duration(hours), fare(v->calculateFare(hours)) {}

void Booking::displayBooking() const {
    std::cout << "Booked: " << timestamp << ", Duration: " << duration << " hrs, Fare: " << fare << "\n";
    vehicle->displayInfo();
}

std::string Booking::getTimestamp() const { return timestamp; }
int Booking::getDuration() const { return duration; }
double Booking::getFare() const { return fare; }
Vehicle* Booking::getVehicle() const { return vehicle; }
