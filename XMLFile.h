#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile
{
const string NAME_OF_FILE;

public:

    XMLFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
    }

    string downloadNameOfFile();
    bool doesFileExist();
    void deleteFile(string nameofFileWithExtension);
    void changeNameOfFile(string oldName, string newName);



};

#endif
