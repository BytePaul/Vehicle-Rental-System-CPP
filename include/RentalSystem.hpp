#ifndef RENTAL_SYSTEM_HPP
#define RENTAL_SYSTEM_HPP

#include <vector>
#include <memory>
#include <string>
#include "Vehicle.hpp"
#include "Customer.hpp"
#include <sqlite3.h>

class RentalSystem {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::vector<Customer> customers;
    sqlite3* db = nullptr;

public:
    // Basic operations
    void addVehicle(std::shared_ptr<Vehicle> v);
    void registerCustomer(const Customer& c);
    void rentVehicle(int customerId, const std::string& regNum, int hours);
    void listVehicles() const;

    // Database support
    bool connectToDatabase(const std::string& dbPath);
    void loadVehiclesFromDB();
    void saveCustomerToDB(const Customer& customer);
    void saveBookingToDB(const Booking& booking, int customerId);
    void returnVehicle(const std::string& regNum);  // new method

};

#endif
