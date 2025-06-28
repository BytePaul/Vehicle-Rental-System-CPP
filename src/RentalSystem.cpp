#include "RentalSystem.hpp"
#include "Booking.hpp"
#include "Car.hpp"
#include "Bike.hpp"
#include "Truck.hpp"
#include <iostream>
#include <sqlite3.h>

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
            Booking booking("2025-06-27 12:00", v.get(), hours); // Replace with timestamp logic if needed

            for (auto& c : customers){
                if (c.getId() == customerId) {
                    c.addBooking(booking);
					saveBookingToDB(booking, customerId);
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

bool RentalSystem::connectToDatabase(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db)) {
        std::cerr << "Failed to connect to database: " << sqlite3_errmsg(db) << "\n";
        return false;
    }
    return true;
}

void RentalSystem::loadVehiclesFromDB() {
    const char* query = "SELECT type, reg_no, brand, rate, seats_or_gear_or_load FROM Vehicles";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare SELECT statement: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string reg = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string brand = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        double rate = sqlite3_column_double(stmt, 3);
        int value = sqlite3_column_int(stmt, 4);

        if (type == "Car") {
            vehicles.push_back(std::make_shared<Car>(reg, brand, rate, value));
        } else if (type == "Bike") {
            vehicles.push_back(std::make_shared<Bike>(reg, brand, rate, value));
        } else if (type == "Truck") {
            vehicles.push_back(std::make_shared<Truck>(reg, brand, rate, static_cast<double>(value)));
        }
    }

    sqlite3_finalize(stmt);
}

void RentalSystem::saveCustomerToDB(const Customer& customer) {
    std::string sql = "INSERT INTO Customers (id, name) VALUES (?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, customer.getId());
        sqlite3_bind_text(stmt, 2, customer.getName().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Failed to insert customer: " << sqlite3_errmsg(db) << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to prepare INSERT statement: " << sqlite3_errmsg(db) << "\n";
    }
}

void RentalSystem::saveBookingToDB(const Booking& booking, int customerId) {
    std::string sql = "INSERT INTO Bookings (customer_id, reg_no, timestamp, duration, fare) VALUES (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, customerId);
        sqlite3_bind_text(stmt, 2, booking.getVehicle()->getRegistrationNumber().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, booking.getTimestamp().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, booking.getDuration());
        sqlite3_bind_double(stmt, 5, booking.getFare());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Failed to insert booking: " << sqlite3_errmsg(db) << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to prepare INSERT statement (Bookings): " << sqlite3_errmsg(db) << "\n";
    }
}

void RentalSystem::returnVehicle(const std::string& regNum) {
    for (auto& v : vehicles) {
        if (v->getRegistrationNumber() == regNum) {
            v->setAvailability(true);
            std::cout << "Vehicle " << regNum << " returned successfully.\n";
            return;
        }
    }
    std::cout << "Vehicle not found in system.\n";
}
