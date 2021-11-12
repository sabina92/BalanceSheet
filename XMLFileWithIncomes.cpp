#include "XMLFileWithIncomes.h"

bool XMLFileWithIncomes::saveIncomeToXMLFile(Income income)
{
    CMarkup xmlFileIncome;
    bool fileExists = xmlFileIncome.Load("incomes.xml" );

    if (!fileExists)
    {
        xmlFileIncome.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileIncome.AddElem("Incomes");
    }

    xmlFileIncome.FindElem();
    xmlFileIncome.IntoElem();

    while (xmlFileIncome.FindElem("Income"))
    {
        xmlFileIncome.IntoElem();
        xmlFileIncome.FindElem("IncomeId");
        MCD_STR strrId = xmlFileIncome.GetData();
        if (atoi(MCD_2PCSZ(strrId)) == idOfLastIncome)
        {
            xmlFileIncome.OutOfElem();
            break;
        }
            xmlFileIncome.OutOfElem();
    }
    xmlFileIncome.AddElem("Income");
    xmlFileIncome.IntoElem();
    xmlFileIncome.AddElem("IncomeId", to_string(income.getFinanceId()));
    xmlFileIncome.AddElem("IncomeUserId", to_string(income.getUserId()));
    xmlFileIncome.AddElem("IncomeDate", to_string(income.getDate()));
    xmlFileIncome.AddElem("IncomeItem", income.getItem());
    xmlFileIncome.AddElem("IncomeAmount", income.getAmount());

    cout << "1" << endl;
    xmlFileIncome.Save("incomes.xml");
    cout << "2" << endl;
    idOfLastIncome++;
    return true;
}

vector <Income> XMLFileWithIncomes::loadIncomes(int loggedInUserId)
{
    CMarkup xmlFileIncome;
    xmlFileIncome.Load( nameOfTemporaryXMLFileWithIncomes );
    Income income;
    vector <Income> incomes;
    xmlFileIncome.ResetPos();

    xmlFileIncome.FindElem();
    xmlFileIncome.IntoElem();

    while ( xmlFileIncome.FindElem("Income") )
    {
        xmlFileIncome.IntoElem();
        xmlFileIncome.FindElem("IncomeId");
        MCD_STR strIncomeId = xmlFileIncome.GetData();

        xmlFileIncome.FindElem("IncomeUserId");
        MCD_STR strUserId = xmlFileIncome.GetData();
        int intUserId = atoi(MCD_2PCSZ(strUserId));
        if (intUserId == loggedInUserId)
        {
            income.setFinanceId(atoi(MCD_2PCSZ(strIncomeId)));
            income.setUserId(atoi(MCD_2PCSZ(strUserId)));
            xmlFileIncome.FindElem("IncomeDate");
            MCD_STR strIncomeDate = xmlFileIncome.GetData();
            income.setDate(atoi(MCD_2PCSZ(strIncomeDate)));
            xmlFileIncome.FindElem("IncomeItem");
            MCD_STR strIncomeItem = xmlFileIncome.GetData();
            income.setItem(strIncomeItem);
            xmlFileIncome.FindElem("IncomeAmount");
            MCD_STR strIncomeAmount= xmlFileIncome.GetData();
            income.setAmount(strIncomeAmount);

            incomes.push_back(income);
        }

        xmlFileIncome.OutOfElem();

    }

    return incomes;
}

int XMLFileWithIncomes::downloadLastIncomeId()
{
    int lastIncomeId =0;
    CMarkup xmlFileIncome;
    bool fileExists = xmlFileIncome.Load( "incomes.xml" );

    if (!fileExists)
    {
        return 0;
    }

    xmlFileIncome.FindElem();
    xmlFileIncome.IntoElem();

    while (xmlFileIncome.FindElem("income"))
    {
        xmlFileIncome.IntoElem();
        xmlFileIncome.FindElem("incomeId");
        MCD_STR strrId = xmlFileIncome.GetData();
        lastIncomeId = (atoi(MCD_2PCSZ(strrId)));
        xmlFileIncome.OutOfElem();
    }
        return lastIncomeId;
}
