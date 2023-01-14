#ifndef  FILEWITHUSERS_H
#define  FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "Markup.h"

#include "AuxiliaryFunctions.h"
#include "XmlFile.h"
#include "User.h"

using namespace std;

class FileWithUsers: public XmlFile
{

public:
    FileWithUsers(string fileName):XmlFile(fileName){}

    void saveUser(User user);
    vector <User> loadData();
    void saveLoggedUser(int id, string newPassword);

};

#endif
