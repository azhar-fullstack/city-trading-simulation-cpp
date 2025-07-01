# City Trading Simulation (C++)

A simulation of city trading and river transport, implemented in C++. Demonstrates advanced OOP, resource management, and system design.

## 🌆 Project Overview
This project simulates a network of cities connected by rivers, where boats transport products between cities. The system manages inventories, products, and trading logic, providing a rich simulation of economic and logistical challenges.

## ✨ Features
- **City and River System:** Model cities, rivers, and their connections
- **Boat Transport:** Simulate boats moving products between cities
- **Inventory Management:** Track products and quantities in each city
- **Product Trading:** Buy, sell, and transport products
- **OOP Design:** Modular code with classes for boats, cities, products, inventory, and river systems

## 🛠️ Technologies Used
- C++ (OOP, STL)
- Modular design (multiple .cpp/.h files)
- Console I/O

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)

### Build Instructions
#### Using Makefile (recommended)
```bash
make
```
#### Or compile manually:
```bash
g++ -o riversystem main.cpp Boat.cpp City.cpp Inventory.cpp Product.cpp RiverSystem.cpp
```

### Run the Simulation
```bash
./riversystem
```
Or on Windows:
```bash
riversystem.exe
```

## 🎮 Controls
- Follow on-screen prompts to:
  - Add or remove products
  - Move boats between cities
  - View inventories
  - Trade products
- Input choices as numbers or text when prompted.

## 📁 Project Structure
```
city-trading-simulation-cpp/
├── Boat.cpp/.h         # Boat class
├── City.cpp/.h         # City class
├── Inventory.cpp/.h    # Inventory management
├── Product.cpp/.h      # Product class
├── RiverSystem.cpp/.h  # River system and trading logic
├── main.cpp            # Main entry point
├── riversystem.exe     # Compiled executable (ignore in repo)
└── README.md           # This file
```

## 🧑‍💻 Skills Demonstrated
- C++ OOP (classes, encapsulation)
- System and resource management
- Simulation and modeling
- Modular code organization
- Interactive CLI design


## 📄 License
This project is open source and available under the MIT License.

---
**Author:** Azhar Mehmood
**Language:** C++
**Category:** Simulation, Algorithms, Resource Management 
