#ifndef ACCESSORYMETHODS_H
#define ACCESSORYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

class AccessoryMethods{


public:

static string changePointToComa();
static int changeCommaToPoint(int amountWithComma);
static string askTheCustomerAboutItem();
static int askTheCustomerAboutAmount();
static void showAllVectorElements();
static int calculateTheSum();
static int calculateTheDifference();
static string convertIntToStringWithDash(int number);
static string convertIntToString(int number);
static int convertStringToInt(string number);


};

#endif



