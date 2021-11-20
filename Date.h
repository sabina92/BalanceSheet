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
    bool yearIsBissextile (int year);
    bool yearIsCorrect (int year);
    bool monthIsCorrect (int month);
    bool monthHasCorrectDaysNumber (int month, int days, int year);
    bool dateIsNotLaterThanToday (int dateToCheck);

public:

    int retrieveActualDate();
    bool dateIsCorrect(int &dateToCheck);
    int giveMonthFromDate (int wholeDate);
    int giveYearFromDate (int wholeDate);
    int giveDayFromDate (int wholeDate);
    int giveTheActualMonth();
    int giveTheActualYear();
    int askCustomerAboutDate();
    int convertCustomerDateToInt(string customerChoice);
    int periodDateIsCorrect (int &dateToCheck);
    int askCustomerAboutStartDate();
    int askCustomerAboutStopDate();

};

#endif

