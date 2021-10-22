#include "XMLFileWithExpenses.h"

bool XMLFileWithExpense::saveExpenseToXMLFIle(Expense expense)
{
    CMarkup xmlFileExpense;
    bool bSuccess = true;
    bSuccess = doesFileExist();

     if (!bSuccess)
     {
        xmlFileExpense.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileExpense.AddElem("Expenses");
     }

    xmlFileExpense.FindElem();
    xmlFileExpense.IntoElem();
    xmlFileExpense.AddElem("Expense");
    xmlFileExpense.IntoElem();
    xmlFileExpense.AddElem("ExpenseId", to_string(expense.getFinanceId()));
    xmlFileExpense.AddElem("UserId", to_string(expense.getUserId()));
    xmlFileExpense.AddElem("Date", expense.getDate());
    xmlFileExpense.AddElem("Item", expense.getItem());
    xmlFileExpense.AddElem("Amount", expense.getAmount());

    xmlFileExpense.Save("Expenses.xml");
}

vector <Expense> XMLFileWithExpense::loadExpenses()
 {
    CMarkup xmlFileExpense;
    xmlFileExpense.Load( nameOfTemporaryXMLFileWithExpenses );
    Expense expense;
    vector <Expense> expenses;
    xmlFileExpense.ResetPos();

    xmlFileExpense.FindElem();
    xmlFileExpense.IntoElem();

    while ( xmlFileExpense.FindElem("Expense") )
    {
        xmlFileExpense.IntoElem();
        xmlFileExpense.FindElem("ExpenseId");
        MCD_STR strExpenseId = xmlFileExpense.GetData();
        expense.setFinanceId(atoi(MCD_2PCSZ(strExpenseId)));
        xmlFileExpense.FindElem("UserId");
        MCD_STR strUserId = xmlFileExpense.GetData();
        expense.setUserId(atoi(MCD_2PCSZ(strUserId)));
        xmlFileExpense.FindElem("Date");
        MCD_STR strExpenseDate = xmlFileExpense.GetData();
        expense.setDate(atoi(MCD_2PCSZ(strExpenseDate)));
        xmlFileExpense.FindElem("Item");
        MCD_STR strExpenseItem = xmlFileExpense.GetData();
        expense.setItem(strExpenseItem);
        xmlFileExpense.FindElem("Amount");
        MCD_STR strExpenseAmount= xmlFileExpense.GetData();
        expense.setAmount(strExpenseAmount);

        xmlFileExpense.OutOfElem();

        expenses.push_back(expense);
    }
//    for (int i=0; i < expenses.size(); i++)
//    {
//        cout << expenses[i].getExpenseId() << endl;
//    }

    return expenses;
 }
