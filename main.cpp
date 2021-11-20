#include <time.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "XMLFile.h"
#include "XMLFileWithUsers.h"
#include "User.h"
#include "XMLFileWithExpenses.h"
#include "AccessoryMethods.h"
#include "Date.h"
#include "ExpensesManager.h"
#include "IncomesManager.h"
#include "FinanceCalculator.h"

#include "UserManager.h"


using namespace std;

int main()
{

    cout << AccessoryMethods::convertIntToString(5) << endl;
    cout << AccessoryMethods::convertStringToInt("5") << endl;
    system("pause");
    FinanceCalculator financeCalculator("users.xml", "expenses.xml", "incomes.xml");
    financeCalculator.showMainMenu();


    return 0;
}
