#include "RentalSystem.hpp"
#include "Car.hpp"
#include "Bike.hpp"
#include "Truck.hpp"
#include <iostream>

int main() {
    RentalSystem system;

    if (!system.connectToDatabase("rental.db")) return 1;
    system.loadVehiclesFromDB();

    // Customer Input
    int id; std::string name;
    std::cout << "Enter customer ID: "; std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter customer name: "; std::getline(std::cin, name);

    Customer c(id, name);
    system.registerCustomer(c);
    system.saveCustomerToDB(c);

    system.listVehicles();

    std::string reg; int hrs;
    std::cout << "\nEnter vehicle reg number: "; std::getline(std::cin, reg);
    std::cout << "Enter duration in hours: "; std::cin >> hrs;

    system.rentVehicle(id, reg, hrs);

    // Return Option
    std::string choice;
    std::cout << "\nReturn vehicle? (y/n): ";
    std::cin >> choice;
    if (choice == "y" || choice == "Y") {
        std::cin.ignore();
        std::string regReturn;
        std::cout << "Enter registration number: ";
        std::getline(std::cin, regReturn);
        system.returnVehicle(regReturn);
    }

    return 0;
}
