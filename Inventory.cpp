#include "Inventory.h"

void Inventory::addProduct(int id, int units, int needed) {
    inventory[id] = { units, needed };
}

void Inventory::modifyProduct(int id, int units, int needed) {
    if (inventory.find(id) != inventory.end()) {
        inventory[id] = { units, needed };
    }
}

void Inventory::removeProduct(int id) {
    inventory.erase(id);
}

const ProductData* Inventory::getProduct(int id) const {
    auto it = inventory.find(id);
    return (it != inventory.end()) ? &it->second : nullptr;
}
