#ifndef BOAT_H
#define BOAT_H

class Boat {
private:
    int buyProductId;
    int sellProductId;
    int buyUnits;
    int sellUnits;

public:
    Boat();
    void modify(int buyId, int buyUnits, int sellId, int sellUnits);
    void printBoatData() const;
};

#endif
