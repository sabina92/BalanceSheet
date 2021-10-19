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
    int amount;

public:
//    Finance(int financeId1, int userId1, int date1, string item1, int amount1) : financeId(financeId1), userId(userId1), date(date1), item(item1), amount(amount1){};

    void setFinanceId(int newFinanceId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(int newAmount);

    int getFinanceId();
    int getUserId();
    int getDate();
    string getItem();
    int getAmount();
};

#endif

