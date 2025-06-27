#include "Customer.hpp"
#include <iostream>

Customer::Customer(int id, const std::string& name)
    : customerId(id), name(name) {}

void Customer::addBooking(const Booking& booking) {
    bookings.push_back(booking);
}

void Customer::showHistory() const {
    std::cout << "Booking History for " << name << " (ID: " << customerId << "):\n";
    for (const auto& b : bookings) {
        b.displayBooking();
    }
}

int Customer::getId() const {
    return customerId;
}

std::string Customer::getName() const {
    return name;
}
