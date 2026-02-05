#pragma once
#include<iostream>
#include<vector>
#include"Task.h"

using namespace std;

class TaskList
{
private:
	string ListName;
	vector<Task> tasks;

public:
	TaskList()
	{
		this->ListName = "";
	}
	TaskList(string ListName)
	{
		this->ListName = ListName;
	}
	void  setListName(string ListName)
	{
		this->ListName = ListName;
	}
	string  getListName()
	{
		return ListName;
	}
	bool  addTask(Task& newTask)
	{
		for (Task& task : tasks)
		{
			if (task.getTitle() == newTask.getTitle())
			{
				cout << "Task with this Title Already Exists \n";
				return false;
			}
		}
		tasks.push_back(newTask);

		return true;

	}
	bool  deleteTask(int id)
	{
		for (auto it = tasks.begin(); it != tasks.end(); it++)
		{
			if (it->getId() == id)
			{
				tasks.erase(it);
				return true;
			}
		}
		cout << "sorry!this task is not found \n";
		return false;
	}
	void  updateTaskTitle(int id, string newTitle)
	{
		if (search(id) == nullptr)
		{
			cout << "sorry!this task is not found \n";
			return;
		}
		Task* task = search(id);
		task->setTitle(newTitle);

	}
	void  updateTaskPriority(int id, int newPriority)
	{
		if (search(id) == nullptr)
		{
			cout << "sorry!this task is not found \n";
			return;
		}
		Task* task = search(id);
		task->setPriority(newPriority);
	}
	void  updateTaskStartDate(int id, Date newStartDate)
	{
		if (search(id) == nullptr)
		{
			cout << "sorry!this task is not found \n";
			return;
		}
		Task* task = search(id);
		task->setStartDate(newStartDate);
	}
	void  updateTaskEndDate(int id, Date newEndDate)
	{
		Task* task = search(id);
		if (task == nullptr)
		{
			cout << "sorry!this task is not found \n";
			return;
		}
		task->setEndDate(newEndDate);
	}
	Task* search(int id)
	{
		for (auto it = tasks.begin(); it != tasks.end(); it++)
		{
			if (it->getId() == id)
			{
				return &(*it);
			}
		}
		return nullptr;
	}
	void  displayListOfTasks( )
	{
		for (auto it = tasks.begin(); it != tasks.end(); it++)
		{
			it->displayTask();
		}
	}




};
 

