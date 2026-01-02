#ifndef BKASH_PAYMENT_STRATEGY_H
#define BKASH_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BkashPaymentStrategy : public PaymentStrategy {
private:
    string mobile;
public:
    BkashPaymentStrategy(const string& mob) {
        mobile = mob;
    }

    void pay(double amount) override {
        cout << "Paid ৳" << amount << " using Bkash (" << mobile << ")" << endl;
    }
};

#endif // BKASH_PAYMENT_STRATEGY_H