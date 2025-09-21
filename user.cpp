//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "user.h"

void User::addMoney(double amount){
    balance += amount;
}
void User::deposit(double amount) {
    balance -= amount;
}

void User::buy() {
}

void User::display() {
    std::cout << "[" << ID << "] balance: " << balance << std::endl;
    std::cout << "Transactions: " << std::endl;
    for (auto t : transactions) {
        t->displayTransaction();
    }
}

void User::addTransaction(boost::shared_ptr<Transaction> t) {
    transactions.push_back(t);
}
