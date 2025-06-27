#include "RentalSystem.hpp"
#include "Booking.hpp"
#include <iostream>
#include <chrono>

void RentalSystem::addVehicle(std::shared_ptr<Vehicle> v){
    vehicles.push_back(v);
}

void RentalSystem::registerCustomer(const Customer& c){
    customers.push_back(c);
}


void RentalSystem::listVehicles() const {
    for(const auto& v : vehicles) {
       v->displayInfo();
       std::cout << (v->getAvailability() ? "Available\n" : "Not Available\n") << "\n";
    }
}


void RentalSystem::rentVehicle(int customerId, const std::string& regNum, int hours){
    for (auto& v : vehicles) {
        if(v->getRegistrationNumber() == regNum && v->getAvailability()){
	   v->setAvailability(false);
           //std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
           Booking booking("2025-06-27 12:00", v.get(), hours);

	   for (auto& c : customers){
		if (c.getId() == customerId) {
			c.addBooking(booking);
			std::cout << "Vehicle rented successfully to " << c.getName() << "!\n";
			return;
	   	}
	  }
	  
	  std::cout << "Customer not found. \n";
	  return;
	}

	}
	std::cout << "Vehicle not available or not found \n";
}
