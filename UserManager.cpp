#include "UserManager.h"

void UserManager::userRegister()
{
    User user = giveDataOfNewUser();

    users.push_back(user);
    int lastUserId = user.getId()-1;
    xmlFileWithUsers.saveUserToXMLFile(user, lastUserId);

    cout << endl << "The account was established successfully" << endl << endl;
    system("pause");
}

User UserManager::giveDataOfNewUser()
{
    User user;

    user.setId(downloadNewUserId());

    string login;
    do
    {
        cout << "Give the login: ";
        cin >>login;
        user.setLogin(login);
    } while (showIfTheLoginExists(user.getLogin()) == true);

    string password;
    cout << "Give the password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Give the name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Give the surname: ";
    cin >> surname;
    user.setSurname(surname);
    return user;
}

int UserManager::downloadNewUserId()
{
    return (users.empty() == true) ? 1 : (users.back().getId() + 1);
}

bool UserManager::showIfTheLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is an user with this login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::changeLoggedInUserPassword()
{
    AccessoryMethods accessoryMethods;
    string newPassword="" ;

     for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            cout << "Give the new password: ";
            newPassword = accessoryMethods.loadLine();
            users[i].setPassword(newPassword);
            cout << "The password was changed." << endl << endl;
            xmlFileWithUsers.changeUserPassword(users[i]);
            system("pause");
        }
    }
}

int UserManager::logInUser()
{
    User user;
    string login = "", password = "";
    AccessoryMethods accessoryMethods;

    cout << endl << "Give your login : ";
    login = accessoryMethods.loadLine();
    int i = 0;

    while (i != users.size())
    {
        if (users[i].getLogin() == login)
        {
            for (int chanceAmount = 3; chanceAmount > 0; chanceAmount--)
            {
                cout << "Give the password. There are " << chanceAmount << " chances. ";
                password = accessoryMethods.loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getId();
                    return loggedInUserId;
                }
            }
            cout << "You entered the wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
        i++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::logOutUser()
{
    loggedInUserId = 0;
}

int UserManager::downloadTheLoggedInUserId()
{
    return loggedInUserId;
}
