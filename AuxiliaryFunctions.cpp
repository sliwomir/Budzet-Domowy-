#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::intToString(int number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

string AuxiliaryFunctions::doubleToString(double number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

string AuxiliaryFunctions::ReplaceFirstLetterWithLargeLetterOthersWithSmalLetter(string tekst)
{
	if (!tekst.empty())
	{
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
		tekst[0] = toupper(tekst[0]);
	}
	return tekst;
}

int AuxiliaryFunctions::convertingStringToInt(string liczba)
{
	int liczbaInt;
	istringstream iss(liczba);
	iss >> liczbaInt;

	return liczbaInt;
}

double AuxiliaryFunctions::convertingStringToDouble(string liczba)
{
	double liczbaDouble;
	istringstream iss(liczba);
	iss >> liczbaDouble;

	return liczbaDouble;
}

bool AuxiliaryFunctions::isNumber(string number){
    for(unsigned int i=0; i<number.length(); i++){
        if(!(number[i] >=48 && number[i] <=57) && number[i] != '.'){
            return false;
        }
    }
    return true;
}

int AuxiliaryFunctions::loadInteger()
{
	string wejscie = "";
	int liczba = 0;

	while (true)
	{
		getline(cin, wejscie);

		stringstream myStream(wejscie);
		if (myStream >> liczba)
			break;
		cout << "To nie jest liczba. Wpisz ponownie. " << endl;
	}
	return liczba;
}

char AuxiliaryFunctions::loadMark()
{
	string wejscie = "";
	char znak = { 0 };

	while (true)
	{
	    cin.clear();
        cin.sync();
		getline(cin, wejscie);

		if (wejscie.length() == 1)
		{
			znak = wejscie[0];
			break;
		}
		cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
	}
	return znak;
}

string AuxiliaryFunctions::loadLine()
{
	string wejscie = "";
	getline(cin, wejscie);
	return wejscie;
}

string AuxiliaryFunctions::changeCommaToDot(string number){
    for(unsigned int i =0; i<number.length();i++){
        if(number[i] == ','){
            number[i] = '.';
            break;
        }
    }
    return number;
}

string AuxiliaryFunctions::getFullDateAsStringWithDashes(int date){
    string dateAsString = AuxiliaryFunctions::intToString(date);
    dateAsString.insert(4,"-");
    dateAsString.insert(7,"-");
    return dateAsString;
}

int AuxiliaryFunctions::getFullDateFromString(string date){
    date.erase(4,1);
    date.erase(6,1);
    return AuxiliaryFunctions::convertingStringToInt(date);
}

int AuxiliaryFunctions::getCurrentDate()
{
    int currentYear = getCurrentYear();
    int currentMonth = getCurrentMonth();
    int currentDay = getCurrentDay();
    int currentDate = (currentYear *10000) + (currentMonth *100) + currentDay;
    return currentDate;
}

int AuxiliaryFunctions::getCurrentDay()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return time->tm_mday;
}

int AuxiliaryFunctions::getCurrentMonth()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1 + time->tm_mon);
}

int AuxiliaryFunctions::getCurrentYear()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1900 + time->tm_year);
}

bool AuxiliaryFunctions::isDateCorrect(string date)
{
    int day, month, year;

    year = getYearFromString(date);
    month = getMonthFromString(date);
    day = getDayFromString(date);

    if(isDayCorrect(day,month,year) && isMonthCorrect(month) && isYearCorrect(year) && !isDateGreaterThanCurrentDate(date) && date.length()==10)
    {
        return true;
    }
    else
    {
        cout << "Zla data" << endl;
        return false;
    }
}

int AuxiliaryFunctions::getDayFromString(string date)
{
    string day;
    if(date[8]!='0')
    {
        day+=date[8];
        day+=date[9];
    }
    else
        day=date[9];
    return AuxiliaryFunctions::convertingStringToInt(day);
}

int AuxiliaryFunctions::getMonthFromString(string date)
{
    string month;

    if(date[5]!='0')
    {
        month+=date[5];
        month+=date[6];
    }
    else
        month=date[6];
    return AuxiliaryFunctions::convertingStringToInt(month);
}

int AuxiliaryFunctions::getYearFromString(string date)
{
    string year;
    for(int i=0; i<4; i++)
    {
        year+=date[i];
    }
    return AuxiliaryFunctions::convertingStringToInt(year);
}

bool AuxiliaryFunctions::isDateGreaterThanCurrentDate(string date)
{


    if(AuxiliaryFunctions::getFullDateFromString(date) > getCurrentDate())
    {
        cout << "Data wieksza od obecnej" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool AuxiliaryFunctions::isDayCorrect(int day, int month, int year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if(day>=1&&day<=31) return true;
        break;
    }
    case 2:
    {
        if(((year%4==0)&&(year%100!=0))||(year%100==0))
        {
            if(day>=1&&day<=29) return true;
        }
        else
        {
            if(day>=1&&day<=28) return true;
        }
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if(day>=1&&day<=30) return true;
        break;
    }
    }
    return false;
}

bool AuxiliaryFunctions::isMonthCorrect(int month)
{
    if(month>=1&&month<=12)
        return true;
    else
        return false;
}

bool AuxiliaryFunctions::isYearCorrect(int year)
{
    if(year>2000)
        return true;
    else
        return false;
}
