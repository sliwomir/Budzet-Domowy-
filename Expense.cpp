#include "Expense.h"

void Expense::setAmount(double newAmount)
{
    if(newAmount > 0)
    {
        newAmount *= -1;
        amount = newAmount;
    }
    else
    {
        amount = newAmount;
    }
}

double Expense::getAmount()
{
    return amount;
}

bool Expense::operator<(const Expense& expense)const
{
    return (date < expense.date);
}

bool Expense::operator>(const Expense& expense)const
{
    return (date > expense.date);
}
