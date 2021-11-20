#include "AccessoryMethods.h"

 string AccessoryMethods::convertIntToString(int number)
{
    string strNumber = to_string(number );
    return strNumber;
}

 int AccessoryMethods::convertStringToInt(string number)
{
    int intNumber = atoi(number.c_str());
    return intNumber;
}

 string AccessoryMethods::convertIntToStringWithDash(int number)
{
    string numberString;
    string numberWithDash;
    numberString = convertIntToString(number);
    string firstPartOfString;
    string secondPartOfString;
    string thirdPartOfString;

    for (int i=0; i < 4; i++)
    {
        firstPartOfString += numberString[i];
    }

       for (int i=4; i <6 ; i++)
    {
        secondPartOfString += numberString[i];
    }

     for (int i=6; i <8 ; i++)
    {
        thirdPartOfString += numberString[i];
    }

    numberWithDash = firstPartOfString + '-' + secondPartOfString + '-' + thirdPartOfString;
    return numberWithDash;
}

string AccessoryMethods::changePointToComa(string amount)
{
    for (int j = 0; j < amount.size(); j++)
    {
        if (amount[j] == ',')
            amount[j] = '.';
    }
    return amount;
}


string AccessoryMethods::loadLine()
{
    string enter = "";
    cin.sync();
    getline(cin, enter);
    return enter;
}

string AccessoryMethods::deletingDashesFromDate(string date)
{
    string newDate;
    for (int k=0; k < date.size(); k++)
    {
        if (date[k] != '-')
        {
            newDate += date[k];
        }
        else
            newDate = newDate;
    }
    return newDate;
}

