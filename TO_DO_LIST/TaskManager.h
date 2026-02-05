#pragma once
#include <iostream>
#include <unordered_map>
#include "TaskList.h"
using namespace std;

class TaskManager
{
private:
    unordered_map<string, TaskList*> categorizedList;

public:

    ~TaskManager() {
        for (auto& pair : categorizedList)
            delete pair.second;
    }

    void addTask(Task task)
    {
        string category = task.getCategory();

        if (categorizedList.count(category) == 0)
        {
            categorizedList[category] = new TaskList(category);
        }

        categorizedList[category]->addTask(task);
    }

    void deleteTask(int id)
    {
        for (auto& pair : categorizedList)
        {
            if (pair.second->deleteTask(id))
            {
                cout << "Deleted task.\n";
                return;
            }
        }
        cout << "Task not found.\n";
    }

    Task* searchTaskinAllLists(int id)
    {
        for (auto& pair : categorizedList)
        {
            Task* task = pair.second->search(id);
            if (task) return task;
        }
        return nullptr;
    }

    TaskList* getListThatHasTask(int id)
    {
        for (auto& pair : categorizedList)
        {
            Task* task = pair.second->search(id);
            if (task) return pair.second;
        }
        return nullptr;
    }

    TaskList* searchList(string listName)
    {
        if (categorizedList.count(listName))
            return categorizedList[listName];
        return nullptr;
    }

    void displayAllLists()
    {
        for (auto& pair : categorizedList)
        {
            cout << "===== Task List: " << pair.first << " =====\n";
            pair.second->displayListOfTasks();
            cout << "==============================\n";
        }
    }

    void addTaskList(TaskList tlist)
    {
        string name = tlist.getListName();
        if (categorizedList.count(name) == 0)
        {
            categorizedList[name] = new TaskList(tlist);
            cout << "Task List added successfully.\n";
        }
        else
        {
            cout << "List already exists.\n";
        }
    }

    void deleteTaskList(string listName)
    {
        if (categorizedList.count(listName))
        {
            delete categorizedList[listName];
            categorizedList.erase(listName);
            cout << "Task List deleted successfully.\n";
        }
        else
        {
            cout << "List not found.\n";
        }
    }

};