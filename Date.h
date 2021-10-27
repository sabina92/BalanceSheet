#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "AccessoryMethods.h"


using namespace std;

class Date{
int date;
struct tm *giveActualDate();
int giveYearFromDate (int wholeDate);
int giveMonthFromDate (int wholeDate);
int giveDayFromDate (int wholeDate);
bool checkIfYearIsBissextile (int year);
bool checkIfYearIsCorrect (int year);
bool checkIfMonthIsCorrect (int month);
bool checkIfMonthHasCorrectDaysNumber (int month, int days, int year);

public:

 int retrieveActualDate();
 int retrievePreviousMonth();
 bool checkIfDateIsCorrect(int dateToCheck);
 bool compareDates(int date1, int date2);


};

#endif

