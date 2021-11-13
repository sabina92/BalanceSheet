#include "IncomesManager.h"

void IncomesManager::addIncome()
{
    Income income;
    Date date;
    int intDate = 0;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;

    intDate = *date.askCustomerAboutDate();
    income = giveNewIncomeData(intDate);

    allIncomes.push_back(income);
    cout << xmlFileWithIncomes.downloadLastIncomeId() << endl;
    if (xmlFileWithIncomes.saveIncomeToXMLFile(income))
        cout << "New income was added." << endl;
    else
        cout << "New income addition failed." << endl;
    system("pause");
}


Income IncomesManager::giveNewIncomeData(int intDate)
{
    Income income;
    int incomeId = 0, incomeUserId = 0, incomeDate = 0;
    string incomeItem = "", incomeAmount = "", amountBeforeChecking ="";

    income.setFinanceId( (xmlFileWithIncomes.downloadLastIncomeId() + 1) );
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(intDate);

    cout << "Give the income item: ";
    incomeItem = AccessoryMethods::loadLine();
    income.setItem(incomeItem);

    cout << "Give the income amount: ";
    amountBeforeChecking = AccessoryMethods::loadLine();
    incomeAmount = AccessoryMethods::changePointToComa(amountBeforeChecking);
    income.setAmount(incomeAmount);

    return income;
}


void IncomesManager::sortIncomes()
{
    sort(allIncomes.begin(), allIncomes.end(),Income::comp);
}

void IncomesManager::showVectorElements()
{

    for (int k=0; k< allIncomes.size(); k++)
    {
        cout << allIncomes[k].getDate() << '-' << allIncomes[k].getItem() << '-' << allIncomes[k].getAmount() << endl;
    }
}

vector <Income> IncomesManager::chooseIncomesFromCurrentMonth()
{
    Date date;
    vector <Income> incomesFromCurrentMonth;
    int actualMonth = 0, actualYear = 0, checkedMonth = 0, checkedYear = 0;

    actualMonth = date.giveTheActualMonth();
    actualYear = date.giveTheActualYear();

    for (int j = 0; j < allIncomes.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allIncomes[j].getDate());
        checkedYear = date.giveYearFromDate(allIncomes[j].getDate());
        if ((checkedMonth == actualMonth)&& (checkedYear == actualYear))
            incomesFromCurrentMonth.push_back(allIncomes[j]);
    }
    return incomesFromCurrentMonth;
}

vector <Income> IncomesManager::chooseIncomesFromPrevioustMonth()
{
    Date date;
    vector <Income> incomesFromPreviousMonth;
    int actualMonth = 0, actualYear = 0, checkedMonth = 0, checkedYear = 0, previousMonth = 0, previousYear = 0;

    actualMonth = date.giveTheActualMonth();
    actualYear = date.giveTheActualYear();

    if (actualMonth == 1)
    {
        previousMonth = 12;
        previousYear = actualYear - 1;
    }
    else
    {
        previousMonth = actualMonth - 1;
        previousYear = actualYear;
    }

    for (int j = 0; j < allIncomes.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allIncomes[j].getDate());
        checkedYear = date.giveYearFromDate(allIncomes[j].getDate());
        if ((checkedMonth == previousMonth)&& (checkedYear == previousYear))
            incomesFromPreviousMonth.push_back(allIncomes[j]);
    }
    return incomesFromPreviousMonth;
}

vector <Income> IncomesManager::chooseIncomesFromChosenPeriod(int customerStartDate, int customerStopDate)
{
    Date date;
    vector <Income> incomesFromChoosenPeriod;

    for (int j = 0; j < allIncomes.size(); j++)
    {
        if ((allIncomes[j].getDate() >= customerStartDate) && (allIncomes[j].getDate() <= customerStopDate))
            incomesFromChoosenPeriod.push_back(allIncomes[j]);
    }
    return incomesFromChoosenPeriod;
}


vector <Income> IncomesManager::getVector()
{
    return allIncomes;
}
