#include "Budget.h"



void Budget::userRegistration()
{
    userManager.userRegistration();
}

void Budget::userLogin()
{
    userManager.userLoging();
    if (userManager.isUserLogged())
    {
        incomesAndExpansesManager = new IncomesAndExpansesManager(userManager.getLoggedUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
    }
}

void Budget::logout()
{
    userManager.setLoggedUserId(0);

    delete incomesAndExpansesManager;
    incomesAndExpansesManager = NULL;
}

void Budget::changePassword()
{
    userManager.changePassword();
}

void Budget::addNewIncome()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->addNewIncome(userManager.getLoggedUserId());
    else
        cout << "Uzytkowanik nie jest zalogowany." << endl;
}

void Budget::addNewExpense()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->addNewExpense(userManager.getLoggedUserId());
    else
        cout << "Uzytkowanik nie jest zalogowany." << endl;
}

void Budget::showBalanceForCurretnMonth()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->showBalanceForCurretnMonth();
    else
        cout << "Uzytkowanik nie jest zalogowany." << endl;
}

void Budget::showBalanceForPreviouslyMonth()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->shwoBalanceForPreviouslyMonth();
    else
        cout << "Uzytkowanik nie jest zalogowany." << endl;
}

void Budget::showBalanceForPeriodOfTime()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->showBalanceForPeriodOfTime();
    else
        cout << "Uzytkowanik nie jest zalogowany." << endl;
}

bool Budget::isUserLogged()
{
    return userManager.isUserLogged();
}
