#include "Product.h"

Product::Product(int id, float weight, float volume) : id(id), weight(weight), volume(volume) {}

int Product::getId() const { return id; }
float Product::getWeight() const { return weight; }
float Product::getVolume() const { return volume; }
