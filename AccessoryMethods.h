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
static string convertIntToStringWithDash(int number);
static string convertIntToString(int number);
static int convertStringToInt(string number);
static string deletingDashesFromDate(string date);
static string loadLine();

};

#endif



