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
                }
            }
            cout << "You entered the wrong date 3 times." << endl;
            system("pause");
            intDate = 0;
            return intDate;
        }
        return intDate;
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
    Date date;
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

vector <Expense> sortExpenses();
vector <Expense> chooseExpensesFromCurrentMonth();
vector <Expense> chooseExpensesFromPrevioustMonth();
vector <Expense> chooseExpensesFromChosenPeriod();
