#include <iostream>
#include "market.h"

int main() {
    //configuration
    std::cout << std::fixed << std::setprecision(2);

    User u1("bartek1001");
    u1.addMoney(10000);

    Market market;
    market.addUser(u1);

    system("clear");

    int choice;
    do {

        market.update(); //simulating real market price manipulation
        std::cout << "\n=== Trading Platform ===" << std::endl;
        std::cout << u1.getPotentialBalance() << std::endl;
        std::cout << "1. Display user info" << std::endl;
        std::cout << "2. Display market" << std::endl;
        std::cout << "3. Make trade" << std::endl;
        std::cout << "4. Add money" << std::endl;
        std::cout << "5. Display market transactions" << std::endl; // ← NOWA OPCJA
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choose option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("clear");
                u1.display();
                break;
            case 2:
                system("clear");
                market.displayMarket();
                break;
            case 3:
                system("clear");
                market.makeTrade(&u1);
                break;
            case 4:
                system("clear");
                double amount;
                std::cout << "Enter amount to add: $";
                std::cin >> amount;
                u1.addMoney(amount);
                std::cout << "Added $" << amount << " to account." << std::endl;
                break;
            case 5:
                system("clear");
                market.displayTransactions();
                break;
            case 0:
                system("clear");
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                system("clear");
                std::cout << "Invalid option!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}