#include <time.h>
#include <conio.h>
#include <iostream>
#include "XMLFile.h"
#include "XMLFileWithUsers.h"
#include "User.h"
#include "XMLFileWithExpenses.h"
#include "AccessoryMethods.h"
#include "Date.h"
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

    XMLFileWithUsers xmlFileUser("Users.xml");
    users = xmlFileUser.loadUsers();

//    for (int i =0; i<users.size(); i++)
//    {
//        cout << i << users[i].getPassword() << endl;
//    }

    vector <Expense> expenses;

    XMLFileWithExpense xmlFileWithExpense("Expenses.xml");
    expenses = xmlFileWithExpense.loadExpenses();

//    for (int i =0; i<expenses.size(); i++)
//    {
//        cout << i << expenses[i].getDate() << endl;
//    }

//    int number1 = 20180202;
//    cout << endl << AccessoryMethods::convertIntToStringWithDash(number1) << endl;

cout << AccessoryMethods::changePointToComa("12,12") << endl;


//Date date;
//cout << date.retrieveActualDate() << endl;
//cout << date.retrievePreviousMonth() << endl;
//cout << date.checkIfDateIsCorrect(19000228) << endl;
//cout << date.compareDates(19000505,19000506) << endl;

UserManager userManager("users.xml");
userManager.registerUser();

    return 0;
}
