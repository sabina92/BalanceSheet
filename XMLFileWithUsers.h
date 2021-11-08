#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include "XMLFile.h"
#include <string>
#include "User.h"
#include <vector>
#include "Markup.h"
#include "AccessoryMethods.h"

using namespace std;

class XMLFileWithUsers
{
const string NAME_OF_XML_FILE_WITH_USERS;

public:
    XMLFileWithUsers(string nameOfFile) : NAME_OF_XML_FILE_WITH_USERS(nameOfFile) {
    }

    void saveUserToXMLFile(User user, int lastUserId);
    vector <User> loadUsers();

    bool doesFileExist();
    string downloadNameOfFile();

    void saveAllUsersToXMLFile(vector <User> users);




};

#endif
