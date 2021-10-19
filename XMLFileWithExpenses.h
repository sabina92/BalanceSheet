#ifndef XMLFILEWITHEXPENSE_H
#define XMLFILEWITHEXPENSE_H

#include <iostream>
#include "Expense.h"
#include "XMLFile.h"
#include "Markup.h"
#include <vector>

using namespace std;

class XMLFileWithExpense : public XMLFile
{
string nameOfTemporaryXMLFileWithExpenses = "Expenses.xml";
int idOfLastExpense;

public:
    XMLFileWithExpense(string nameOfFile) : XMLFile(nameOfFile) {
    }
    bool saveExpenseToXMLFIle(Expense expense);
    vector <Expense> loadExpenses();

};

#endif
