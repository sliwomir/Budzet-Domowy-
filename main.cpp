#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{

    Budget budget("users.xml", "incomes.xml", "expenses.xml");


    while (true)
    {
        if (budget.isUserLogged() == 0)

        {
            char choice;

            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> choice;


            switch (choice)
            {
            case '1':
                budget.userRegistration();
                break;
            case '2':
                budget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char choiceUserMenu;

            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu" << endl;
            cout << "---------------------------" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "7. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> choiceUserMenu;;

            switch (choiceUserMenu)
            {
            case '1':
                budget.addNewIncome();
                break;
            case '2':
                budget.addNewExpense();
                break;
            case '3':
                budget.showBalanceForCurretnMonth();
                break;
            case '4':
                budget.showBalanceForPreviouslyMonth();
                break;
            case '5':
                budget.showBalanceForPeriodOfTime();
                break;
            case '6':
                budget.changePassword();
                break;
            case '7':
                budget.logout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}

