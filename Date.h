#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "AccessoryMethods.h"
#include "Finance.h"


using namespace std;

class Date
{
    int date;
    struct tm *giveActualDate();
    bool checkIfYearIsBissextile (int year);
    bool checkIfYearIsCorrect (int year);
    bool checkIfMonthIsCorrect (int month);
    bool checkIfMonthHasCorrectDaysNumber (int month, int days, int year);
    bool checkIfDateIsLaterThanToday (int dateToCheck);

public:

    int retrieveActualDate();
    bool checkIfDateIsCorrect(int dateToCheck);
    int giveMonthFromDate (int wholeDate);
    int giveYearFromDate (int wholeDate);
    int giveDayFromDate (int wholeDate);


};

#endif

