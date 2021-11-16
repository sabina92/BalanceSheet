#include "AccessoryMethods.h"


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

void AccessoryMethods::sortExpenses(vector <Expense> expenses)
{
    sort(expenses.begin(), expenses.end(),Expense::comp);
}

void AccessoryMethods::sortIncomes(vector <Income> incomes)
{
    sort(incomes.begin(), incomes.end(),Income::comp);
}

void AccessoryMethods::showExpenseVectorElements(vector <Expense> expenses)
{
    string dateWithDashes = "";
    for (int k=0; k< expenses.size(); k++)
    {
        dateWithDashes = convertIntToStringWithDash(expenses[k].getDate());
        cout << dateWithDashes << '-' << expenses[k].getItem() << '-' << expenses[k].getAmount() << endl;
    }
}

void AccessoryMethods::showIncomeVectorElements(vector <Income> incomes)
{
    string dateWithDashes = "";
    for (int k=0; k< incomes.size(); k++)
    {
        dateWithDashes = convertIntToStringWithDash(incomes[k].getDate());
        cout << dateWithDashes << '-' << incomes[k].getItem() << '-' << incomes[k].getAmount() << endl;
    }
}
