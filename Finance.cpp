#include "Finance.h"

 void Finance::setFinanceId(int newFinanceId)
    {
        if (newFinanceId >= 0)
        financeId = newFinanceId;
    }

void Finance::setUserId(int newUserId)
{
    userId = newUserId;
}

void Finance::setDate(int newDate)
{
    date = newDate;
}

void Finance::setItem(string newItem)
{
    item = newItem;
}

void Finance::setAmount(int newAmount)
{
    amount = newAmount;
}

int Finance::getFinanceId()
{
    return financeId;
}

int Finance::getUserId()
{
    return userId;
}

int Finance::getDate()
{
    return date;
}

string Finance::getItem()
{
    return item;
}

int Finance::getAmount()
{
    return amount;
}
