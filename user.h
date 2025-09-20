//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_USER_H
#define TRADINGPLATFORM_USER_H

#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"

class User {
private:
    std::string ID;
    double balance;
    std::vector<Transaction*> transactions; //list of pointers to transaction

public:
    User(std::string id) : ID(id), balance(0) {}
    void addMoney(double amount);
    void display();
    void buy();
    void addTransaction(Transaction* t);
    void deposit(double amount);
    double getBalance() { return balance; }

};


#endif //TRADINGPLATFORM_USER_H