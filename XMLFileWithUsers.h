#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include "XMLFile.h"
#include <string>
#include "User.h"
#include <vector>
#include "Markup.h"

using namespace std;

class XMLFileWithUsers : public XMLFile
{
const string NAME_OF_XML_FILE_WITH_USERS;

public:
    XMLFileWithUsers(string nameOfFile) : NAME_OF_XML_FILE_WITH_USERS(nameOfFile), XMLFile(nameOfFile) {
    }

    void saveUserToXMLFIle(User user);
    vector <User> loadUsers();


};

#endif
