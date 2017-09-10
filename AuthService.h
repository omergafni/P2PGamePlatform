//
// Created by user on 08/09/17.
//

#ifndef BOOLPGIA_AUTHSERVICE_H
#define BOOLPGIA_AUTHSERVICE_H

#include <string>

using namespace std;

class AuthService {

public:
    AuthService(const string &usersFolder);
    bool canLogIn(string userName, string password);
    bool registerUser(string username, string password);

protected:

    string dbUserName, dbPassword;
    string usersFolder;
    string unHashPassword(string hashedPassword);
    string hashPassword(string password);

    bool isValidUser(string userName, string password);
    bool CheckIfUserExists(string user);
};


#endif //BOOLPGIA_AUTHSERVICE_H
