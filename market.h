//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_MARKET_H
#define TRADINGPLATFORM_MARKET_H
#include <cstdlib>
#include <vector>
#include "user.h"
#include "transaction.h"
#include "item.h"
#include <boost/smart_ptr.hpp> //in case of ERRORS change that to your boost directory


class Market {
private:

    //time_t time;
    std::vector <User> users;
    //std::vector <Transaction> transactions;
    std::vector<boost::shared_ptr<Transaction>> transactions; //wersja z boost
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
    void update() {
        priceManipulation();
        calculatePercent();

        for (auto t : transactions) {
            t->newValue();
        }
        updateUsers();
    }
    void setActiveUser(User* user) { activeUser = user; }
    User* getActiveUser() { return activeUser; }

    void addIndex(Item newIndex);
    void addUser(User user) {   users.push_back(user);  }

    //void addNewTransaction(Transaction newTransaction) {   transactions.push_back(newTransaction); }
    void addNewTransaction(boost::shared_ptr<Transaction> transaction) {transactions.push_back(transaction); }
    void displayMarket();
    double calculate2Cash(Item * _chosenItem, double _amount);
    double calculate2Symbol(Item * _chosenItem, double _value);
    void makeTrade(User* user);
    void displayTransactions();

    void priceManipulation();
    void calculatePercent();
    void updateUsers();

};


#endif //TRADINGPLATFORM_MARKET_H