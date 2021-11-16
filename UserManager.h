#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "XMLFileWithUsers.h"
#include "AccessoryMethods.h"
#include "User.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    XMLFileWithUsers xmlFileWithUsers;
    int lastUserId;

    User giveDataOfNewUser();
    int downloadNewUserId();
    bool showIfTheLoginExists(string login);
    void saveAllUsersToFile();

public:
    UserManager(string nameOfFileWithUsers) : xmlFileWithUsers (nameOfFileWithUsers) {
    loggedInUserId = 0;
    users = xmlFileWithUsers.loadUsers();
    };
    void userRegister();
    void changeLoggedInUserPassword();
    int logInUser();
    void logOutUser();
    int downloadTheLoggedInUserId();


};

#endif
