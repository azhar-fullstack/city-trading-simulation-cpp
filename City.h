#ifndef CITY_H
#define CITY_H

#include <string>
#include "Inventory.h"

class City {
private:
    std::string name;
    Inventory inventory;

public:
    explicit City(const std::string& name);
    std::string getName() const;
    Inventory& getInventory();
    const Inventory& getInventory() const; // Add const version of getInventory
};

#endif
