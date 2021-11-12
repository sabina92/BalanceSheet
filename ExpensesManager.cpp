#include "ExpensesManager.h"

int *ExpensesManager::checkDate()
{
    Date date;
    int *intDate;
    int newDate = 0;
    string givenDate = "", dateWithoutDashes = "";
    cout << "If you want to add the today's date, write: YES. If not, give your date" << endl;
    givenDate = AccessoryMethods::loadLine();

    if (givenDate == "YES")
    {
        newDate = date.retrieveActualDate();
        cout << newDate << endl;
        intDate = &newDate;
        return intDate;
        delete intDate;
    }
    else
    {
        dateWithoutDashes = AccessoryMethods::deletingDashesFromDate(givenDate);

        int intDate2 = AccessoryMethods::convertStringToInt(dateWithoutDashes);
        intDate = &intDate2;

        if(!date.checkIfDateIsCorrect(intDate2))
        {
            cout << "You gave the wrong date. Please, give the date once again. You have 3 chances." << endl;
            for (int chanceAmount = 3; chanceAmount > 0; chanceAmount--)
            {
                cout << "Give the date. There are " << chanceAmount << " chances. ";
                givenDate = AccessoryMethods::loadLine();
                dateWithoutDashes = AccessoryMethods::deletingDashesFromDate(givenDate);
                intDate2 = AccessoryMethods::convertStringToInt(dateWithoutDashes);

                if (date.checkIfDateIsCorrect(intDate2) )
                {
                    return intDate;
                    delete intDate;
                }
            }
            cout << "You entered the wrong date 3 times." << endl;
            system("pause");
            intDate = 0;
            return intDate;
            delete intDate;
        }
        return intDate;
        delete intDate;
    }
}


void ExpensesManager::addExpense()
{
    Expense expense;
    int intDate = 0;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

    intDate = *checkDate();
    expense = giveNewExpenseData(intDate);

    allExpenses.push_back(expense);
    cout << xmlFileWithExpenses.downloadLastExpenseId() << endl;
    if (xmlFileWithExpenses.saveExpenseToXMLFile(expense))
        cout << "New expense was added." << endl;
    else
        cout << "New expense addition failed." << endl;
    system("pause");
}


Expense ExpensesManager::giveNewExpenseData(int intDate)
{
    Expense expense;
    int expenseId = 0, expenseUserId = 0, expenseDate = 0;
    string expenseItem = "", expenseAmount = "", amountBeforeChecking ="";

    expense.setFinanceId( (xmlFileWithExpenses.downloadLastExpenseId() + 1) );
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(intDate);

    cout << "Give the expense item: ";
    expenseItem = AccessoryMethods::loadLine();
    expense.setItem(expenseItem);

    cout << "Give the expense amount: ";
    amountBeforeChecking = AccessoryMethods::loadLine();
    expenseAmount = AccessoryMethods::changePointToComa(amountBeforeChecking);
    expense.setAmount(expenseAmount);

    return expense;
}


void ExpensesManager::sortExpenses()
{
    sort(allExpenses.begin(), allExpenses.end(),Expense::comp);
}

void ExpensesManager::showVectorElements()
{

    for (int k=0; k< allExpenses.size(); k++)
    {
        cout << allExpenses[k].getDate() << '-' << allExpenses[k].getItem() << '-' << allExpenses[k].getAmount() << endl;
    }
}

int ExpensesManager::giveTheActualMonth()
{
    Date date;
    int actualMonth = 0, actualDate = 0;
    actualDate = date.retrieveActualDate();
    actualMonth = date.giveMonthFromDate(actualDate);

    return actualMonth;
}

int ExpensesManager::giveTheActualYear()
{
    Date date;
    int actualYear = 0, actualDate = 0;
    actualDate = date.retrieveActualDate();
    actualYear = date.giveYearFromDate(actualDate);

    return actualYear;
}

vector <Expense> ExpensesManager::chooseExpensesFromCurrentMonth()
{
    Date date;
    vector <Expense> expensesFromCurrentMonth;
    int actualMonth = 0, actualYear = 0, checkedMonth = 0, checkedYear = 0;

    actualMonth = giveTheActualMonth();
    actualYear = giveTheActualYear();

    for (int j = 0; j < allExpenses.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allExpenses[j].getDate());
        checkedYear = date.giveYearFromDate(allExpenses[j].getDate());
        if ((checkedMonth == actualMonth)&& (checkedYear == actualYear))
            expensesFromCurrentMonth.push_back(allExpenses[j]);
    }
    return expensesFromCurrentMonth;
}

vector <Expense> ExpensesManager::chooseExpensesFromPrevioustMonth()
{
    Date date;
    vector <Expense> expensesFromPreviousMonth;
    int actualMonth = 0, actualYear = 0, checkedMonth = 0, checkedYear = 0, previousMonth = 0, previousYear = 0;

    actualMonth = giveTheActualMonth();
    actualYear = giveTheActualYear();

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

    for (int j = 0; j < allExpenses.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allExpenses[j].getDate());
        checkedYear = date.giveYearFromDate(allExpenses[j].getDate());
        if ((checkedMonth == previousMonth)&& (checkedYear == previousYear))
            expensesFromPreviousMonth.push_back(allExpenses[j]);
    }
    return expensesFromPreviousMonth;
}

int ExpensesManager::convertCustomerDateToInt(string dateDescribe)
{
    int customerDate = 0;
    string stringCustomerDate = "", customerDateWithoutDashes = "";

    AccessoryMethods::askTheCustomer(dateDescribe);
    stringCustomerDate = AccessoryMethods::loadLine();
    customerDateWithoutDashes = AccessoryMethods::deletingDashesFromDate(stringCustomerDate);
    customerDate = AccessoryMethods::convertStringToInt(customerDateWithoutDashes);
    return customerDate;
}

vector <Expense> ExpensesManager::chooseExpensesFromChosenPeriod()
{
    vector <Expense> expensesFromChoosenPeriod;
    int customerStartDate = 0, customerStopDate = 0;
    string initialDescibe = "the initial date for the expense period: ", finalDescibe = "the final date for the expense period: ";

    customerStartDate = convertCustomerDateToInt(initialDescibe);
    while (!checkPeriodDate(customerStartDate))
    {
        cout << "You gave the wrong date. Please, give the correct date: " << endl;
        customerStartDate = convertCustomerDateToInt(initialDescibe);
    }

        customerStopDate = convertCustomerDateToInt(finalDescibe);
    while (!checkPeriodDate(customerStopDate))
    {
        cout << "You gave the wrong date. Please, give the correct date: " << endl;
        customerStopDate = convertCustomerDateToInt(finalDescibe);
    }

    for (int j = 0; j < allExpenses.size(); j++)
    {
        if ((allExpenses[j].getDate() >= customerStartDate) && (allExpenses[j].getDate() <= customerStopDate))
            expensesFromChoosenPeriod.push_back(allExpenses[j]);
    }
    return expensesFromChoosenPeriod;
}

int ExpensesManager::checkPeriodDate (int dateToCheck)
{
    Date date;
    bool dateCheck = date.checkIfDateIsCorrect(dateToCheck);
    if (dateCheck == true)
        return 1;
    else
        return 0;
}

vector <Expense> ExpensesManager::getVector()
{
    return allExpenses;
}
