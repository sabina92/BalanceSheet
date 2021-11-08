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
<<<<<<< HEAD
<<<<<<< HEAD
    bool doesFileExist();
    string downloadNameOfFile();

=======
    void saveAllUsersToXMLFile(vector <User> users);
>>>>>>> temp2
=======
    bool doesFileExist();
    string downloadNameOfFile();

>>>>>>> a55cd894a81039f45a61ebbb4b42fa5e00b1df13


};

#endif
