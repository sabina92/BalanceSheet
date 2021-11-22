#include "XMLFileWithUsers.h"


void XMLFileWithUsers::saveUserToXMLFile(User user,int lastUserId)
{
        CMarkup xmlFileUser;
  bool fileExists = xmlFileUser.Load( "users.xml" );

    if (!fileExists)
    {
        xmlFileUser.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileUser.AddElem("Users");
    }

    xmlFileUser.FindElem();
    xmlFileUser.IntoElem();

    while (xmlFileUser.FindElem("User"))
    {
        xmlFileUser.IntoElem();
        xmlFileUser.FindElem("UserId");
        MCD_STR strrId = xmlFileUser.GetData();
        if (atoi(MCD_2PCSZ(strrId)) == lastUserId)
        {
            xmlFileUser.OutOfElem();
            break;
        }
            xmlFileUser.OutOfElem();
    }
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
    xmlFileUser.ResetPos();

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
    return users;
}

void XMLFileWithUsers::changeUserPassword(User user)
{
     CMarkup xmlFileUser;
  bool fileExists = xmlFileUser.Load("users.xml" );

    if (!fileExists)
    {
        xmlFileUser.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileUser.AddElem("Users");
    }

    xmlFileUser.FindElem();
    xmlFileUser.IntoElem();
    while ( xmlFileUser.FindElem("User") )
    {
        xmlFileUser.IntoElem();
        xmlFileUser.FindElem("UserId");
        MCD_STR strrId = xmlFileUser.GetData();
        if (atoi(MCD_2PCSZ(strrId)) == user.getId())
        {
            xmlFileUser.FindElem("Password");
            xmlFileUser.RemoveElem();
            xmlFileUser.AddElem("Password", user.getPassword());
            xmlFileUser.Save("users.xml");
            break;
        }
            xmlFileUser.OutOfElem();
    }
}

void XMLFileWithUsers::saveAllUsersToXMLFile(vector <User> users)
{
    CMarkup xmlFileUser;
  bool fileExists = xmlFileUser.Load("users.xml" );

    if (!fileExists)
    {
        xmlFileUser.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileUser.AddElem("Users");
    }

    xmlFileUser.FindElem();
    xmlFileUser.IntoElem();

    for (int i=0; i < users.size(); i++)
    {
        xmlFileUser.AddElem("User");
        xmlFileUser.IntoElem();
        xmlFileUser.AddElem("UserId", to_string(users[i].getId()));
        xmlFileUser.AddElem("Login", users[i].getLogin());
        xmlFileUser.AddElem("Password", users[i].getPassword());
        xmlFileUser.AddElem("Name", users[i].getName());
        xmlFileUser.AddElem("Surname", users[i].getSurname());
        xmlFileUser.OutOfElem();
    }


    xmlFileUser.Save("users.xml");
}
