//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "market.h"
#include <iostream>

void Market::addIndex(Item newIndex) {
    indexes.push_back(newIndex);
}
void Market::displayMarket() {
    int j = 1;
    for (auto i : indexes) {
        std::cout <<j << ". " <<  i.getName() <<" $" << i.getPrice() << std::endl;
        j++;
    }
}

// void Market::makeTrade(User* user) {
//     if (!user) {
//         std::cout << "No active user selected!" << std::endl;
//         return;
//     }
//
//     setActiveUser(user);
//     Item* active = nullptr;
//     int j = 1;
//
//     std::cout << "\n=== Available Stocks ===" << std::endl;
//     for (auto& i : indexes) {
//         std::cout << j << ". " << i.getName() << " $" << i.getPrice() << std::endl;
//         j++;
//     }
//
//     int choice;
//     std::cout << "\nChoose what you want to trade: ";
//     std::cin >> choice;
//
//     if (choice < 1 || choice > indexes.size()) {
//         std::cout << "Invalid choice!" << std::endl;
//         return;
//     }
//
//     active = &indexes[choice - 1];
//
//     std::cout << "\n1. Buy\n2. Sell\nChoose operation: ";
//     std::cin >> choice;
//
//     if (choice != 1 && choice != 2) {
//         std::cout << "Invalid operation!" << std::endl;
//         return;
//     }
//
//     std::string operationType = (choice == 1) ? "buy" : "sell";
//
//     std::cout << "\n1. Enter the amount of shares\n2. Enter the price in dollars\n";
//     std::cin >> choice;
//
//     double value; // in $
//     double amount; // amount of shares
//
//     if (choice == 1) {
//         std::cout << "How many shares: ";
//         std::cin >> amount;
//         value = calculate2Cash(active, amount);
//     } else if (choice == 2) {
//         std::cout << "How much ($): ";
//         std::cin >> value;
//         amount = calculate2Symbol(active, value);
//     } else {
//         std::cout << "Invalid choice!" << std::endl;
//         return;
//     }
//
//     // Sprawdzenie czy użytkownik ma wystarczające środki (dla kupna)
//     if (operationType == "buy" && user->getBalance() < value) {
//         std::cout << "Insufficient funds! Available: $" << user->getBalance()
//                   << ", Required: $" << value << std::endl;
//         return;
//     }
//
//     std::string confir;
//     std::cout << "\nType YES to " << operationType << " " << amount
//               << " shares of " << active->getName() << " for $" << value << std::endl;
//     std::cin >> confir;
//
//     if (confir == "YES" || confir == "yes") {
//         // Tworzenie transakcji
//         std::string transactionId = "T" + std::to_string(transactions.size() + 1);
//         Transaction* newTransaction = new Transaction(transactionId, operationType, value, user);
//
//         // Dodanie transakcji do użytkownika i rynku
//         user->addTransaction(newTransaction);
//         transactions.push_back(*newTransaction);
//
//         std::cout << "Transaction completed! You " << operationType << " $" << value
//                   << " of " << active->getName() << " stock." << std::endl;
//     } else {
//         std::cout << "Transaction cancelled." << std::endl;
//     }
// }
void Market::makeTrade(User* user) {
    if (!user) {
        std::cout << "No active user selected!" << std::endl;
        return;
    }

    Item* active = nullptr;
    int j = 1;

    std::cout << "\n=== Available Stocks ===" << std::endl;
    for (auto& i : indexes) {
        std::cout << j << ". " << i.getName() << " $" << i.getPrice() << std::endl;
        j++;
    }

    int choice;
    std::cout << "\nChoose what you want to trade: ";
    std::cin >> choice;

    if (choice < 1 || choice > indexes.size()) {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }

    active = &indexes[choice - 1];

    std::cout << "\n1. Buy\n2. Sell\nChoose operation: ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Invalid operation!" << std::endl;
        return;
    }

    std::string operationType = (choice == 1) ? "buy" : "sell";

    std::cout << "\n1. Enter the amount of shares\n2. Enter the price in dollars\n";
    std::cin >> choice;

    double value; // in $
    double amount; // amount of shares

    if (choice == 1) {
        std::cout << "How many shares: ";
        std::cin >> amount;
        value = calculate2Cash(active, amount);
    } else if (choice == 2) {
        std::cout << "How much ($): ";
        std::cin >> value;
        amount = calculate2Symbol(active, value);
    } else {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }

    // Sprawdzenie czy użytkownik ma wystarczające środki
    if (operationType == "buy" && user->getBalance() < value) {
        std::cout << "Insufficient funds! Available: $" << user->getBalance()
                  << ", Required: $" << value << std::endl;
        return;
    }

    std::string confir;
    std::cout << "\nType YES to " << operationType << " " << amount
              << " shares of " << active->getName() << " for $" << value << std::endl;
    std::cin >> confir;

    if (confir == "YES" || confir == "yes") {
        // TWORZENIE shared_ptr ZAMIAST surowego wskaźnika
        boost::shared_ptr<Transaction> newTransaction(
    new Transaction("T" + std::to_string(transactions.size() + 1),
                    operationType,
                    value,
                    user)
);

        user->addTransaction(newTransaction);

        std::cout << "Transaction completed! You " << operationType << " $" << value
                  << " of " << active->getName() << " stock." << std::endl;
    } else {
        std::cout << "Transaction cancelled." << std::endl;
    }
}

double Market::calculate2Cash(Item * _chosenItem, double _amount) {
    return _amount * _chosenItem->getPrice();
}

double Market::calculate2Symbol(Item * _chosenItem, double _value) {
    return _value / _chosenItem->getPrice();
}
