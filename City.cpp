#include "City.h"

City::City(const std::string& name) : name(name) {}

std::string City::getName() const { return name; }

Inventory& City::getInventory() { return inventory; }
const Inventory& City::getInventory() const { return inventory; } // Implementation for the const version
