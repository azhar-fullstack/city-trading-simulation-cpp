#include "Boat.h"
#include <iostream>

Boat::Boat() : buyProductId(0), sellProductId(0), buyUnits(0), sellUnits(0) {}

void Boat::modify(int buyId, int buyUnits, int sellId, int sellUnits) {
    buyProductId = buyId;
    this->buyUnits = buyUnits;
    sellProductId = sellId;
    this->sellUnits = sellUnits;
}

void Boat::printBoatData() const {
    std::cout << "Buying Product ID: " << buyProductId << ", Units: " << buyUnits
              << "\nSelling Product ID: " << sellProductId << ", Units: " << sellUnits << std::endl;
}
