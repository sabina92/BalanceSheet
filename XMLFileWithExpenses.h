#ifndef XMLFILEWITHEXPENSE_H
#define XMLFILEWITHEXPENSE_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "AccessoryMethods.h"
#include "Expense.h"
#include "XMLFile.h"
#include "Markup.h"


using namespace std;

class XMLFileWithExpense : public XMLFile
{
int idOfLastExpense;


public:
    XMLFileWithExpense(string nameOfFile) : XMLFile(nameOfFile) {
        idOfLastExpense = downloadLastExpenseId();
    }
    bool saveExpenseToXMLFile(Expense expense);
    vector <Expense> loadExpenses(int loggedInUserId);
    int downloadLastExpenseId();

};

#endif
