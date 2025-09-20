//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_MARKET_H
#define TRADINGPLATFORM_MARKET_H
#include <ctime>
#include <vector>
#include "user.h"
#include "item.h"

class Market {
private:
    //time_t time;
    std::vector <User> users;
    std::vector <Transaction> transactions;
    std::vector <Item> indexes;
    User* activeUser;

public:
    Market() : activeUser(nullptr) {
        Item AAPL("AAPL", 250.59);
        Item NDX("NDX", 24626.25);
        Item NVDA("NVDA", 176.76);
        Item SPX("SPX", 6664.37);
        //AAPL.update("AAPL");
        //NASDAQ.update("NDX");
        //NVDA.update("NVDA");
        //SPX.update("SPX");
        addIndex(AAPL);
        addIndex(NDX);
        addIndex(NVDA);
        addIndex(SPX);
    }

    void setActiveUser(User* user) { activeUser = user; }
    User* getActiveUser() { return activeUser; }

    void addIndex(Item newIndex);
    void addUser(User user) {   users.push_back(user);  }
    void newTransaction(Transaction newTransaction) {   transactions.push_back(newTransaction); }
    void displayMarket();
    double calculate2Cash(Item * _chosenItem, double _amount);
    double calculate2Symbol(Item * _chosenItem, double _value);
    void makeTrade(User* user);

};


#endif //TRADINGPLATFORM_MARKET_H