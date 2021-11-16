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
    void saveAllUsersToXMLFile(vector <User> users);
    void changeUserPassword(User user);

};

#endif
