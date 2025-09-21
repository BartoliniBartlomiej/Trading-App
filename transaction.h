//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_TRANSACTION_H
#define TRADINGPLATFORM_TRANSACTION_H
#include <string>
#include <iostream>
#include <ctime>
#include </opt/homebrew/Cellar/boost/1.89.0/include/boost/smart_ptr.hpp>  //change that to your boost dire

class User;

class Transaction {
private:
    std::string transactionId;
    std::string type;
    std::string itemName;
    double value;
    double amount;
    User* transactionUser; // pointer to transaction user


public:
    Transaction(std::string _transactionId, std::string _type, double _value,
                User* _transactionUser, std::string _itemName = "")
        : transactionId(_transactionId), type(_type), value(_value),
          transactionUser(_transactionUser), itemName(_itemName) {
        if(type == "buy")
            collectMoney();
        else if(type == "sell")
            withdrawMoney();
    }
    // Transaction(std::string _transactionId, std::string _type, double _value, User* _transactionUser)
    //     : transactionId(_transactionId), type(_type), value(_value),
    //       transactionUser(_transactionUser) {
    //     if(type == "buy")
    //         collectMoney();
    //     else if(type == "sell")
    //         withdrawMoney();
    // }
    void displayTransaction();
    void collectMoney();
    void withdrawMoney();
    std::string getItemName() const { return itemName; }
    std::string getId() const { return transactionId; }
    std::string getType() const { return type; }
    double getValue() const { return value; }
    User* getUser() const { return transactionUser; }
};


#endif //TRADINGPLATFORM_TRANSACTION_H