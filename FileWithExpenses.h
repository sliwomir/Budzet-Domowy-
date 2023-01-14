#ifndef  FILEWITHEXPENSES_H
#define  FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include "Markup.h"

#include "AuxiliaryFunctions.h"
#include "XmlFile.h"
#include "Expense.h"

using namespace std;

class FileWithExpenses: public XmlFile
{
    int lastExpenseId;

public:
    FileWithExpenses(string fileName)
        :XmlFile(fileName)
    {
        lastExpenseId = 0;
    }

    void saveExpense(Expense expense);
    vector <Expense> loadData(int loggedUserId);

    int getLastExpenseId();
    void setLastExpenseId(int id);

};

#endif
