//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_TRANSACTION_H
#define TRADINGPLATFORM_TRANSACTION_H
#include <string>
#include <iostream>
#include <ctime>
#include <boost/smart_ptr.hpp>  //in case of ERRORS change that to your boost directory

#include "item.h"

class User;

class Transaction {
private:
    std::string transactionId;
    std::string type;
    std::string itemName;
    double value;
    double lastValue;
    double amount;
    double change;
    User* transactionUser; // pointer to transaction user
    Item* item;
    double startingPrice;

public:

    Transaction(std::string _transactionId, std::string _type, double _value, User *_transactionUser,
                Item* _item)
        : transactionId(_transactionId), type(_type), value(_value), startingPrice(_value),
          transactionUser(_transactionUser), itemName(_item->getName()), change(0), item(_item)
    {
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
    void setValue(double _value) { value = _value; }
    void setLastValue(double _value) { lastValue = _value; }
    void setChangeT(double change) { change = change; }

    void displayTransaction();
    void collectMoney();
    void withdrawMoney();


    std::string getItemName() const { return itemName; }
    std::string getId() const { return transactionId; }
    std::string getType() const { return type; }
    double getValue() const { return value; }
    User* getUser() const { return transactionUser; }
    void newValue();
    double getLastValue() {   return lastValue; };
    double getChangeT();
    double getStartingValue() { return startingPrice; }
};


#endif //TRADINGPLATFORM_TRANSACTION_H