#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
private:
    int id;
    float weight;
    float volume;

public:
    Product(int id, float weight, float volume);
    int getId() const;
    float getWeight() const;
    float getVolume() const;
};

#endif
