## 🚗 Vehicle Rental System

A terminal-based Vehicle Rental System written in modern C++ (C++17) with SQLite3 for persistent data storage and CMake for build management.

## 📦 Features

- Load vehicle data from an SQLite database
- Register new customers interactively
- Rent vehicles and track rentals
- Store customer and booking details in the database
- Return vehicles and mark them available again
- Object-oriented architecture using C++, STL, and smart pointers

## 📁 Project Structure
```
vehicle-rental-system/
├── include/              # Header files (Vehicle, Car, Bike, etc.)
├── src/                  # Implementation files
├── data/                 # SQLite database and schema
│   ├── rental.db         # Active SQLite3 database
│   └── rental.sql        # Schema + initial data
├── main.cpp              # Entry point
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```
## 🛠️ Prerequisites

- C++17 compatible compiler
- SQLite3 development library
  - Ubuntu: sudo apt install libsqlite3-dev
- CMake ≥ 3.10

## ⚙️ Build Instructions

### 1. Clone the Repository

git clone https://github.com/your-username/vehicle-rental-system.git
cd vehicle-rental-system

### 2. Create the SQLite Database

Run this command to initialize the database with tables and sample data:

sqlite3 data/rental.db < data/rental.sql

### 3. Build the Project

mkdir build
cd build
cmake ..
make

### 4. Run the Program

./VehicleRentalSystem ../data/rental.db

## 🧪 Example Interaction
´´
Enter customer ID: 101
Enter customer name: Alice

Available vehicles:
Car - Toyota [KA01AB1234], Seats: 5, Rate/hr: 50
Bike - Yamaha [KA02ZX7890], Gear: Yes, Rate/hr: 30
Truck - Tata [KA03TR9988], Load: 12 tons, Rate/hr: 80

Enter vehicle reg number: KA01AB1234
Enter duration in hours: 4
Vehicle rented successfully to Alice!

Return vehicle? (y/n): y
Enter registration number: KA01AB1234
Vehicle KA01AB1234 returned successfully.
´´
## ✅ To Do

- Add login functionality (admin/customer)
- Export booking history to CSV
- Add time-based auto return logic
- Add unit tests with Catch2 or Google Test

## 📚 Technologies Used

- C++17
- SQLite3
- CMake
- STL (vector, map, memory, etc.)

## 👨‍💻 Author

Paul Gaikwad

## 📄 License

This project is open-source and available under the MIT License.
