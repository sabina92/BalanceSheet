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

int main() {

//    time_t czas;
//    struct tm * data;
//    int rok, miesiac, dzien;
//    const char * dzien_tygodnia[] = { "Niedziela", "Poniedzialek",
//        "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota" };
//
//
//    time( & czas );
//    data = localtime( & czas );
//    data->tm_year = rok - 1900;
//    data->tm_mon = miesiac - 1;
//    data->tm_mday = dzien;

//    cout << data->tm_year + 1900 << " " << data->tm_mon + 1 << " "<< data->tm_mday << endl;
//
//    mktime( data );


//    cout << "Dzien Twoich narodzin to: " << dzien_tygodnia[ data->tm_wday ] << endl;

//    cout << data->tm_year << " " << data->tm_mon << " "<< data->tm_mday << endl;

    //getch();

    vector <User> users;

//    XMLFileWithUsers xmlFileUser("Users.xml");
//    users = xmlFileUser.loadUsers();

//    for (int i =0; i<users.size(); i++)
//    {
//        cout << i << users[i].getPassword() << endl;
//    }

//    vector <Expense> expenses;
//
//    XMLFileWithExpense xmlFileWithExpense("Expenses.xml");


//    for (int i =0; i<expenses.size(); i++)
//    {
//        cout << i << expenses[i].getDate() << endl;
//    }

//    int number1 = 20180202;
//    cout << endl << AccessoryMethods::convertIntToStringWithDash(number1) << endl;

//cout << AccessoryMethods::changePointToComa("12,12") << endl;
//

//Date date;
//cout << date.retrieveActualDate() << endl;
//cout << date.retrievePreviousMonth() << endl;
//cout <<"date" << date.checkIfDateIsCorrect(19000228) << endl;
//cout <<"date" << date.checkIfDateIsCorrect(20000818) << endl;
//system("pause");
//cout << date.compareDates(19000505,19000506) << endl;
//

//UserManager userManager("users.xml");
//userManager.registerUser();
//userManager.registerUser();
//userManager.logInUser();

//IncomesManager incomesManager("incomes.xml", 2);
//incomesManager.sortIncomes();
//incomesManager.showVectorElements();

//vector <Income> incomesFromCurrentMonth;
//incomesFromCurrentMonth = incomesManager.chooseIncomesFromCurrentMonth();
//cout << "------------------" << endl;
//AccessoryMethods::showAllVectorElements2(incomesFromCurrentMonth);
//
//vector <Income> incomesFromPreviousMonth;
//incomesFromPreviousMonth = incomesManager.chooseIncomesFromPrevioustMonth();
//cout << "--------------------" << endl;
//AccessoryMethods::showAllVectorElements2(incomesFromPreviousMonth);
//
//vector <Income> incomesFromChoosenPeriod;
//incomesFromChoosenPeriod = incomesManager.chooseIncomesFromChosenPeriod();
//cout << "--------------------" << endl;
//AccessoryMethods::showAllVectorElements2(incomesFromChoosenPeriod);

    FinanceCalculator financeCalculator("users.xml", "expenses.xml", "incomes.xml");
   financeCalculator.showMainMenu();

    return 0;
}
