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
    XMLFileWithExpense xmlFileWithExpenses;
    vector <Expense> allExpenses;

    Expense giveNewExpenseData(int intDate);


public:
    ExpensesManager(string nameOfFileWithExpenses, int loggedInUserId) : xmlFileWithExpenses(nameOfFileWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        allExpenses = xmlFileWithExpenses.loadExpenses(LOGGED_IN_USER_ID);
    };

    void addExpense();
    void sortExpenses(vector <Expense> &expenses);
    vector <Expense> getVector();
    vector <Expense> chooseExpensesFromCurrentMonth();
    vector <Expense> chooseExpensesFromPrevioustMonth();
    vector <Expense> chooseExpensesFromChosenPeriod(int customerStartDate, int customerStopDate);
    void showExpenseVectorElements(vector <Expense> expenses);

};

#endif
