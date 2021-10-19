#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Finance.h"
#include <string>

using namespace std;

class Expense : public Finance
{
    int expenseId;
    int expenseUserId;
    int expenseDate;
    string expenseItem;
    int expenseAmount;

public:

};

#endif

