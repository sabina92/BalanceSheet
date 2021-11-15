#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <algorithm>

#include "Expense.h"
#include "Income.h"
#include "AccessoryMethods.h"

using namespace std;

class BalanceSheet
{


public:

    void showBalanceSheet(vector <Expense> choosenExpenses, vector <Income> choosenIncomes, string balanceSheetPeriod);

};

#endif
