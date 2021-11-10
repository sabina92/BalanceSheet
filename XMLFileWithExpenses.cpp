#include "XMLFileWithExpenses.h"

bool XMLFileWithExpense::saveExpenseToXMLFile(Expense expense)
{
    CMarkup xmlFileExpense;
    bool fileExists = xmlFileExpense.Load("expenses.xml" );

    if (!fileExists)
    {
        xmlFileExpense.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileExpense.AddElem("Expenses");
    }

    xmlFileExpense.FindElem();
    xmlFileExpense.IntoElem();

    while (xmlFileExpense.FindElem("Expense"))
    {
        xmlFileExpense.IntoElem();
        xmlFileExpense.FindElem("ExpenseId");
        MCD_STR strrId = xmlFileExpense.GetData();
        if (atoi(MCD_2PCSZ(strrId)) == idOfLastExpense)
        {
            xmlFileExpense.OutOfElem();
            break;
        }
            xmlFileExpense.OutOfElem();
    }
    xmlFileExpense.AddElem("Expense");
    xmlFileExpense.IntoElem();
    xmlFileExpense.AddElem("ExpenseId", to_string(expense.getFinanceId()));
    xmlFileExpense.AddElem("ExpenseUserId", to_string(expense.getUserId()));
    xmlFileExpense.AddElem("ExpenseDate", to_string(expense.getDate()));
    xmlFileExpense.AddElem("ExpenseItem", expense.getItem());
    xmlFileExpense.AddElem("ExpenseAmount", expense.getAmount());

    cout << "1" << endl;
    xmlFileExpense.Save("expenses.xml");
    cout << "2" << endl;
    idOfLastExpense++;
    return true;
}

vector <Expense> XMLFileWithExpense::loadExpenses(int loggedInUserId)
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

        xmlFileExpense.FindElem("UserId");
        MCD_STR strUserId = xmlFileExpense.GetData();
        int intUserId = atoi(MCD_2PCSZ(strUserId));
        if (intUserId == loggedInUserId)
        {
            expense.setFinanceId(atoi(MCD_2PCSZ(strExpenseId)));
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

            expenses.push_back(expense);
        }

        xmlFileExpense.OutOfElem();

    }

    return expenses;
}

int XMLFileWithExpense::downloadLastExpenseId()
{
    int lastExpenseId =0;
    CMarkup xmlFileExpense;
    bool fileExists = xmlFileExpense.Load( "expenses.xml" );

    if (!fileExists)
    {
        return 0;
    }

    xmlFileExpense.FindElem();
    xmlFileExpense.IntoElem();

    while (xmlFileExpense.FindElem("Expense"))
    {
        xmlFileExpense.IntoElem();
        xmlFileExpense.FindElem("ExpenseId");
        MCD_STR strrId = xmlFileExpense.GetData();
        lastExpenseId = (atoi(MCD_2PCSZ(strrId)));
        xmlFileExpense.OutOfElem();
    }
        return lastExpenseId;
}
