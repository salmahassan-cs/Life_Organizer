#pragma once
#include<iostream>
#include "Budget.h"
#include "TaskManager.h"
using namespace std;


class User
{
private:
    inline static int counter;
    int id;
    string userName;
    string email;
    string password;
    bool loggedIn;
    Budget budget;
    TaskManager taskManager; 

     

    bool validateEmail(string email)
    {
        bool isvalid = false;
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                isvalid = true;
                break;
            }

        }
        if (isvalid)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:



    User()
    {
        id = ++counter;
        loggedIn = false;
    }

    User(string userName, string email, string  password)
    {
        id = ++counter;
        this->userName = userName;

        if (validateEmail(email))
            this->email = email;
        else
        {
          cout << "Invalid E-mail\n";
          return;
        }
            


        this->password = password;
        loggedIn = false;
    }
     

     

    void logout()
    {
        loggedIn = false;
        cout << "Logged out successfully\n";
    }

    bool  isLoggedIn()
    {
        return loggedIn;
    }

    int getId()
    {
        return id;
    }

    string  getUserName()
    {
        return userName;
    }

    string  getEmail()
    {
        return email;
    }

    void  updateProfile(string userName, string email, string password)
    {
        this->userName = userName;

        if (validateEmail(email))
            this->email = email;
        else
            cout << "Invalid email format\n";

        this->password =  password ;
    }

    void  displayProfile()
    {
        cout << "===== User Profile =====\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << userName << endl;
        cout << "Email: " << email << endl;
        cout << "Status: " << (loggedIn ? "Logged In" : "Logged Out") << endl;
        cout << "========================\n";
    }

    Budget& getBudget()
    {
        return budget;
    }

    TaskManager& getTaskManager()
    {
        return taskManager;
    }

    string getPassword()
    {
       return password ;
    }




};
