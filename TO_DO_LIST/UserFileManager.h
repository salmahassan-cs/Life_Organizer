 
#pragma once
#include <vector>
#include <fstream>
#include "User.h"
#include <string>
class UserFileManager
{
private:
    string fileName;


    bool canWriteFile(const string& filename) {
        ofstream test(filename, ios::app);
        if (!test.is_open()) {
            return false;
        }
        test.close();
        return true;
    }

    vector<string> split(  string  line, char delimiter)
    {
        vector<string> result;
        string current = "";

        for (char c : line)
        {
            if (c == delimiter)
            {
                if (!current.empty())
                {
                    result.push_back(current);
                    current = "";
                }
            }
            else
            {
                current += c;
            }
        }

        if (!current.empty())
            result.push_back(current);

        return result;
    }
public:
    UserFileManager(string fileName = "users.txt")
    {
        this->fileName = fileName;
    }


    void saveUsers(vector<User>& users)
    {
        ofstream file("users.txt");

        if (!file.is_open())
        {
            cout << "Error opening file for writing\n";
            return;
        }

        for (User& u : users)
        {
            file << u.getUserName() << " " << u.getEmail() << " " << u.getPassword() << endl;

        }

        file.close();
    }

    vector<User> loadUsers()
    {
        vector<User> users;
        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "File not found, creating new file...\n";
            ofstream createFile(fileName);
            createFile.close();
            return users;
        }

        string line;
        while (getline(file, line)) {
            vector<string> parts = split(line, ' ');
            if (parts.size() == 3) {
                string username = parts[0];
                string email = parts[1];
                string password = parts[2];

                User u(username, email, password);
                users.push_back(u);
            }
        }

        file.close();
        return users;
    }


    void addUserToFile(User u) {
        if (!canWriteFile(fileName)) {
            cout << "Cannot write to file! Make sure it is closed in other programs.\n";
            return;
        }

        ofstream file(fileName, ios::app);
        file << u.getUserName() << " " << u.getEmail() << " " << u.getPassword() << endl;
        file.close();
    }
};
