#include "IncomesAndExpansesManager.h"



void IncomesAndExpansesManager::addNewIncome(int id)
{
    Income income = setNewIncome(id);
    incomes.push_back(income);

    incomesFile.saveIncome(income);
    cout << endl << "Przychod wpisano pomyslnie" << endl << endl;
    system("pause");
}

Income IncomesAndExpansesManager::setNewIncome(int id)
{
    Income income;
    income.setEventId(getNewIncomeId());
    income.setUserId(id);

    string date;
    string item;
    string amountAsString;
    double amount;
    char choice;

    cout << endl <<"Ustawic dzisiejsza date przychodu?: [t/n] ";
    cin >> choice;
    if(choice == 't')
    {
        income.setDate(AuxiliaryFunctions::getCurrentDate());
    }
    else
    {
        do
        {
            cout << endl <<"Podaj date nowego przychodu w formacie rrrr-mm-dd: ";
            cin >> date;
        }
        while(! AuxiliaryFunctions::isDateCorrect(date));
        income.setDate(AuxiliaryFunctions::getFullDateFromString(date));
    }

    cout << "Podaj czego dotyczy przychod np. wyplata, odsetki z lokaty, sprzedaz na allegro: ";
    cin.sync();
    getline(cin,item);
    income.setItem(item);

    cout << "Jaka wartosc przychodu?: ";
    while(true)
    {
        cin >> amountAsString;
        amountAsString = AuxiliaryFunctions::changeCommaToDot(amountAsString);
        cout << "Przychod dodany" << endl;
        if(AuxiliaryFunctions::isNumber(amountAsString))
        {
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie: ";
    }
    amount = AuxiliaryFunctions::convertingStringToDouble(amountAsString);
    income.setAmount(amount);
    return income;
}

int IncomesAndExpansesManager::getNewIncomeId()
{
    return incomesFile.getLastIncomeId()+1;
}

void IncomesAndExpansesManager::addNewExpense(int id)
{
    Expense expense = setNewExpense(id);
    expenses.push_back(expense);

    expensesFile.saveExpense(expense);

    cout << endl << "Wydatek wpisano pomyslnie" << endl << endl;
    system("pause");

}

Expense IncomesAndExpansesManager::setNewExpense(int id)
{
    Expense expense;
    expense.setEventId(getNewExpenseId());
    expense.setUserId(id);

    string date;
    string item;
    string amountAsString;
    double amount;
    char choice;

    cout << endl << "Ustawic dzisiejsza date wydatku?: [t/n] ";
    cin >> choice;
    if(choice == 't' )
    {
        expense.setDate(AuxiliaryFunctions::getCurrentDate());
    }
    else
    {
        do
        {
            cout << endl <<"Podaj date nowego wydatku w formacie rrrr-mm-dd: ";
            cin >> date;
        }
        while(! AuxiliaryFunctions::isDateCorrect(date));
        expense.setDate(AuxiliaryFunctions::getFullDateFromString(date));
    }
    cout << "Czego dotyczy wydatek np. zakupy,rachunki: ";
    cin.sync();
    getline(cin,item);
    expense.setItem(item);

    cout << "Jaka wartosc wydatku?: ";
    while(true)
    {
        cin >> amountAsString;
        amountAsString = AuxiliaryFunctions::changeCommaToDot(amountAsString);
        cout << "Wydatek dodany" << endl;
        if(AuxiliaryFunctions::isNumber(amountAsString))
        {
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie: ";
    }
    amount = AuxiliaryFunctions::convertingStringToDouble(amountAsString);
    expense.setAmount(amount);

    return expense;

}

int IncomesAndExpansesManager::getNewExpenseId()
{
    return expensesFile.getLastExpenseId()+1;
}



void IncomesAndExpansesManager::showIncomes()
{
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getEventId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(incomes[i].getDate())<< endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
        cout << endl;
    }
    system("pause");
}

void IncomesAndExpansesManager::showExpenses()
{
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        cout << expenses[i].getEventId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(expenses[i].getDate())<<endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
        cout << endl;
    }
    system("pause");
}

void IncomesAndExpansesManager::setLoggedUserId(int id)
{
    loggedUserId = id;
}

void IncomesAndExpansesManager::showBalanceForCurretnMonth()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;

    int beginningDate = (AuxiliaryFunctions::getCurrentYear() *10000) + (AuxiliaryFunctions::getCurrentMonth() *100) + 1;
    int endingDate = AuxiliaryFunctions::getCurrentDay();
    int i=0;
    double incomesSum = 0, expensesSum = 0;

    tmpIncomes = sortIncomesFromLower(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while((unsigned)i < tmpIncomes.size() && tmpIncomes[i].getDate() >= endingDate)
    {
        if(tmpIncomes[i].getDate() >= beginningDate)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpIncomes[i].getDate())<<"\t";
            cout << tmpIncomes[i].getItem()<<"\t";
            cout << tmpIncomes[i].getAmount() << endl;
            incomesSum +=tmpIncomes[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma przychodow z biezacego miesiaca: " << incomesSum << endl;
    cout << endl << endl;

    i=0;
    tmpExpenses = sortExpensesFromLower(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while((unsigned)i < tmpExpenses.size() && tmpExpenses[i].getDate() >= endingDate)
    {
        if(tmpExpenses[i].getDate() >= beginningDate)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpExpenses[i].getDate()) << "\t";
            cout << tmpExpenses[i].getItem() << "\t";
            cout << tmpExpenses[i].getAmount() << endl;
            expensesSum += tmpExpenses[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma wydatkow z biezacego miesiaca: " << expensesSum << endl;
    cout << endl << endl;

    cout << "Roznica przychodow i wydatkow: " << incomesSum + expensesSum << endl;

    system("pause");
}

void IncomesAndExpansesManager::shwoBalanceForPreviouslyMonth()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;

    int currentMonthBeginning = (AuxiliaryFunctions::getCurrentYear()*10000) + (AuxiliaryFunctions::getCurrentMonth()*100) + 1;

    int previouslyMonthBeginning;
    if(AuxiliaryFunctions::getCurrentMonth() == 1)
    {
        int previouslyMonth = 12;
        previouslyMonthBeginning = ((AuxiliaryFunctions::getCurrentYear()-1)*10000) + (previouslyMonth *100) + 1;
    }
    else
    {
        int previouslyMonth = AuxiliaryFunctions::getCurrentMonth() - 1;
        previouslyMonthBeginning = (AuxiliaryFunctions::getCurrentYear()*10000) + (previouslyMonth *100) + 1;
    }

    int i=0;
    double incomesSum = 0, expensesSum = 0;

    tmpIncomes = sortIncomesFromLower(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while((unsigned)i < tmpIncomes.size() && tmpIncomes[i].getDate() >= previouslyMonthBeginning)
    {
        if(tmpIncomes[i].getDate() < currentMonthBeginning)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpIncomes[i].getDate())<<"\t";
            cout << tmpIncomes[i].getItem() << "\t";
            cout << tmpIncomes[i].getAmount() << endl;
            incomesSum +=tmpIncomes[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma przychodow z poprzedniego miesiaca: " << incomesSum << endl;

    cout << endl << endl;
    i=0;
    tmpExpenses = sortExpensesFromLower(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while((unsigned)i < tmpExpenses.size() && tmpExpenses[i].getDate() >= previouslyMonthBeginning)
    {
        if(tmpExpenses[i].getDate() < currentMonthBeginning)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpExpenses[i].getDate())<<"\t";
            cout << tmpExpenses[i].getItem() << "\t";
            cout << tmpExpenses[i].getAmount() << endl;
            expensesSum += tmpExpenses[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma wydatkow z poprzedniego miesiaca: " << expensesSum << endl;
    cout << endl << endl;

    cout << "Roznica przychodow i wydatkow: " << incomesSum + expensesSum << endl;

    system("pause");
}

void IncomesAndExpansesManager::showBalanceForPeriodOfTime()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;
    string date;
    int beginningDate, endingDate;
    char choice;
    int i=0;
    double incomesSum = 0, expensesSum = 0;

    do
    {
        cout << "Podaj date poczatku okresu z ktorego chcesz raport formacie rrrr-mm-dd: ";
        cin >> date;
    }
    while(! AuxiliaryFunctions::isDateCorrect(date));
    beginningDate = AuxiliaryFunctions::getFullDateFromString(date);



    cout << "Czy chcesz ustawic koniec okresu na dzien dzisiejszy?: [t/n] ";
    cin >> choice;
    if(choice == 't' )
    {
        endingDate = AuxiliaryFunctions::getCurrentDate();
    }
    else
    {
        do
        {
            cout << "Podaj date konca okresu w formacie rrrr-mm-dd: ";
            cin >> date;
        }
        while(! AuxiliaryFunctions::isDateCorrect(date));
        endingDate = AuxiliaryFunctions::getFullDateFromString(date);
    }


    tmpIncomes = sortIncomesFromLower(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while((unsigned)i < tmpIncomes.size() && tmpIncomes[i].getDate() >= beginningDate)
    {
        if(tmpIncomes[i].getDate() <= endingDate)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpIncomes[i].getDate()) << "\t";
            cout << tmpIncomes[i].getItem() << "\t";
            cout << tmpIncomes[i].getAmount() << endl;
            incomesSum +=tmpIncomes[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma przychodow z wybranego zakresu czasu: " << incomesSum << endl;
    cout << endl << endl;

    i=0;
    tmpExpenses = sortExpensesFromLower(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while((unsigned)i < tmpExpenses.size() && tmpExpenses[i].getDate() >= beginningDate)
    {
        if(tmpExpenses[i].getDate() <= endingDate)
        {
            cout << AuxiliaryFunctions::getFullDateAsStringWithDashes(tmpExpenses[i].getDate()) << "\t";
            cout << tmpExpenses[i].getItem() << "\t";
            cout << tmpExpenses[i].getAmount() << endl;
            expensesSum += tmpExpenses[i].getAmount();
        }
        i++;
    }
    cout << endl << "Suma wydatkow z wybranego zakresu czasu: " << expensesSum << endl;
    cout << endl << endl;

    cout << "Roznica przychodow i wydatkow: " << incomesSum + expensesSum << endl;

    system("pause");
}

vector <Income> IncomesAndExpansesManager::sortIncomesFromLower(vector <Income> tmpIncomes)
{

    tmpIncomes = incomes;
    sort(tmpIncomes.begin(), tmpIncomes.end());
    return tmpIncomes;
}


vector <Expense> IncomesAndExpansesManager::sortExpensesFromLower(vector <Expense> tmpExpenses)
{

    tmpExpenses = expenses;
    sort(tmpExpenses.begin(), tmpExpenses.end());
    return tmpExpenses;
}
