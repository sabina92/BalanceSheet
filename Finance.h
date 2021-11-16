#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

using namespace std;

class Finance
{
    int financeId;
    int userId;
    int date;
    string item;
    string amount;

public:

    void setFinanceId(int newFinanceId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getFinanceId();
    int getUserId();
    int getDate()const;
    string getItem();
    string getAmount();
};

#endif

