#include <time.h>
#include <conio.h>
#include <iostream>
#include "XMLFile.h"
#include "XMLFileWithUsers.h"
#include "User.h"
#include "XMLFileWithExpenses.h"
#include "AccessoryMethods.h"

using namespace std;

int main() {

    time_t czas;
    struct tm * data;
    int rok, miesiac, dzien;
    const char * dzien_tygodnia[] = { "Niedziela", "Poniedzialek",
        "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota" };


    time( & czas );
    data = localtime( & czas );
    data->tm_year = rok - 1900;
    data->tm_mon = miesiac - 1;
    data->tm_mday = dzien;

    mktime( data );

    cout << "Dzien Twoich narodzin to: " << dzien_tygodnia[ data->tm_wday ];

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

    int number1 = 20180202;
    cout << endl << AccessoryMethods::convertIntToStringWithDash(number1) << endl;

    return 0;
}
