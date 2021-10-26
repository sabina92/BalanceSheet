#include "Date.h"

struct tm * Date::giveActualDate()
{
    string wholeActualDate;

    time_t time1;
    struct tm * actualTime;

    time( & time1 );
    actualTime = localtime (& time1);

    return actualTime;
    delete actualTime;
};

int Date::retrieveActualDate()
{
    string wholeActualDate;
//
//    time_t time1;
//    struct tm * actualTime;
//
//    time( & time1 );
//    actualTime = localtime (& time1);

    struct tm * actualTime = giveActualDate();

    wholeActualDate = AccessoryMethods::convertIntToString(actualTime->tm_year + 1900)+AccessoryMethods::convertIntToString(actualTime->tm_mon + 1)+AccessoryMethods::convertIntToString(actualTime->tm_mday);

    return AccessoryMethods::convertStringToInt(wholeActualDate);
}

int Date::retrievePreviousMonth()
{
    struct tm * actualTime = giveActualDate();
    int previousMonth = actualTime->tm_mon;
    return previousMonth;
}

bool checkIfDateIsCorrect();
int calculateHowManyDaysHaveMonth();
bool compareDates();
