#ifndef  AUXILIARYFUNCTIONS_H
#define  AUXILIARYFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

class AuxiliaryFunctions
{
public:
    static string intToString(int number);
    static string doubleToString(double number);
    static int convertingStringToInt(string liczba);
    static double convertingStringToDouble(string liczba);

    static bool isNumber(string number);
    static int loadInteger();
    static char loadMark();
    static string loadLine();

    static string ReplaceFirstLetterWithLargeLetterOthersWithSmalLetter(string tekst);//
    static string changeCommaToDot(string number);
    static string getFullDateAsStringWithDashes(int date);
    static int getFullDateFromString(string date);

    static int getCurrentDate();
    static int getCurrentDay();
    static int getCurrentMonth();
    static int getCurrentYear();

    static int getDayFromString(string date);
    static int getMonthFromString(string date);
    static int getYearFromString(string date);


    static bool isDateCorrect(string date);
    static bool isDateGreaterThanCurrentDate(string date);
    static bool isDayCorrect(int day, int month, int year);
    static bool isMonthCorrect(int month);
    static bool isYearCorrect(int year);


};

#endif
