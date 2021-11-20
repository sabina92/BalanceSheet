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

    delete actualTime;
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

bool Date::dateIsCorrect(int &dateToCheck)
{
    int intDay = 0, intMonth = 0, intYear = 0, actualYear = 0;
    intDay = giveDayFromDate(dateToCheck);
    intMonth = giveMonthFromDate(dateToCheck);
    intYear = giveYearFromDate(dateToCheck);

    return (!((monthHasCorrectDaysNumber(intMonth, intDay, intYear) == false) || (monthIsCorrect(intMonth) == false) || (yearIsCorrect(intYear) == false)||(dateIsNotLaterThanToday(dateToCheck) == false)));
}

bool Date::monthHasCorrectDaysNumber (int month, int days, int year)
{

    if (((month <= 7) && (month%2 == 1))||(((month) >7)&&(month%2 == 0)))
        return (days <= 31);

    if (((month == 4)||(month == 6))||((month >8)&&(month%2 == 1)))
        return (days <= 30);

    if ((month == 2) && (yearIsBissextile(year))== true)
        return (days <= 29);

    if ((month == 2) && (yearIsBissextile(year))== false)
        return (days <= 28);
}

bool Date::monthIsCorrect (int month)
{
    return ((month >= 1) && (month <= 12));
}

bool Date::yearIsCorrect (int year)
{
    int actualYear = giveYearFromDate(retrieveActualDate());

    return ((year <= actualYear)|| (year >= 1900));
}

bool Date::yearIsBissextile(int year)
{
    return (((year%4 == 0)&& (year%100 != 0)) || (year%400 == 0));
}

bool Date::dateIsNotLaterThanToday (int dateToCheck)
{
     int actualDate = retrieveActualDate();
     return (dateToCheck <= actualDate);
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

        if(!dateIsCorrect(intDate2))
        {
            cout << "You gave the wrong date. Please, give the date once again. You have 3 chances." << endl;
            for (int chanceAmount = 3; chanceAmount > 0; chanceAmount--)
            {
                cout << "Give the date. There are " << chanceAmount << " chances. ";
                givenDate = AccessoryMethods::loadLine();
                dateWithoutDashes = AccessoryMethods::deletingDashesFromDate(givenDate);
                intDate2 = AccessoryMethods::convertStringToInt(dateWithoutDashes);

                if (dateIsCorrect(intDate2))
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

int Date::periodDateIsCorrect (int &dateToCheck)
{
    bool dateCheck = dateIsCorrect(dateToCheck);
    return (dateCheck) ? 1 : 0;
}

int Date::askCustomerAboutStartDate()
{
    int customerStartDate = 0;
    string customerChoice = "";
    string initialDescibe = "the initial date for the finance period: ";

    cout << "Please, write " << initialDescibe << endl;
    cin >> customerChoice;

    customerStartDate = convertCustomerDateToInt(customerChoice);
    while (!periodDateIsCorrect(customerStartDate))
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
    while (!periodDateIsCorrect(customerStopDate))
    {
        cout << "You gave the wrong date. Please, give the correct date: " << endl;
            cin >> customerChoice;
        customerStopDate = convertCustomerDateToInt(customerChoice);
    }
    return customerStopDate;
}
