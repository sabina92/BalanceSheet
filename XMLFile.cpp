#include "XMLFile.h"
#include "Markup.h"

bool XMLFile::doesFileExist()
    {
        string nameOfFile = downloadNameOfFile().c_str();
        CMarkup xmlFile;
        bool isXMLFileExists = xmlFile.Load(nameOfFile);

        cout << endl <<isXMLFileExists ;
        return isXMLFileExists;
    }

string XMLFile::downloadNameOfFile()
    {
        return NAME_OF_FILE;
    }
