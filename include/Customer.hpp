#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>
#include "Booking.hpp"

class Customer {
    int customerId;
    std::string name;
    std::vector<Booking> bookings;

public:
    Customer(int id, const std::string& name);
    void addBooking(const Booking& booking);
    void showHistory() const;
    int getId() const;
    std:: string getName() const;
};

#endif
