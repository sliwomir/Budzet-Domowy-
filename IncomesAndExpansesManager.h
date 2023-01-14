#ifndef  INCOMEMANAGER_H
#define  INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryFunctions.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

#include <algorithm>
#include <functional>

using namespace std;

class IncomesAndExpansesManager
{
	vector <Income> incomes;
	vector <Expense> expenses;
	FileWithIncomes incomesFile;
	FileWithExpenses expensesFile;
    int loggedUserId;

    Income setNewIncome(int id);
    int getNewIncomeId();

    Expense setNewExpense(int id);
    int getNewExpenseId();



public:
    IncomesAndExpansesManager(int id, string fileNameWithIncomes, string fileNameWithExpenses)
    :incomesFile(fileNameWithIncomes),expensesFile(fileNameWithExpenses),loggedUserId(id)
{
    incomes = incomesFile.loadData(loggedUserId);
    expenses = expensesFile.loadData(loggedUserId);
}

    void addNewIncome(int id);
    void showIncomes();
    void addNewExpense(int id);
    void showExpenses();
    void setLoggedUserId(int id);

    vector <Income> sortIncomesFromLower(vector <Income> tmpIncomes);
    vector <Expense> sortExpensesFromLower(vector <Expense> tmpExpenses);

    void showBalanceForCurretnMonth();
    void shwoBalanceForPreviouslyMonth();
    void showBalanceForPeriodOfTime();
};
#endif
