#ifndef  FILEWITHINCOMES_H
#define  FILEWITHINCOMES_H

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
#include "Income.h"

using namespace std;

class FileWithIncomes: public XmlFile
{
    int lastIncomeId;

public:
    FileWithIncomes(string fileName):XmlFile(fileName)
    {
     lastIncomeId = 0;
    }

    void saveIncome(Income income);
    vector <Income> loadData(int loggedUserId);

    int getLastIncomeId();
    void setLastIncomeId(int id);

};

#endif
