#include "UserManager.h"

void UserManager::registerUser()
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
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
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
            system("pause");
        }
    }

    xmlFileWithUsers.saveAllUsersToXMLFile(users);
}

//int UzytkownikMenedzer::logowanieUzytkownika()
//{
//    Uzytkownik uzytkownik;
//    string login = "", haslo = "";
//    MetodyPomocnicze metodyPomocnicze;
//
//    cout << endl << "Podaj login: ";
//    login = metodyPomocnicze.wczytajLinie();
//    int i = 0;
//
//    while (i != uzytkownicy.size())
//    {
//        if (uzytkownicy[i].pobierzLogin() == login)
//        {
//            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
//            {
//                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
//                haslo = metodyPomocnicze.wczytajLinie();
//
//                if (uzytkownicy[i].pobierzHaslo() == haslo)
//                {
//                    cout << endl << "Zalogowales sie." << endl << endl;
//                    system("pause");
//                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
//                    return idZalogowanegoUzytkownika;
//                }
//            }
//            cout << "Wprowadzono 3 razy bledne haslo." << endl;
//            system("pause");
//            return 0;
//        }
//        i++;
//    }
//    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
//    system("pause");
//    return 0;
//}
//
//void UzytkownikMenedzer::wylogujUzytkownika()
//{
//    idZalogowanegoUzytkownika = 0;
//}
//
//int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
//{
//    return idZalogowanegoUzytkownika;
//}
