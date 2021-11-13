#include "AccessoryMethods.h"


 void AccessoryMethods::askTheCustomer(string option)
{
    cout << "Please, write the " << option << endl;
}

 void AccessoryMethods::showAllVectorElements(vector <Expense> allElements)
{
    for (int k=0; k< allElements.size(); k++)
    {
        cout << allElements[k].getDate() << '-' << allElements[k].getItem() << '-' << allElements[k].getAmount() << endl;
    }
}

 void AccessoryMethods::showAllVectorElements2(vector <Income> allElements)
{
    for (int k=0; k< allElements.size(); k++)
    {
        cout << allElements[k].getDate() << '-' << allElements[k].getItem() << '-' << allElements[k].getAmount() << endl;
    }
}

 int AccessoryMethods::calculateTheSum(vector <Finance> allElements)
{
    int suma;
    for (int l=0; l< allElements.size(); l++)
    {
        suma += convertStringToInt(allElements[l].getAmount());
    }
    return suma;
}
 int AccessoryMethods::calculateTheDifference(int firstSum, int secondSum)
{
    int difference;
    return difference = firstSum - secondSum;
}

 string AccessoryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

 int AccessoryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
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
