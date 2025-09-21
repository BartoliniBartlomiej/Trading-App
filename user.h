//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_USER_H
#define TRADINGPLATFORM_USER_H

#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"
#include </opt/homebrew/Cellar/boost/1.89.0/include/boost/smart_ptr.hpp> //change that to your boost directory

class User {
private:
    std::string ID;
    double balance;
    //std::vector<Transaction*> transactions; //list of pointers to transaction
    std::vector<boost::shared_ptr<Transaction>> transactions; //list of pointers to transaction

public:
    User(std::string id) : ID(id), balance(0) {}
    void addMoney(double amount);
    void display();
    void buy();
    void addTransaction(boost::shared_ptr<Transaction> t);
    void deposit(double amount);
    double getBalance() { return balance; }


    std::string getID() { return ID;    }
};


#endif //TRADINGPLATFORM_USER_H