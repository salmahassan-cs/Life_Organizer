#pragma once
#include <iostream>
#include "Date.h"
#include "Common.h"
using namespace std;
class Expense
{
private:
    int id;
    inline static int counter = 0;
    double amount;
    string category;
    Date date;
     string description;

    bool validateAmount(double amount) { return amount > 0; }

public:
    Expense(double amount,  string category, Date date = Date{}) {
        id = ++counter;
        if (validateAmount(amount))
            this->amount = amount;
        else
            this->amount = 0;

        this->category = category;

        if (Common::validateDate(date))
            this->date = date;
    }

    int getId() { return id; }
    double getAmount() { return amount; }
    string getCategory() { return category; }
    Date getDate() { return date; }

    void setAmount(double amount) {
        if (validateAmount(amount))
            this->amount = amount;
        else {
            this->amount = 0;
            cout << "Amount must be > 0\n";
        }
    }

    void setCategory(std::string category) { this->category = category; }
    void setDate(Date date) { this->date = date; }

    void display() {
        cout << "Amount: " << amount << "\nCategory: " << category
            << "\nDate: " << date.day << "/" << date.month << "/" << date.year
            << "\nDescription: " << description << "\n";
    }
};