#include <iostream>
#include "RiverSystem.h"

void displayMenu() {
    std::cout << "Choose an operation:\n";
    std::cout << "1. Add City\n";
    std::cout << "2. Remove City\n";
    std::cout << "3. List Cities\n"; // Added list cities option
    std::cout << "4. List Products\n"; // Added list products option
    std::cout << "5. Read River\n";
    std::cout << "6. Read Inventory\n";
    std::cout << "7. Modify Boat\n";
    std::cout << "8. Write Boat Data\n";
    std::cout << "9. Query Number of Products\n";
    std::cout << "10. Add Products\n";
    std::cout << "11. Write Product\n";
    std::cout << "12. Write City\n";
    std::cout << "13. Put Product\n";
    std::cout << "14. Modify Product\n";
    std::cout << "15. Remove Product\n";
    std::cout << "16. Query Product\n";
    std::cout << "17. Trade\n";
    std::cout << "18. Redistribute\n";
    std::cout << "19. Make Trip\n";
    std::cout << "20. Exit\n";
}

int main() {
    RiverSystem riverSystem;
    int choice;
    std::string cityName1, cityName2;
    int productId, units, needed, buyId, buyUnits, sellId, sellUnits, count;
    float weight, volume;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter city name: ";
                std::cin >> cityName1;
                riverSystem.addCity(cityName1);
                break;
            case 2:
                std::cout << "Enter city name: ";
                std::cin >> cityName1;
                riverSystem.removeCity(cityName1);
                break;
            case 3:
                riverSystem.listCities();
                break;
            case 4:
                riverSystem.listProducts();
                break;
            case 5:
                riverSystem.readRiver();
                break;
            case 6:
                std::cout << "Enter city name to read inventory: ";
                std::cin >> cityName1;
                riverSystem.readInventory(cityName1);
                break;
            case 7:
                std::cout << "Enter buy product ID, buy units, sell product ID, sell units: ";
                std::cin >> buyId >> buyUnits >> sellId >> sellUnits;
                riverSystem.modifyBoat(buyId, buyUnits, sellId, sellUnits);
                break;
            case 8:
                riverSystem.writeBoatData();
                break;
            case 9:
                riverSystem.queryNumProducts();
                break;
            case 10:
                std::cout << "Enter count, weight, volume: ";
                std::cin >> count >> weight >> volume;
                riverSystem.addProducts(count, weight, volume);
                break;
            case 11:
                std::cout << "Enter product ID: ";
                std::cin >> productId;
                riverSystem.writeProduct(productId);
                break;
            case 12:
                std::cout << "Enter city name: ";
                std::cin >> cityName1;
                riverSystem.writeCity(cityName1);
                break;
            case 13:
                std::cout << "Enter city name, product ID, units, needed: ";
                std::cin >> cityName1 >> productId >> units >> needed;
                riverSystem.putProd(cityName1, productId, units, needed);
                break;
            case 14:
                std::cout << "Enter city name, product ID, units, needed: ";
                std::cin >> cityName1 >> productId >> units >> needed;
                riverSystem.modifyProd(cityName1, productId, units, needed);
                break;
            case 15:
                std::cout << "Enter city name and product ID: ";
                std::cin >> cityName1 >> productId;
                riverSystem.removeProd(cityName1, productId);
                break;
            case 16:
                std::cout << "Enter city name and product ID: ";
                std::cin >> cityName1 >> productId;
                riverSystem.queryProd(cityName1, productId);
                break;
            case 17:
                std::cout << "Enter two city names for trading: ";
                std::cin >> cityName1 >> cityName2;
                riverSystem.trade(cityName1, cityName2);
                break;
            case 18:
                std::cout << "Redistributing products...\n";
                riverSystem.redistribute();
                break;
            case 19:
                std::cout << "Making a trip...\n";
                riverSystem.makeTrip();
                break;
            case 20:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
