#ifndef FINANCECALCULATOR_H
#define FINANCECALCULATOR_H

#include <iostream>
#include <vector>

#include "UserManager.h"
#include "ExpensesManager.h"
#include "IncomesManager.h"
#include "BalanceSheet.h"

using namespace std;

class FinanceCalculator
{
    UserManager userManager;
    BalanceSheet balanceSheet;
    ExpensesManager *expensesManager;
    IncomesManager *incomesManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    char loadSign();
    bool isUserLoggedIn();

public:
        FinanceCalculator(string nameOfFileWithUsers, string nameOfFileWithExpenses, string nameOfFileWithIncomes)
    : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes)
    {
        expensesManager = NULL;
        incomesManager = NULL;
    };
    ~FinanceCalculator()
    {
        delete expensesManager;
        expensesManager = NULL;
        delete incomesManager;
        incomesManager = NULL;
    }

    void userRegister();
    void changeLoggedInUserPassword();
    void logInUser();
    void logOutUser();

    void addExpense();
    void addIncome();
    void showBalanceSheetFromCurrentMonth();
    void showBalanceSheetFromPreviousMonth();
    void showBalanceSheetFromChoosenPeriod();
    void showMainMenu();



};

#endif
