#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Finance.h"
#include <string>
#include <vector>

using namespace std;

class Income : public Finance
{
    int incomeId;
    int incomeUserId;
    int incomeDate;
    string incomeItem;
    int incomeAmount;

public:

};

#endif

