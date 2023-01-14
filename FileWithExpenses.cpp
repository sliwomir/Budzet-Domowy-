#include "FileWithExpenses.h"


void FileWithExpenses::saveExpense(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( loadFileName() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expenses");
    xml.IntoElem();
    xml.AddElem("ExpenseId", AuxiliaryFunctions::intToString(expense.getEventId()));
    xml.AddElem("UserId", AuxiliaryFunctions::intToString(expense.getUserId()));
    xml.AddElem("Date", AuxiliaryFunctions::getFullDateAsStringWithDashes(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryFunctions::doubleToString(expense.getAmount()));

    xml.Save(loadFileName());
    lastExpenseId+=1;
}

vector <Expense> FileWithExpenses::loadData(int loggedUserId)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    string expenseId, userId, date, item, amount;

    bool fileExists = xml.Load( loadFileName() );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            expenseId = xml.GetData();
            expense.setEventId(AuxiliaryFunctions::convertingStringToInt(expenseId));
            lastExpenseId = AuxiliaryFunctions::convertingStringToInt(expenseId);

            xml.FindElem("UserId");
            userId = xml.GetData();
            if(loggedUserId == AuxiliaryFunctions::convertingStringToInt(userId))
            {
                expense.setUserId(AuxiliaryFunctions::convertingStringToInt(userId));
            }
            else
            {
                xml.RestorePos();
                continue;
            }

            xml.FindElem("Date");
            date = xml.GetData();
            expense.setDate(AuxiliaryFunctions::getFullDateFromString(date));

            xml.FindElem("Item");
            item = xml.GetData();
            expense.setItem(item);

            xml.FindElem("Amount");
            amount = xml.GetData();
            expense.setAmount(AuxiliaryFunctions::convertingStringToDouble(amount));

            expenses.push_back(expense);
            xml.RestorePos();
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void FileWithExpenses::setLastExpenseId(int id)
{
    lastExpenseId=id;
}
