#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomesAndExpansesManager.h"

using namespace std;

class Budget
{
	UserManager userManager;
	IncomesAndExpansesManager *incomesAndExpansesManager;

	string const FILE_NAME_WITH_INCOMES;
	string const FILE_NAME_WITH_EXPENSES;

public:
    Budget(string fileName, string fileNameWithIncomes, string fileNameWithExpenses)
    :userManager(fileName),FILE_NAME_WITH_INCOMES(fileNameWithIncomes),FILE_NAME_WITH_EXPENSES(fileNameWithExpenses){}

    void userRegistration();
    void userLogin();
    void logout();
    void changePassword();

    void addNewIncome();
    void addNewExpense();

    void showBalanceForCurretnMonth();
    void showBalanceForPreviouslyMonth();
    void showBalanceForPeriodOfTime();

    bool isUserLogged();

};

#endif
