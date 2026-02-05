// TO_DO_LIST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string> 
#include "User.h" 
#include "Budget.h" 
#include "TaskManager.h"
#include"UserFileManager.h"
#include"UserManager.h"
 

using namespace std;
void runApp() {

    UserManager userManager;
    User* loggedUser = nullptr;  

    bool exitApp = false;
    while (!exitApp) {

        cout << "===== Welcome to Life Organizer =====\n";
        cout << "1->Register\n2->Login\n3->Logout\n4->Budget Menu\n5->Task Menu\n6->Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {

        case 1:
        {
            string name, email, password;
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter password: ";
            getline(cin, password);

            userManager.registerUser(name, email, password);

            break;
        }

        case 2:
        {
            if (loggedUser && loggedUser->isLoggedIn()) {
                cout << "You are already logged in.\n";
                break;
            }

            string email, password;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;

            if (userManager.login(email, password)) {
                loggedUser = userManager.getLoggedUser();
                cout << "Login successful\n";
            }
            else {
                cout << "Invalid email or password\n";
            }

            break;
        }

        case 3:
        {
            if (!loggedUser || !loggedUser->isLoggedIn()) {
                cout << "You are not logged in.\n";
                break;
            }

            userManager.logout();
            loggedUser = nullptr;
            break;
        }

        case 4:
        {
            loggedUser = userManager.getLoggedUser();
            if (!loggedUser  ) {
                cout << "Please login first.\n";
                break;
            }

            bool Budget = false;
            while (!Budget) {
                cout << "===== Budget Menu =====\n";
                cout << "1. Add Income\n2. Delete Income\n3. Update Income\n4. View All Incomes\n";
                cout << "5. Add Expense\n6. Delete Expense\n7. Update Expense\n8. View All Expenses\n";
                cout << "9. View Balance\n10. Daily Report\n11. Weekly Report\n12. Monthly Report\n13. Summary Report\n";
                cout << "0. Back\n";
                cout << "Choose an option: ";

                int Choice2;
                cin >> Choice2;

                switch (Choice2) {
                case 1:
                {
                    double amount;
                    string source;
                    cout << "Enter amount: ";
                    cin >> amount;
                    cout << "Enter source: ";
                    cin.ignore();
                    getline(cin, source);
                    Date d;
                    cout << "Enter day month year: ";
                    cin >> d.day >> d.month >> d.year;

                    Income income(amount, source, d);
                    loggedUser->getBudget().addIncome(income);
                    cout << "Income added successfully.\n";
                    break;
                }
                case 2:
                {
                    int id;
                    cout << "Enter Income ID to delete: ";
                    cin >> id;
                    loggedUser->getBudget().deleteIncome(id);
                    break;
                }
                case 3:
                {
                    int id;
                    double amount;
                    string source;
                    cout << "Enter Income ID to update: ";
                    cin >> id;
                    cout << "Enter new amount: ";
                    cin >> amount;
                    cout << "Enter new source: ";
                    cin.ignore();
                    getline(cin, source);
                    loggedUser->getBudget().updateIncome(amount, source, id);
                    break;
                }
                case 4:
                    loggedUser->getBudget().displayIncome();
                    break;
                case 5:
                {
                    double amount;
                    string category;
                    cout << "Enter amount: ";
                    cin >> amount;
                    cout << "Enter category: ";
                    cin.ignore();
                    getline(cin, category);
                    Date d;
                    cout << "Enter day month year: ";
                    cin >> d.day >> d.month >> d.year;
                    Expense expense(amount, category, d);
                    loggedUser->getBudget().addExpense(expense);
                    cout << "Expense added successfully.\n";
                    break;
                }
                case 6:
                {
                    int id;
                    cout << "Enter Expense ID to delete: ";
                    cin >> id;
                    loggedUser->getBudget().deleteExpense(id);
                    break;
                }
                case 7:
                {
                    int id;
                    double amount;
                    string category;
                    cout << "Enter Expense ID to update: ";
                    cin >> id;
                    cout << "Enter new amount: ";
                    cin >> amount;
                    cout << "Enter new category: ";
                    cin.ignore();
                    getline(cin, category);
                    loggedUser->getBudget().updateExpense(amount, category, id);
                    break;
                }
                case 8:
                    loggedUser->getBudget().displayExpenses();
                    break;
                case 9:
                {
                    double balance = loggedUser->getBudget().calculateBalance();
                    cout << "Your Balance: " << balance << endl;
                    break;
                }
                case 10:
                {
                    Date d;
                    cout << "Enter day month year: ";
                    cin >> d.day >> d.month >> d.year;
                    loggedUser->getBudget().dailyReport(d);
                    break;
                }
                case 11:
                {
                    Date d;
                    cout << "Enter start day month year: ";
                    cin >> d.day >> d.month >> d.year;
                    loggedUser->getBudget().weeklyReport(d);
                    break;
                }
                case 12:
                {
                    int month, year;
                    cout << "Enter month and year: ";
                    cin >> month >> year;
                    loggedUser->getBudget().monthlyReport(month, year);
                    break;
                }
                case 13:
                    loggedUser->getBudget().summaryReport();
                    break;
                case 0:
                    Budget = true;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
                }
            }
            break;
        }

        case 5:
        {
            loggedUser = userManager.getLoggedUser();
            if (!loggedUser) {
                cout << "Please login first.\n";
                break;
            }
            bool taskMenu = false;
            while (!taskMenu) {
                cout << "===== Task Menu =====\n";
                cout << "1. Add Task List\n2. Delete Task List\n3. Add Task\n4. Delete Task\n5. Update Task Title\n 6. View Tasks In spacific list \n7. View All Tasks\n0. Back\n";
                cout << "Choose an option: ";

                int Choice3;
                cin >> Choice3;

                switch (Choice3) {
                case 1:
                {
                    string listName;
                    cout << "Enter Task List Name: ";
                    cin.ignore();
                    getline(cin, listName);
                    TaskList tlist(listName);
                    loggedUser->getTaskManager().addTaskList(tlist);
                    cout << "Task List added successfully.\n";
                    break;
                }
                case 2:
                {
                    string listName;
                    cout << "Enter Task List Name to delete: ";
                    cin.ignore();
                    getline(cin, listName);
                    loggedUser->getTaskManager().deleteTaskList(listName);
                    break;
                }
                case 3:
                {
                    string title, category,list;
                    int priority;
                     
                    cout << "Enter Task title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Task category: ";
                    getline(cin, category);
                    cout << "Enter Task priority (1-3): ";
                    cin >> priority;
                    Date start, end;
                    cout << "Enter(start date) day month year: ";
                    cin >> start.day >> start.month >> start.year;
                    cout << "Enter(end date) day month year: ";
                    cin >> end.day >> end.month >> end.year;
                    Task task(title, "", start, end, priority, category);
                    loggedUser->getTaskManager().addTask(task);
                    cout << "Task added successfully.\n";
                    break;
                }
                case 4:
                {
                    int id;
                    cout << "Enter Task ID to delete: ";
                    cin >> id;
                    TaskList* task = loggedUser->getTaskManager().getListThatHasTask(id);
                    if (task) {
                        task->deleteTask(id);
                        cout << "Deleted task.\n";
                    }
                    else {
                        cout << "Task not found.\n";
                    }
                    break;
                }
                case 5:
                {
                    int id;
                    string newTitle;
                    cout << "Enter Task ID to update: ";
                    cin >> id;
                    cout << "Enter new title: ";
                    cin.ignore();
                    getline(cin, newTitle);
                    Task* task = loggedUser->getTaskManager().searchTaskinAllLists(id);
                    if (task) {
                        task->setTitle(newTitle);
                        cout << "Task updated.\n";
                    }
                    else {
                        cout << "Task not found.\n";
                    }
                    break;
                }
                case 6:
                {
                    string listName;
                    cout << "Enter List Name: ";
                    cin.ignore();
                    getline(cin, listName);

                    TaskList* list = userManager.getLoggedUser()->getTaskManager().searchList(listName);



                    if (list != nullptr)
                    {
                        list->displayListOfTasks();
                    }
                    else
                    {
                        cout << "List not found\n";
                    }
                    break;
                }
                case 7:
                    userManager.getLoggedUser()->getTaskManager().displayAllLists();
                    break;
                case 0:
                    taskMenu = true;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
                }
            }
            break;
        }

        case 6:
            exitApp = true;
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

int main() {

    runApp();

    return 0;

}