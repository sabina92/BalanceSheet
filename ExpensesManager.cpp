#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "XMLFileWithExpenses.h"
#include "Expense.h"


using namespace std;

class ExpensesManager
{
    XMLFileWithExpense xmlFileWithExpense;
    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> expensesFromPrevioustMonth;
    vector <Expense> expensesFromChosenPeriod;


public:
    Expense addExpense();
    vector <Expense> sortExpenses();
    vector <Expense> chooseExpensesFromCurrentMonth();
    vector <Expense> chooseExpensesFromPrevioustMonth();
    vector <Expense> chooseExpensesFromChosenPeriod();

};

#endif

