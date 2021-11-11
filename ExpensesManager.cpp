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


vector <Expense> ExpensesManager::chooseExpensesFromCurrentMonth()
{
    vector <Expense> expensesFromCurrentMonth;
    Date date;
    int actualMonth = 0, actualDate = 0, checkedMonth = 0;
    actualDate = date.retrieveActualDate();
    actualMonth = date.giveMonthFromDate(actualDate);

    for (int j = 0; j < allExpenses.size(); j++)
    {
        checkedMonth = date.giveMonthFromDate(allExpenses[j].getDate());
        if (checkedMonth == actualMonth)
            expensesFromCurrentMonth.push_back(allExpenses[j]);
    }
    return expensesFromCurrentMonth;
}

vector <Expense> chooseExpensesFromPrevioustMonth();
vector <Expense> chooseExpensesFromChosenPeriod();

vector <Expense> ExpensesManager::getVector()
{
    return allExpenses;
}
