#ifndef XMLFILEWITHINCOME_H
#define XMLFILEWITHINCOME_H

#include <iostream>
#include "XMLFile.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class XMLFileWithIncome : public XMLFile
{
string nameOfTemporaryXMLFileWithIncomes = "Incomes.xml";

public:
    XMLFileWithIncome(string nameOfFile) : XMLFile(nameOfFile) {
    }
    void saveIncomeToXMLFIle(Income income);
    vector <Income> loadIncomes();


};

#endif
