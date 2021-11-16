#ifndef XMLFILEWITHINCOME_H
#define XMLFILEWITHINCOME_H

#include <iostream>
#include "XMLFile.h"
#include "Income.h"
#include "Markup.h"
#include "AccessoryMethods.h"

using namespace std;

class XMLFileWithIncomes : public XMLFile
{
string nameOfTemporaryXMLFileWithIncomes = "incomes.xml";
int idOfLastIncome;

public:
    XMLFileWithIncomes(string nameOfFile) : XMLFile(nameOfFile) {
        idOfLastIncome = downloadLastIncomeId();
    }
    bool saveIncomeToXMLFile(Income income);
    vector <Income> loadIncomes(int loggedInUserId);
    int downloadLastIncomeId();


};

#endif
