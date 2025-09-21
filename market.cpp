//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "market.h"
#include <iostream>
#include <iomanip>


void Market::addIndex(Item newIndex) {
    indexes.push_back(newIndex);
}
void Market::displayMarket() {
    std::cout << "\n=== MARKET LIST OF INDEXES ===" << std::endl;
    int j = 1;
    for (auto i : indexes) {
        if (i.getChange()>0) {
            std::cout <<j << ". " <<  i.getName() <<" $" << i.getPrice() << " | "<< "\033[32m" << "+"<< i.getChange() << "%" << "\033[0m" << std::endl;
            j++;
        } else if (i.getChange()<0) {
            std::cout <<j << ". " <<  i.getName() <<" $" << i.getPrice() << " | " << "\033[31m" << i.getChange() << "%" << "\033[0m" << std::endl;
            j++;
        } else {
            std::cout <<j << ". " <<  i.getName() <<" $" << i.getPrice() << " | "<< i.getChange() << "%" << std::endl;
            j++;
        }

    }
}

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
        boost::shared_ptr<Transaction> newTransaction(new Transaction("T" + std::to_string(transactions.size() + 1),
                    operationType,
                    value,
                    user,
                    active));
        user->addTransaction(newTransaction);
        addNewTransaction(newTransaction); //?
        std::cout << "Transaction completed! You " << operationType << " $" << value
                  << " of " << active->getName() << " stock." << std::endl;
    }
    else
    {
        std::cout << "Transaction cancelled." << std::endl;
    }
}

double Market::calculate2Cash(Item * _chosenItem, double _amount) {
    return _amount * _chosenItem->getPrice();
}

double Market::calculate2Symbol(Item * _chosenItem, double _value) {
    return _value / _chosenItem->getPrice();
}
void Market::displayTransactions() {
    std::cout << "\n=== MARKET TRANSACTION HISTORY ===" << std::endl;
    if (transactions.empty()) {
        std::cout << "No transactions yet." << std::endl;
        return;
    }

    for (auto& transaction : transactions) {
        if (transaction->getChangeT() > 0) {
            std::cout << "Transaction ID: " << transaction->getId()
                  << " | Type: " << transaction->getType()
                  << " | Symbol: " << transaction->getItemName()
                  << " | Starting Value: $" << transaction->getStartingValue()
                  << " | Value: $" << transaction->getValue()
                  << " |\033[32m" << " +" << transaction->getChangeT() << "%" << "\033[0m"
                  << " | User: " << transaction->getUser()->getID() // potrzebujesz gettera do ID usera
                  << std::endl;
        }
        else {
            std::cout << "Transaction ID: " << transaction->getId()
                  << " | Type: " << transaction->getType()
                  << " | Symbol: " << transaction->getItemName()
                  << " | Starting Value: $" << transaction->getStartingValue()
                  << " | Value: $" << transaction->getValue()
                  << " | \033[31m"  << transaction->getChangeT() << "%" << "\033[0m"
                  << " | User: " << transaction->getUser()->getID() // potrzebujesz gettera do ID usera
                  << std::endl;
        }
    }
}

void Market::priceManipulation() {

    for (auto& i : indexes) {
        double procent = std::rand()%2000-1000;
        double iloczyn = 1 + (procent/10000);
        double newPrice = iloczyn * i.getConstPrice();
        i.setLastPrice(i.getPrice());
        i.setPrice(newPrice);
    }
}

void Market::calculatePercent() {

    for (auto& i : indexes) {
        double _change = 100 *((i.getPrice()/i.getLastPrice())-1);
        i.setChange(_change);
    }
}

