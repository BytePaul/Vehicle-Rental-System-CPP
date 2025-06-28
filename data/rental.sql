-- rental.sql

-- Create Vehicles table
CREATE TABLE IF NOT EXISTS Vehicles (
    type TEXT NOT NULL,
    reg_no TEXT PRIMARY KEY,
    brand TEXT NOT NULL,
    rate REAL NOT NULL,
    seats_or_gear_or_load INTEGER NOT NULL
);

-- Create Customers table
CREATE TABLE IF NOT EXISTS Customers (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL
);

-- Create Bookings table
CREATE TABLE IF NOT EXISTS Bookings (
    booking_id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    reg_no TEXT NOT NULL,
    timestamp TEXT NOT NULL,
    duration INTEGER NOT NULL,
    fare REAL NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES Customers(id),
    FOREIGN KEY (reg_no) REFERENCES Vehicles(reg_no)
);

-- Optional: Insert sample vehicles
INSERT OR IGNORE INTO Vehicles VALUES ('Car', 'KA01AB1234', 'Toyota', 50.0, 5);
INSERT OR IGNORE INTO Vehicles VALUES ('Bike', 'KA02ZX7890', 'Yamaha', 30.0, 1);
INSERT OR IGNORE INTO Vehicles VALUES ('Truck', 'KA03TR9988', 'Tata', 80.0, 12);
