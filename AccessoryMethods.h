#ifndef ACCESSORYMETHODS_H
#define ACCESSORYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <locale>
#include <vector>
#include <algorithm>

#include "Finance.h"
#include "Expense.h"
#include "Income.h"

using namespace std;

class AccessoryMethods{


public:

static string changePointToComa(string amount);
static string askTheCustomer(string option);
static int calculateTheDifference(int firstSum, int secondSum);
static string convertIntToStringWithDash(int number);
static string convertIntToString(int number);
static int convertStringToInt(string number);
static string deletingDashesFromDate(string date);
static void sortIncomes(vector <Income> incomes);
static void sortExpenses(vector <Expense> expenses);
static void showIncomeVectorElements(vector <Income> incomes);
static void showExpenseVectorElements(vector <Expense> expenses);
static string loadLine();

};

#endif



