#include <iostream>
#include "market.h"

int main() {
    User u1("bartek1001");
    u1.addMoney(10000);

    Market market;

    int choice;
    do {
        std::cout << "\n=== Trading Platform ===" << std::endl;
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
                u1.display();
                break;
            case 2:
                market.displayMarket();
                break;
            case 3:
                market.makeTrade(&u1);
                break;
            case 4:
                double amount;
                std::cout << "Enter amount to add: $";
                std::cin >> amount;
                u1.addMoney(amount);
                std::cout << "Added $" << amount << " to account." << std::endl;
                break;
            case 5: // ← NOWA OPCJA
                market.displayTransactions();
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}