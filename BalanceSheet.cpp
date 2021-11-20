#include "BalanceSheet.h"


void BalanceSheet::showBalanceSheet(vector <Expense> choosenExpenses, vector <Income> choosenIncomes, string balanceSheetPeriod)
{
    int expenseAmount = 0;
    int incomeAmount = 0;
    int sumOfExpenses = 0, sumOfIncomes = 0, financeDifference = 0;

    for (int i=0; i< choosenExpenses.size(); i++)
    {
        expenseAmount = AccessoryMethods::convertStringToInt(choosenExpenses[i].getAmount());
        sumOfExpenses += expenseAmount;
    }

    for (int i=0; i< choosenIncomes.size(); i++)
    {
        incomeAmount = AccessoryMethods::convertStringToInt(choosenIncomes[i].getAmount());
        sumOfIncomes += incomeAmount;
    }

    financeDifference = sumOfIncomes - sumOfExpenses;

    if (financeDifference >= 0)
        cout << endl << "In " << balanceSheetPeriod <<" you generated " << financeDifference << "PLN savings." << endl;
    else
        cout << endl << "In " << balanceSheetPeriod <<" you generated " << -financeDifference << "PLN debt." << endl;
}


