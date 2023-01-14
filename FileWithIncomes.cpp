#include "FileWithIncomes.h"



void FileWithIncomes::saveIncome(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load( loadFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", AuxiliaryFunctions::intToString(income.getEventId()));
    xml.AddElem("UserId", AuxiliaryFunctions::intToString(income.getUserId()));
    xml.AddElem("Date", AuxiliaryFunctions::getFullDateAsStringWithDashes(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryFunctions::doubleToString(income.getAmount()));

    xml.Save(loadFileName());
    lastIncomeId+=1;
}

vector <Income> FileWithIncomes::loadData(int loggedUserId)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    string incomeId, userId, date, item, amount;

    bool fileExists = xml.Load( loadFileName() );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("IncomeId");
            incomeId = xml.GetData();
            income.setEventId(AuxiliaryFunctions::convertingStringToInt(incomeId));
            lastIncomeId = AuxiliaryFunctions::convertingStringToInt(incomeId);

            xml.FindElem("UserId");
            userId = xml.GetData();
            if(loggedUserId == AuxiliaryFunctions::convertingStringToInt(userId))
            {
                income.setUserId(AuxiliaryFunctions::convertingStringToInt(userId));
            }
            else
            {
                xml.RestorePos();
                continue;
            }

            xml.FindElem("Date");
            date = xml.GetData();
            income.setDate(AuxiliaryFunctions::getFullDateFromString(date));

            xml.FindElem("Item");
            item = xml.GetData();
            income.setItem(item);

            xml.FindElem("Amount");
            amount = xml.GetData();
            income.setAmount(AuxiliaryFunctions::convertingStringToDouble(amount));

            incomes.push_back(income);
            xml.RestorePos();
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

void FileWithIncomes::setLastIncomeId(int id)
{
    lastIncomeId=id;
}
