#include "FinanceCalculator.h"

void FinanceCalculator::userRegister()
{
    userManager.userRegister();
}

void FinanceCalculator::logInUser()
{
    userManager.logInUser();
    if(isUserLoggedIn())
    {
        expensesManager = new ExpensesManager(NAME_OF_FILE_WITH_EXPENSES, userManager.downloadTheLoggedInUserId());
        incomesManager = new IncomesManager(NAME_OF_FILE_WITH_INCOMES, userManager.downloadTheLoggedInUserId());
    }
}

bool FinanceCalculator::isUserLoggedIn()
{
    if (userManager.downloadTheLoggedInUserId() > 0)
        return true;
    else
        return false;
}

void FinanceCalculator::logOutUser()
{
    userManager.logOutUser();
    delete expensesManager;
    expensesManager = NULL;
    delete incomesManager;
    incomesManager = NULL;
}

void FinanceCalculator::showBalanceSheetFromCurrentMonth()
{
    vector <Expense> expenses;
    vector <Income> incomes;

    incomes = incomesManager->chooseIncomesFromCurrentMonth();
    AccessoryMethods::sortIncomes(incomes);
    cout << "There are incomes from current month: " << endl;
    AccessoryMethods::showIncomeVectorElements(incomes);

    expenses = expensesManager->chooseExpensesFromCurrentMonth();
    AccessoryMethods::sortExpenses(expenses);
    cout << "There are expenses from current month: " << endl;
    AccessoryMethods::showExpenseVectorElements(expenses);

    balanceSheet.showBalanceSheet(expenses, incomes, "current month");
    system("pause");
}

void FinanceCalculator::showBalanceSheetFromPreviousMonth()
{
    vector <Expense> expenses;
    vector <Income> incomes;

    incomes = incomesManager->chooseIncomesFromPrevioustMonth();
    AccessoryMethods::sortIncomes(incomes);
    cout << "There are incomes from current month: " << endl;
    AccessoryMethods::showIncomeVectorElements(incomes);

    expenses = expensesManager->chooseExpensesFromPrevioustMonth();
    AccessoryMethods::sortExpenses(expenses);
    cout << "There are expenses from current month: " << endl;
    AccessoryMethods::showExpenseVectorElements(expenses);

    balanceSheet.showBalanceSheet(expenses, incomes, "previous month");
    system("pause");
}

void FinanceCalculator::showBalanceSheetFromChoosenPeriod()
{
    vector <Expense> expenses;
    vector <Income> incomes;
    int customerStartDate = 0 , customerStopDate = 0;
    Date date;

    customerStartDate = date.askCustomerAboutStartDate();
    customerStopDate = date.askCustomerAboutStopDate();
    incomes = incomesManager->chooseIncomesFromChosenPeriod(customerStartDate, customerStopDate);
    AccessoryMethods::sortIncomes(incomes);
    cout << "There are incomes from chosen month: "  << endl;
    AccessoryMethods::showIncomeVectorElements(incomes);

    expenses = expensesManager->chooseExpensesFromChosenPeriod(customerStartDate, customerStopDate);;
    AccessoryMethods::sortExpenses(expenses);
    cout << "There are expenses from chosen month: " << endl;
    AccessoryMethods::showExpenseVectorElements(expenses);

    balanceSheet.showBalanceSheet(expenses, incomes, "chosen period");
    system("pause");
}

void FinanceCalculator::showMainMenu()
{
    char choice;
    while (true)
    {
        if (userManager.downloadTheLoggedInUserId() == 0)
        {
            choice = chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                userRegister();
                break;
            case '2':
                logInUser();
                break;
            case '9':
                logOutUser();
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in Main Menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                incomesManager->addIncome();
                break;
            case '2':
                expensesManager->addExpense();
                break;
            case '3':
                showBalanceSheetFromCurrentMonth();
                break;
            case '4':
                showBalanceSheetFromPreviousMonth();
                break;
            case '5':
                showBalanceSheetFromChoosenPeriod();
                break;
            case '6':
                userManager.changeLoggedInUserPassword();
                break;
            case '7':
                userManager.logOutUser();
                break;
            }
        }
    }
}

char FinanceCalculator::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register the user" << endl;
    cout << "2. Log  in the user" << endl;
    cout << "9. Exit the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadSign();

    return choice;
}

char FinanceCalculator::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add the income" << endl;
    cout << "2. Add the expense" << endl;
    cout << "3. Show Balance Sheet from current month" << endl;
    cout << "4. Show Balance Sheet from previous month" << endl;
    cout << "5. Show Balance Sheet from choosen period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change logged in the user password" << endl;
    cout << "7. Log out the user" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadSign();

    return choice;
}

char FinanceCalculator::loadSign()
{
    string enter = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "It is not a single sign. Write it again. " << endl;
    }
    return sign;
}
