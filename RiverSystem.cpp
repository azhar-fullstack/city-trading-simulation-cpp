#include "RiverSystem.h"
#include <iostream>
#include <algorithm>

void RiverSystem::listCities() const {
    if (cities.empty()) {
        std::cout << "No cities available.\n";
        return;
    }

    std::cout << "Cities:\n";
    for (const auto& city : cities) {
        std::cout << city.first << '\n';
    }
}

void RiverSystem::listProducts() const {
    if (products.empty()) {
        std::cout << "No products available.\n";
        return;
    }

    std::cout << "Products:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId() << ", Weight: " << product.getWeight()
                  << ", Volume: " << product.getVolume() << '\n';
    }
}


void RiverSystem::addCity(const std::string& cityName) {
    cities.emplace(cityName, City(cityName));
}

void RiverSystem::removeCity(const std::string& cityName) {
    cities.erase(cityName);
}

void RiverSystem::readRiver() {
    int numCities;
    std::cout << "Enter the number of cities: ";
    std::cin >> numCities;

    std::string cityName;
    for (int i = 0; i < numCities; ++i) {
        std::cout << "Enter city name: ";
        std::cin >> cityName;
        addCity(cityName);
    }
}

void RiverSystem::readInventory(const std::string& cityName) {
    auto it = cities.find(cityName);
    if (it == cities.end()) {
        std::cerr << "City not found." << std::endl;
        return;
    }

    Inventory& inv = it->second.getInventory();
    int numItems;
    std::cout << "Enter the number of items in inventory: ";
    std::cin >> numItems;

    for (int i = 0; i < numItems; ++i) {
        int productId, units, needed;
        std::cout << "Enter product ID, units, needed: ";
        std::cin >> productId >> units >> needed;
        if (needed <= 0) {
            std::cerr << "Invalid units needed for product." << std::endl;
            return;
        }
        inv.addProduct(productId, units, needed);
    }
}

void RiverSystem::readInventories() {
    std::string cityName;
    while (std::cin >> cityName) {
        readInventory(cityName);
    }
}

void RiverSystem::modifyBoat(int buyId, int buyUnits, int sellId, int sellUnits) {
    if (buyId == sellId) {
        std::cerr << "Cannot buy and sell the same product." << std::endl;
        return;
    }
    boat.modify(buyId, buyUnits, sellId, sellUnits);
}

void RiverSystem::writeBoatData() const {
    boat.printBoatData();
}

void RiverSystem::queryNumProducts() const {
    std::cout << "Number of products: " << products.size() << std::endl;
}

void RiverSystem::addProducts(int count, float weight, float volume) {
    for (int i = 0; i < count; ++i) {
        int id = products.size() + 1;
        products.emplace_back(id, weight, volume);
    }
}

void RiverSystem::writeProduct(int productId) const {
    auto it = std::find_if(products.begin(), products.end(),
                           [productId](const Product& product) { return product.getId() == productId; });

    if (it != products.end()) {
        std::cout << "Product ID: " << it->getId() << ", Weight: " << it->getWeight()
                  << ", Volume: " << it->getVolume() << std::endl;
    } else {
        std::cerr << "Product not found." << std::endl;
    }
}

void RiverSystem::writeCity(const std::string& cityName) const {
    auto it = cities.find(cityName);
    if (it != cities.end()) {
        const Inventory& inv = it->second.getInventory(); // Use const Inventory
        // Implement your inventory details printing
    } else {
        std::cerr << "City not found." << std::endl;
    }
}

void RiverSystem::putProd(const std::string& cityName, int productId, int units, int needed) {
    auto it = cities.find(cityName);
    if (it == cities.end()) {
        std::cerr << "City not found." << std::endl;
        return;
    }
    if (std::find_if(products.begin(), products.end(),
                     [productId](const Product& product) { return product.getId() == productId; }) == products.end()) {
        std::cerr << "Product not found." << std::endl;
        return;
    }

    Inventory& inv = it->second.getInventory();
    if (inv.getProduct(productId)) {
        std::cerr << "Product already exists in the inventory." << std::endl;
        return;
    }

    if (needed <= 0) {
        std::cerr << "Invalid units needed." << std::endl;
        return;
    }

    inv.addProduct(productId, units, needed);
}

void RiverSystem::modifyProd(const std::string& cityName, int productId, int units, int needed) {
    auto it = cities.find(cityName);
    if (it == cities.end()) {
        std::cerr << "City not found." << std::endl;
        return;
    }

    Inventory& inv = it->second.getInventory();
    if (!inv.getProduct(productId)) {
        std::cerr << "Product not found in the inventory." << std::endl;
        return;
    }

    if (needed <= 0) {
        std::cerr << "Invalid units needed." << std::endl;
        return;
    }

    inv.modifyProduct(productId, units, needed);
}

void RiverSystem::removeProd(const std::string& cityName, int productId) {
    auto it = cities.find(cityName);
    if (it == cities.end()) {
        std::cerr << "City not found." << std::endl;
        return;
    }

    Inventory& inv = it->second.getInventory();
    if (!inv.getProduct(productId)) {
        std::cerr << "Product not found in the inventory." << std::endl;
        return;
    }

    inv.removeProduct(productId);
}

void RiverSystem::queryProd(const std::string& cityName, int productId) const {
    auto it = cities.find(cityName);
    if (it == cities.end()) {
        std::cerr << "City not found." << std::endl;
        return;
    }

    const Inventory& inv = it->second.getInventory();
    const ProductData* product = inv.getProduct(productId);
    if (!product) {
        std::cerr << "Product not found in the inventory." << std::endl;
        return;
    }

    std::cout << "Units: " << product->units << ", Needed: " << product->needed << std::endl;
}

void RiverSystem::trade(const std::string& city1, const std::string& city2) {
    auto it1 = cities.find(city1);
    auto it2 = cities.find(city2);

    if (it1 == cities.end() || it2 == cities.end()) {
        std::cerr << "One or both cities not found." << std::endl;
        return;
    }

    Inventory& inv1 = it1->second.getInventory();
    Inventory& inv2 = it2->second.getInventory();

    for (auto it = inv1.inventory.begin(); it != inv1.inventory.end(); ++it) {
        int productId = it->first;
        ProductData& data1 = it->second;
        
        auto data2 = inv2.getProduct(productId);
        if (data2) {
            int surplus1 = data1.units - data1.needed;
            int surplus2 = data2->units - data2->needed;

            if (surplus1 > 0 && surplus2 < 0) {
                int tradeAmount = std::min(surplus1, -surplus2);
                inv1.modifyProduct(productId, data1.units - tradeAmount, data1.needed);
                inv2.modifyProduct(productId, data2->units + tradeAmount, data2->needed);
            }
        }
    }
}

void RiverSystem::redistribute() {
    std::string currentCity = "mouth";
    while (!currentCity.empty()) {
        auto it = cities.find(currentCity);
        if (it != cities.end()) {
            City& city = it->second;
            Inventory& inv = city.getInventory();

            // Example logic to redistribute products
            // Adjust the product redistribution logic here

            // Update currentCity to the next upstream city
            // Customize the logic to find the upstream cities correctly
        }
    }
}

void RiverSystem::makeTrip() {
    std::string currentCity = "mouth";
    std::vector<std::string> visitedCities;

    while (!currentCity.empty()) {
        auto it = cities.find(currentCity);
        if (it != cities.end()) {
            City& city = it->second;
            Inventory& inv = city.getInventory();

            // Example trading logic for the boat trip
            // Customize this logic to suit your needs

            visitedCities.push_back(currentCity);
            // Update currentCity to the next city in the route
        }
    }

    std::cout << "Boat visited: ";
    for (const std::string& city : visitedCities) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}
