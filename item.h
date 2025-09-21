//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#ifndef TRADINGPLATFORM_ITEM_H
#define TRADINGPLATFORM_ITEM_H
#include <string>
#include <curl/curl.h>
#include "include/json.hpp"

class Item {
private:
    std::string name;
    double price;
    double change; // in %
    double const entrancePrice;
    double lastPrice;
public:
    Item(std::string name, double price): name(name), price(price), entrancePrice(price) {};
    std::string getName() { return name; }

    void setPrice(double _newPrice) {   price = _newPrice;  }
    void setLastPrice(double _price) {  lastPrice = _price;  }
    void setChange(double _newChange) {  change = _newChange;  }

    double getPrice() { return price; }
    double getConstPrice() { return entrancePrice; }
    double getLastPrice() { return lastPrice; }
    double getChange() { return change; }

    //bool update(const std::string& symbol); // <~~~ for updating prices, g++ -std=c++17 main.cpp market.cpp item.cpp -lcurl -o stock_app
};


#endif //TRADINGPLATFORM_ITEM_H