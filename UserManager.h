#ifndef  USERMANAGER_H
#define  USERMANAGER_H

#include <iostream>
#include "User.h"
#include <vector>
#include <string>
#include "AuxiliaryFunctions.h"
#include "FileWithUsers.h"


using namespace std;

class UserManager
{
    vector <User> users;
    int loggedUserId;
    FileWithUsers usersFile;

    User setNewUser();
    int getNewUserId();
    bool doesExistUser(string login);

public:
    UserManager(string fileName):usersFile(fileName)
    {
        loggedUserId = 0;
        users = usersFile.loadData();
    }

    void userRegistration();
    void userLoging();
    void changePassword();

    void setLoggedUserId(int Id);
    int getLoggedUserId();
    void showRegistredUsers();
    bool isUserLogged();


};
#endif
