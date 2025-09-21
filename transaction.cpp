//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "transaction.h"

#include "user.h"

void Transaction::displayTransaction()
{
    if (type == "buy") {
        std::cout << transactionId << " [-$" << value << "]" << std::endl;
    } else {
        std::cout << transactionId << " [+$" << value << "]" << std::endl;
    }
}

void Transaction::collectMoney() {
    transactionUser->deposit(value);
}
void Transaction::withdrawMoney() {
    transactionUser->addMoney(value);
}

void Transaction::newValue() {
    if (item == nullptr) return; // Zabezpieczenie

    setLastValue(value);
    double iloczyn = (item->getChange()/100)+1;
    double newValue = getValue()*iloczyn;
    setValue(newValue);

    if (getLastValue() != 0) {
        change = 100 * (getValue()/getStartingValue()-1);
    }
}

double Transaction::getChangeT() {
    return change;
}

