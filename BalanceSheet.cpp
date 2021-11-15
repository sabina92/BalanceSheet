#include "BalanceSheet.h"


void BalanceSheet::showBalanceSheet(vector <Expense> choosenExpenses, vector <Income> choosenIncomes, string balanceSheetPeriod)
{
    int sumOfExpenses = 0, sumOfIncomes = 0, financeDifference = 0;

    for (int i=0; i< choosenExpenses.size(); i++)
    {
        sumOfExpenses += AccessoryMethods::convertStringToInt(choosenExpenses[i].getAmount());
    }

    for (int i=0; i< choosenIncomes.size(); i++)
    {
        sumOfIncomes += AccessoryMethods::convertStringToInt(choosenIncomes[i].getAmount());
    }

    financeDifference = sumOfIncomes - sumOfExpenses;

    if (financeDifference >= 0)
        cout << "In " << balanceSheetPeriod <<" you generated " << financeDifference << "PLN savings." << endl;
    else
        cout << "In " << balanceSheetPeriod <<" you generated " << -financeDifference << "PLN debt." << endl;
}


