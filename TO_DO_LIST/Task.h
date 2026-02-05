#pragma once
  
#include <string>
using namespace std;
#include<iostream>
#include"Date.h"
enum class Status
{
	Pending, InProgress, Done

};


class Task
{

private:
	inline static int counter;
	int id;
	string title;
	string description;
	int priority;
	Date startDate;
	Date endDate;
	Status status;
	string TaskCat;
public:
	Task(string title, string discription, Date startDate, Date endDate, int priority, string TaskCat )
	{
		id = ++counter;//start by 1
		this->title = title;
		this->description = discription;
		setStartDate(startDate); 
		setEndDate(endDate)  ;
		this->status = Status::Pending;
		setPriority(priority);
		this->TaskCat = TaskCat  ;
		if (!setPriority(priority))
		{
			throw runtime_error("Invalid priority");
		}
		if (!setEndDate(endDate) || !setStartDate(startDate))
		{
			throw runtime_error("Invalid Date");
		}

	}
	int  getId()
	{
		return id;
	}
	string  getTitle()
	{
		return title;
	}
	string  getStatus()
	{
		switch (status) {
		case Status::Pending:
			return "Pending";
		case Status::Done:
			return "Done";
		case Status::InProgress:
			return "In Progress";
		}
		return "Unknown";
	}
	int  getPriority()
	{
		return priority;
	}
	void  setTitle(string title)
	{
		if (title.empty())
		{
			cout << "Title cannot be empty \n";
			return;
		}
		this->title = title;
	}
	void  setDescription(string description)
	{
		this->description = description;
	}
	bool setPriority(int priority)
	{

		if (priority < 1 || priority>3)
		{
			cout<< "Priority must be between 1 and 3\n"    ;
			return false;
		}
		this->priority = priority;
		return true;
	}
	bool  setStartDate(Date startDate)
	{
		if (startDate.month == 2 && startDate.day > 29) 
		{
			cout << "Invalid StartDate\n";
			return  false;

		}
		else if (startDate.day < 1 || startDate.day >31 || startDate.month > 12 || startDate.month < 1 || startDate.year < 2026)
		{
			cout << "Invalid StartDate\n";
			return  false;
		}
		this->startDate = startDate;
		return true;
	}
	bool setEndDate(Date endDate)
	{
		if (endDate.month == 2 && endDate.day > 29)
		{
			cout << "Invalid StartDate\n";
			return false;

		}
		else if (endDate.day < 1 || endDate.day >31 || endDate.month > 12 || endDate.month < 1 || endDate.year < 2026||endDate.year<startDate.year)
		{
			cout << "Invalid StartDate\n";
			return false;
		}
		this->endDate = endDate;
		return true;
	}
	void  setStatus(Status status)
	{
		this->status = status;
	}
	void  markAsDone()
	{
		status = Status::Done;
	}
	void  displayTask()
	{
		cout << "ID : " << id << endl;
		cout << "Title : " << title << endl;
		cout << "==============================\n";
		cout << "Start Date : \n";
		cout << "Day : " << startDate.day << endl;
		cout << "Month : " << startDate.month << endl;
		cout << "Year : " << startDate.year << endl;
		cout << "==============================\n";
		cout << "End Date : \n";
		cout << "Day : " << endDate.day << endl;
		cout << "Month : " << endDate.month << endl;
		cout << "Year : " << endDate.year << endl;
		cout << "==============================\n";
		cout << "Status: ";
		switch (status)
		{
		case Status::Done:
			cout << "Done\n";
			break;
		case Status::InProgress:
			cout << "inProgress\n";
			break;
		case Status::Pending:
			cout << "Pending\n";
		}
		cout << "Priority : " << priority << endl;

	}
	string  getCategory()
	{
		return TaskCat;
	}

};


