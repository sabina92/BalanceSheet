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

    struct tm * actualTime = giveActualDate();

    wholeActualDate = AccessoryMethods::convertIntToString(actualTime->tm_year + 1900)+AccessoryMethods::convertIntToString(actualTime->tm_mon + 1)+AccessoryMethods::convertIntToString(actualTime->tm_mday);

    return AccessoryMethods::convertStringToInt(wholeActualDate);
}


int Date::giveYearFromDate (int wholeDate)
{
    string year;
    string stringDate;
    int intYear;

    stringDate = AccessoryMethods::convertIntToString(wholeDate);

    for (int i=0; i < 4; i++)
    {
        year += stringDate[i];
    }
    intYear = AccessoryMethods::convertStringToInt(year);
    return intYear;
}

int Date::giveMonthFromDate (int wholeDate)
{
    string month;
    string stringDate;
    int intMonth;

    stringDate = AccessoryMethods::convertIntToString(wholeDate);
    for (int i=4; i < 6; i++)
    {
        month += stringDate[i];
    }
    intMonth = AccessoryMethods::convertStringToInt(month);
    return intMonth;
}

int Date::giveDayFromDate (int wholeDate)
{
    string day;
    string stringDate;
    int intDay;

    stringDate = AccessoryMethods::convertIntToString(wholeDate);
    for (int i=6; i < 8; i++)
    {
        day += stringDate[i];
    }
    intDay = AccessoryMethods::convertStringToInt(day);
    return intDay;
}

bool Date::checkIfDateIsCorrect(int dateToCheck)
{
    bool isCorrect = true;
    int intDay = 0, intMonth = 0, intYear = 0, actualYear = 0;
    intDay = giveDayFromDate(dateToCheck);
    intMonth = giveMonthFromDate(dateToCheck);
    intYear = giveYearFromDate(dateToCheck);

    if ((checkIfMonthHasCorrectDaysNumber(intMonth, intDay, intYear) == false) || (checkIfMonthIsCorrect(intMonth) == false) || (checkIfYearIsCorrect(intYear) == false)||(checkIfDateIsLaterThanToday(dateToCheck) == false))
        isCorrect = false;

    return isCorrect;
}

bool Date::checkIfMonthHasCorrectDaysNumber (int month, int days, int year)
{
    bool areDaysCorrect = true;

    int monthsWith31days[8] = {1,3,5,7,8,10,12};
    int monthsWith30days[4] = {4,6,9,11};
    int februaryMonth = 2;

    for (int i=0; i < 7; i++)
    {
        if (month == monthsWith31days[i])
        {
            if (days > 31)
            {
                areDaysCorrect = false;
                return areDaysCorrect;
            }
        }
    }

    for (int i=0; i < 4; i++)
    {
        if (month == monthsWith30days[i])
        {
            if (days > 30)
            {
                areDaysCorrect = false;
                return areDaysCorrect;
            }
        }
    }

    if ((month == februaryMonth) && (checkIfYearIsBissextile(year))== true)
    {
        if (days > 29)
        {
            areDaysCorrect = false;
            return areDaysCorrect;
        }
    }
    if ((month == februaryMonth) && (checkIfYearIsBissextile(year))== false)
    {
        if (days > 28)
        {
            areDaysCorrect = false;
            return areDaysCorrect;
        }
    }
    return areDaysCorrect;
}

bool Date::checkIfMonthIsCorrect (int month)
{
    bool isMonthCorrect = true;
    if ((month < 1) || (month > 12))
        isMonthCorrect = false;

    return isMonthCorrect;
}

bool Date::checkIfYearIsCorrect (int year)
{
    int actualYear = giveYearFromDate(retrieveActualDate());
    bool isYearCorrect = true;

    if ((year > actualYear)|| (year < 1900))
        isYearCorrect = false;

    return isYearCorrect;
}

bool Date::checkIfYearIsBissextile(int year)
{
    if (((year%4 == 0)&& (year%100 != 0)) || (year%400 == 0))
        return true;
    else
        return false;
}

bool Date::checkIfDateIsLaterThanToday (int dateToCheck)
{
     int actualDate = retrieveActualDate();
     if (dateToCheck > actualDate)
        return false;
     else
        return true;
}

int Date::giveTheActualMonth()
{
    Date date;
    int actualMonth = 0, actualDate = 0;
    actualDate = retrieveActualDate();
    actualMonth = giveMonthFromDate(actualDate);

    return actualMonth;
}

int Date::giveTheActualYear()
{
    Date date;
    int actualYear = 0, actualDate = 0;
    actualDate = retrieveActualDate();
    actualYear = giveYearFromDate(actualDate);

    return actualYear;
}

int Date::askCustomerAboutDate()
{
    int newDate = 0;
    string givenDate = "", dateWithoutDashes = "";
    cout << "If you want to add the today's date, write: YES. If not, give your date (year-month-day): " << endl;
    givenDate = AccessoryMethods::loadLine();

    if (givenDate == "YES")
    {
       return newDate = retrieveActualDate();
    }
    else
    {
        dateWithoutDashes = AccessoryMethods::deletingDashesFromDate(givenDate);

        int intDate2 = AccessoryMethods::convertStringToInt(dateWithoutDashes);

        if(!checkIfDateIsCorrect(intDate2))
        {
            cout << "You gave the wrong date. Please, give the date once again. You have 3 chances." << endl;
            for (int chanceAmount = 3; chanceAmount > 0; chanceAmount--)
            {
                cout << "Give the date. There are " << chanceAmount << " chances. ";
                givenDate = AccessoryMethods::loadLine();
                dateWithoutDashes = AccessoryMethods::deletingDashesFromDate(givenDate);
                intDate2 = AccessoryMethods::convertStringToInt(dateWithoutDashes);

                if (checkIfDateIsCorrect(intDate2))
                {
                    return intDate2;
                }
            }
            cout << "You entered the wrong date 3 times." << endl;
            system("pause");
            return 0;
        }
        return intDate2;
    }
}

int Date::convertCustomerDateToInt(string customerChoice)
{
    int customerDate = 0;
    string customerDateWithoutDashes = "";

    customerDateWithoutDashes = AccessoryMethods::deletingDashesFromDate(customerChoice);
    customerDate = AccessoryMethods::convertStringToInt(customerDateWithoutDashes);
    return customerDate;
}

int Date::checkPeriodDate (int &dateToCheck)
{
    bool dateCheck = checkIfDateIsCorrect(dateToCheck);
    if (dateCheck == true)
        return 1;
    else
        return 0;
}

int Date::askCustomerAboutStartDate()
{
    int customerStartDate = 0;
    string customerChoice = "";
    string initialDescibe = "the initial date for the finance period: ";

    cout << "Please, write " << initialDescibe << endl;
    cin >> customerChoice;

    customerStartDate = convertCustomerDateToInt(customerChoice);
    while (!checkPeriodDate(customerStartDate))
    {
        cout << "You gave the wrong date. Please, give the correct date: " << endl;
        cin >> customerChoice;
        customerStartDate = convertCustomerDateToInt(customerChoice);
    }
    return customerStartDate;
}

int Date::askCustomerAboutStopDate()
{
    int customerStopDate = 0;
    string customerChoice = "";
    string finalDescibe = "the final date for the finance period: ";

    cout << "Please, write " << finalDescibe << endl;
    cin >> customerChoice;

    customerStopDate = convertCustomerDateToInt(customerChoice);
    while (!checkPeriodDate(customerStopDate))
    {
        cout << "You gave the wrong date. Please, give the correct date: " << endl;
            cin >> customerChoice;
        customerStopDate = convertCustomerDateToInt(customerChoice);
    }
    return customerStopDate;
}
