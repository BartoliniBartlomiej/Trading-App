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

