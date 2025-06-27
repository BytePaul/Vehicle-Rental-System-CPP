#ifndef RENTAL_SYSTEM_HPP
#define RENTAL_SYSTEM_HPP

#include <vector>
#include <memory>
#include "Vehicle.hpp"
#include "Customer.hpp"

class RentalSystem {
   std::vector<std::shared_ptr<Vehicle>> vehicles;
   std::vector<Customer> customers;

public:
   void addVehicle(std::shared_ptr<Vehicle> v);
   void registerCustomer(const Customer& c);
   void rentVehicle(int customerId, const std::string& regNum, int hours);
   void listVehicles() const;
};

#endif
