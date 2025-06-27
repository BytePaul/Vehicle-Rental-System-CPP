#include "RentalSystem.hpp"
#include "Car.hpp"

int main() {
    RentalSystem system;

    auto car1 = std::make_shared<Car>("KA01AB1234", "Toyota", 50.0, 5);
    system.addVehicle(car1);

    Customer cust1(101, "Alice");
    system.registerCustomer(cust1);

    system.listVehicles();
    system.rentVehicle(101, "KA01AB1234", 4);

    return 0;
}
