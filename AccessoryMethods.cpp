#include "AccessoryMethods.h"

string AccessoryMethods::changePointToComa()
{

}


 int AccessoryMethods::changeCommaToPoint(int amountWithComma)
{

}
 string AccessoryMethods::askTheCustomerAboutItem()
{

}
 int AccessoryMethods::askTheCustomerAboutAmount()
{

}
 void AccessoryMethods::showAllVectorElements()
{

}
 int AccessoryMethods::calculateTheSum()
{

}
 int AccessoryMethods::calculateTheDifference()
{

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
