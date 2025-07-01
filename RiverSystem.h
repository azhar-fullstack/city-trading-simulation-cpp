#ifndef RIVERSYSTEM_H
#define RIVERSYSTEM_H

#include <map>
#include <vector>
#include "City.h"
#include "Boat.h"

class RiverSystem {
private:
    std::map<std::string, City> cities;
    Boat boat;
    std::vector<Product> products;

public:
    void addCity(const std::string& cityName);
    void removeCity(const std::string& cityName);
    void listCities() const; // New method to list cities
    void listProducts() const; // New method to list products
    void readRiver();
    void readInventory(const std::string& cityName);
    void readInventories();
    void modifyBoat(int buyId, int buyUnits, int sellId, int sellUnits);
    void writeBoatData() const;
    void queryNumProducts() const;
    void addProducts(int count, float weight, float volume);
    void writeProduct(int productId) const;
    void writeCity(const std::string& cityName) const;
    void putProd(const std::string& cityName, int productId, int units, int needed);
    void modifyProd(const std::string& cityName, int productId, int units, int needed);
    void removeProd(const std::string& cityName, int productId);
    void queryProd(const std::string& cityName, int productId) const;
    void trade(const std::string& city1, const std::string& city2);
    void redistribute();
    void makeTrip();
};

#endif
