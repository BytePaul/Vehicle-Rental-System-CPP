cmake_minimum_required(VERSION 3.10)
project(VehicleRentalSystem)

set(CMAKE_CXX_STANDARD 17)

# Add include and source directories
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Check for SQLite3
find_package(SQLite3 REQUIRED)

add_executable(VehicleRentalSystem ${SOURCES})

# Link SQLite3
target_link_libraries(VehicleRentalSystem SQLite::SQLite3)
