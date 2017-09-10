//
// Created by user on 08/09/17.
//

#include <iostream>
#include <fstream>
#include <crypt.h>
#include "AuthService.h"

AuthService::AuthService(const string &usersFolder) : usersFolder(usersFolder) {}

bool AuthService::canLogIn(string userName, string password) {
    ifstream read(usersFolder + '/' + userName + ".txt");
    getline(read, dbUserName);
    getline(read, dbPassword);

    return isValidUser(userName, password);
}


bool AuthService::isValidUser(string userName, string password) {
    string unHashedPassword = unHashPassword(dbPassword);

    if (userName == dbUserName && password == unHashedPassword)
        return true;

    return false;
}


bool AuthService::registerUser(string username, string password) {

    bool userAlreadyExists = CheckIfUserExists(username);

    if (userAlreadyExists)
      return false;

    string hashedPassword = hashPassword(password);

    ofstream file;
    file.open(usersFolder + "/" + username + ".txt");
    file << username << endl << hashedPassword;
    file.close();

    return true;
}

bool AuthService::CheckIfUserExists(string username) {

    if (ifstream(usersFolder + "/" + username + ".txt"))
        return true;

    return false;
}

string AuthService::hashPassword(string password) {

    string hashedPassword = "";

    // ROT - 13 encryption
    for (int i=0 ; i< password.size(); i++)
        hashedPassword+= password[i] + 13;

    return hashedPassword;
}

string AuthService::unHashPassword(string hashedPassword) {
    string originalPassword = "";

    // ROT - 13 decryption
    for (int i=0 ; i< hashedPassword.size(); i++)
        originalPassword+= hashedPassword[i] - 13;

    return originalPassword;
}




