#pragma once
#include <vector>
#include <iostream>
#include "User.h"
#include "UserFileManager.h"
using namespace std;

class UserManager
{
private:
    vector<User> users;
    User* loggedUser = nullptr;
    UserFileManager fileManager;
    string trim(string str)
    {
        while (!str.empty() && str.back() == ' ')
            str.pop_back();

        while (!str.empty() && str.front() == ' ')
            str.erase(str.begin());

        return str;
    }
public:
    UserManager()
    {
        users = fileManager.loadUsers();

        cout << "Loaded Users:\n";
        for (auto& u : users)
        {
            cout << u.getEmail() << " " << u.getPassword() << endl;
        }
    }

    bool registerUser(string userName, string email, string password) {
        for (User u : users) {
            if (u.getEmail() == email) {
                cout << "Email already exists\n";
                return false;
            }
        }

        User newUser(userName, email, password);
        users.push_back(newUser);
        fileManager.addUserToFile(newUser);  
        cout << "User registered successfully\n";
        return true;
    }

    bool login(string email, string password)
    {
        email = trim(email);
        password = trim(password);

        for (User& u : users)
        {
            if (u.getEmail() == email && u.getPassword() == password)
            {
                loggedUser = &u;
                cout << "Login successful!\n";
                return true;
            }
        }
        cout << "Invalid email or password!\n";
        return false;
    }

    void logout() {
        if (loggedUser != nullptr) {
            loggedUser->logout();
            loggedUser = nullptr;
        }
    }

    User* getLoggedUser() { return loggedUser; }
    vector<User>& getUsers() { return users; }
    bool isLoggedIn() { return loggedUser != nullptr; }
};