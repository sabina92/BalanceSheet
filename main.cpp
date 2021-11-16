#include <time.h>
#include <conio.h>
#include <iostream>
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

    FinanceCalculator financeCalculator("users.xml", "expenses.xml", "incomes.xml");
    financeCalculator.showMainMenu();

    return 0;
}
