#include "ExpensesManager.h"

void ExpensesManager::addExpense()
{
    Date date;
    Expense expense;
    int intDate = 0;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

    intDate = *date.askCustomerAboutDate();
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

vector <Expense> ExpensesManager::chooseExpensesFromCurrentMonth()
{
    Date date;
    vector <Expense> expensesFromCurrentMonth;
    int actualMonth = 0, actualYear = 0, checkedMonth = 0, checkedYear = 0;

    actualMonth = date.giveTheActualMonth();
    actualYear = date.giveTheActualYear();

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

    for (int j = 0; j < allExpenses.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allExpenses[j].getDate());
        checkedYear = date.giveYearFromDate(allExpenses[j].getDate());
        if ((checkedMonth == previousMonth)&& (checkedYear == previousYear))
            expensesFromPreviousMonth.push_back(allExpenses[j]);
    }
    return expensesFromPreviousMonth;
}

vector <Expense> ExpensesManager::chooseExpensesFromChosenPeriod(int customerStartDate, int customerStopDate)
{
    Date date;
    vector <Expense> expensesFromChoosenPeriod;

    for (int j = 0; j < allExpenses.size(); j++)
    {
        if ((allExpenses[j].getDate() >= customerStartDate) && (allExpenses[j].getDate() <= customerStopDate))
            expensesFromChoosenPeriod.push_back(allExpenses[j]);
    }
    return expensesFromChoosenPeriod;
}

vector <Expense> ExpensesManager::getVector()
{
    return allExpenses;
}
