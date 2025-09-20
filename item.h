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
public:
    Item(std::string name, double price): name(name), price(price) {}
    std::string getName() { return name; }
    double getPrice() { return price; }

    //bool update(const std::string& symbol); // <~~~ for updating prices, g++ -std=c++17 main.cpp market.cpp item.cpp -lcurl -o stock_app
};


#endif //TRADINGPLATFORM_ITEM_H