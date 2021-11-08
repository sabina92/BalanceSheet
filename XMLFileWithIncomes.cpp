#include "XMLFileWithIncomes.h"

void XMLFileWithIncome::saveIncomeToXMLFIle(Income income)
{
    CMarkup xmlFileIncome;
    bool bSuccess = true;
    bSuccess = doesFileExist();

     if (!bSuccess)
     {
        xmlFileIncome.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileIncome.AddElem("Incomes");
     }

    xmlFileIncome.FindElem();
    xmlFileIncome.IntoElem();
    xmlFileIncome.AddElem("Income");
    xmlFileIncome.IntoElem();
    xmlFileIncome.AddElem("IncomeId", to_string(income.getFinanceId()));
    xmlFileIncome.AddElem("UserId", to_string(income.getUserId()));
    xmlFileIncome.AddElem("Date", income.getDate());
    xmlFileIncome.AddElem("Item", income.getItem());
    xmlFileIncome.AddElem("Amount", income.getAmount());

    xmlFileIncome.Save("Incomes.xml");
}

vector <Income> XMLFileWithIncome::loadIncomes()
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
        income.setFinanceId(atoi(MCD_2PCSZ(strIncomeId)));
        xmlFileIncome.FindElem("UserId");
        MCD_STR strUserId = xmlFileIncome.GetData();
        income.setUserId(atoi(MCD_2PCSZ(strUserId)));
        xmlFileIncome.FindElem("Date");
        MCD_STR strIncomeDate = xmlFileIncome.GetData();
        income.setDate(atoi(MCD_2PCSZ(strIncomeDate)));
        xmlFileIncome.FindElem("Item");
        MCD_STR strIncomeItem = xmlFileIncome.GetData();
        income.setItem(strIncomeItem);
        xmlFileIncome.FindElem("Amount");
        MCD_STR strIncomeAmount= xmlFileIncome.GetData();
        income.setAmount(strIncomeAmount);

        xmlFileIncome.OutOfElem();

        incomes.push_back(income);
    }
//    for (int i=0; i < incomes.size(); i++)
//    {
//        cout << incomes[i].getIncomeId() << endl;
//    }

    return incomes;
 }
