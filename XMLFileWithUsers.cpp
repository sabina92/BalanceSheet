#include "XMLFileWithUsers.h"


string XMLFileWithUsers::downloadNameOfFile()
    {
        return NAME_OF_XML_FILE_WITH_USERS;
    }

bool XMLFileWithUsers::doesFileExist()
    {
        string nameOfFile = downloadNameOfFile().c_str();
        CMarkup xmlFile;
        bool isXMLFileExists = xmlFile.Load(nameOfFile);

        cout << endl <<isXMLFileExists ;
        return isXMLFileExists;
    }

 void XMLFileWithUsers::saveUserToXMLFIle(User user)
 {
    CMarkup xmlFileUser;
    bool bSuccess = true;
    bSuccess = doesFileExist();

     if (!bSuccess)
     {
        xmlFileUser.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileUser.AddElem("Users");
     }

    xmlFileUser.FindElem();
    xmlFileUser.IntoElem();
    xmlFileUser.AddElem("User");
    xmlFileUser.IntoElem();
    xmlFileUser.AddElem("UserId", to_string(user.getId()));
    xmlFileUser.AddElem("Login", user.getLogin());
    xmlFileUser.AddElem("Password", user.getPassword());
    xmlFileUser.AddElem("Name", user.getName());
    xmlFileUser.AddElem("Surname", user.getSurname());

    xmlFileUser.Save("users.xml");
 }

 vector <User> XMLFileWithUsers::loadUsers()
 {
    CMarkup xmlFileUser;
    xmlFileUser.Load( NAME_OF_XML_FILE_WITH_USERS );
    User user;
    vector <User> users;
    //xmlFileUser.ResetPos();

    xmlFileUser.FindElem();
    xmlFileUser.IntoElem();

    while ( xmlFileUser.FindElem("User") )
    {
        xmlFileUser.IntoElem();
        xmlFileUser.FindElem("UserId");
        MCD_STR strId = xmlFileUser.GetData();
        user.setId(atoi(MCD_2PCSZ(strId)));
        xmlFileUser.FindElem("Login");
        MCD_STR strLogin = xmlFileUser.GetData();
        user.setLogin(strLogin);
        xmlFileUser.FindElem("Password");
        MCD_STR strPassword = xmlFileUser.GetData();
        user.setPassword(strPassword);
        xmlFileUser.FindElem("Name");
        MCD_STR strName = xmlFileUser.GetData();
        user.setName(strName);
        xmlFileUser.FindElem("Surname");
        MCD_STR strSurname= xmlFileUser.GetData();
        user.setSurname(strSurname);
        xmlFileUser.OutOfElem();

        users.push_back(user);
    }
//    for (int i=0; i < users.size(); i++)
//    {
//        cout << users[i].getLogin() << endl << users[i].getName()<< endl;
//    }

    return users;
 }
