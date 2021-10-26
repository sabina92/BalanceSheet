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


public:

 int retrieveActualDate();
 int retrievePreviousMonth();
 bool checkIfDateIsCorrect();
 int calculateHowManyDaysHaveMonth();
 bool compareDates();


};

#endif

