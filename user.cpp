//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "user.h"

void User::addMoney(double amount){
    balance += amount;
    potentialBalance = balance;
}
void User::deposit(double amount) {
    balance -= amount;
    potentialBalance = balance;
}

void User::display() {
    updatePotentialBalance();
    if (calculateProfits()>0) {
        std::cout << "[" << ID << "] balance: $" << balance << " | Portfolio balance: $" << potentialBalance << "\033[32m" <<" [+$" <<
            calculateProfits() << "]" << "\033[0m"<< std::endl;
    }else {
        std::cout << "[" << ID << "] balance: $" << balance << " | Portfolio balance: $" << potentialBalance << "\033[31m" <<" [" <<
            calculateProfits() << "$]" << "\033[0m"<< std::endl;
    }

    std::cout << "Transactions: " << std::endl;
    for (auto t : userTransactions) {
        t->displayTransaction();
    }
}

void User::addTransaction(boost::shared_ptr<Transaction> t) {
    userTransactions.push_back(t);
    if (t->getType() == "sell") {
        t->setClose();
    }
}


void User::updatePotentialBalance() {
    double totalValue = balance; // Zacznij od gotówki

    for (auto t : userTransactions) {
        if (t->getType() == "buy") {
            if (t->getIsClosed() == false) {
                totalValue += t->getValue();
            }
        }
        // Dla "sell" - transakcje sprzedaży już są w balance
    }
    potentialBalance = totalValue;
}

double User::calculateProfits() {
    double totalProfit = 0;
    for (auto t : userTransactions) {
        totalProfit += t->calculateProfit();
    }
    return totalProfit;
}