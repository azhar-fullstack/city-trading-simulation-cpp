#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "Product.h"

struct ProductData {
    int units;
    int needed;
};

class Inventory {
public:
    std::map<int, ProductData> inventory;

public:
    void addProduct(int id, int units, int needed);
    void modifyProduct(int id, int units, int needed);
    void removeProduct(int id);
    const ProductData* getProduct(int id) const;
};

#endif
