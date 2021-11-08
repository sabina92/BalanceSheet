#ifndef ACCESSORYMETHODS_H
#define ACCESSORYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <locale>
#include <vector>
#include "Finance.h"

using namespace std;

class AccessoryMethods{


public:

static string changePointToComa(string amount);
static void askTheCustomer(string option);
static void showAllVectorElements(vector <Finance> allElements);
static int calculateTheSum(vector <Finance> allElements);
static int calculateTheDifference(int firstSum, int secondSum);
static string convertIntToStringWithDash(int number);
static string convertIntToString(int number);
static int convertStringToInt(string number);


string loadLine();

};

#endif



