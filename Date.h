#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "AccessoryMethods.h"


using namespace std;

class Date{
int date;


public:

 string retrieveActualDate();
 string retrievePreviousMonth();
 bool checkIfDateIsCorrect();
 int calculateHowManyDaysHaveMonth();
 bool compareDates();


};

#endif

