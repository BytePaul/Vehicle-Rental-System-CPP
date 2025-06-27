#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle {

protected:
   std::string registrationNumber;
   std::string brand;
   double baseRate;
   bool isAvailable;

public: 
   Vehicle(std::string regNum, std:: string brand, double rate);
   virtual void displayInfo() const = 0;
   virtual double calculateFare(int hours) const = 0;
   virtual ~Vehicle() {}

   bool getAvailability() const;
   void setAvailability(bool status);
   std::string getRegistrationNumber() const;

};


#endif
