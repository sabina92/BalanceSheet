#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <algorithm>

#include "Expense.h"
#include "XMLFileWithExpenses.h"
#include "AccessoryMethods.h"
#include "Date.h"
#include "Finance.h"

using namespace std;

class ExpensesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Expense> allExpenses;
 vector <Expense> expensesFromCurrentMonth;
 vector <Expense> expensesFromPrevioustMonth;
 vector <Expense> expensesFromChosenPeriod;
 XMLFileWithExpense xmlFileWithExpenses;

 Expense giveNewExpenseData(int intDate);
bool comp( const Expense & l, const Expense & r );

public:
    ExpensesManager(string nameOfFileWithExpenses, int loggedInUserId) : xmlFileWithExpenses (nameOfFileWithExpenses), LOGGED_IN_USER_ID(loggedInUserId) {
allExpenses = xmlFileWithExpenses.loadExpenses(LOGGED_IN_USER_ID);
    };

    void addExpense();
   void sortExpenses();
    void showVectorElements();
    vector <Expense> getVector();
    vector <Expense> chooseExpensesFromCurrentMonth();
    vector <Expense> chooseExpensesFromPrevioustMonth();
    vector <Expense> chooseExpensesFromChosenPeriod();
     int *checkDate();


};

#endif
