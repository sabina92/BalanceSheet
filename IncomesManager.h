#ifndef IncomeMANAGER_H
#define IncomeMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <algorithm>

#include "Income.h"
#include "XMLFileWithIncomes.h"
#include "AccessoryMethods.h"
#include "Date.h"
#include "Finance.h"

using namespace std;

class IncomesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> allIncomes;
    vector <Income> incomesFromCurrentMonth;
    vector <Income> incomesFromPrevioustMonth;
    vector <Income> incomesFromChosenPeriod;
    XMLFileWithIncomes xmlFileWithIncomes;

    Income giveNewIncomeData(int intDate);

public:
    IncomesManager(string nameOfFileWithIncomes, int loggedInUserId) : xmlFileWithIncomes (nameOfFileWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        allIncomes = xmlFileWithIncomes.loadIncomes(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void sortIncomes();
    void showVectorElements();
    vector <Income> getVector();
    vector <Income> chooseIncomesFromCurrentMonth();
    vector <Income> chooseIncomesFromPrevioustMonth();
    vector <Income> chooseIncomesFromChosenPeriod(int customerStartDate, int customerStopDate);


};

#endif
