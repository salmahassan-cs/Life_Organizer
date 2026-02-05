#pragma once
 #include <iostream>
#include"Common.h"
#include"Date.h"
using namespace std;

class Income
{
private:
	int id;
	inline static int counter;
	double amount;
	string source;
	Date date;
	string description;
	bool  validateAmount(double& amount)
	{
		return amount > 0;
	}
public:


	Income(double amount, string source)
	{
		id = ++counter;
		this->amount = validateAmount(amount) ? amount : 0;

		this->source = source;
	}
	int  getId()
	{
		return id;
	}
	Income(double amount, string source, Date date)
	{
		id = ++counter;
		this->amount = validateAmount(amount) ? amount : 0;

		this->source = source;
		if (Common::validateDate (date))
		{
			this->date = date;
		}

	}
	void  display()
	{
		cout << "Amount :  " << amount << endl;
		cout << "Source :  " << source << endl;
		cout << "Date : ";
		cout << date.day << "/" << date.month << "/" << date.year << endl;
		cout << "Description : " << description << endl;

	}

	void  setAmount(double amount)
	{
		if (validateAmount(amount))
		{
			this->amount = amount;
		}
		else
		{
			this->amount = 0;
			cout << "Amount must be > 0\n";
			return;
		}


	}
	double  getAmount()
	{
		return amount;
	}

	void  setSource(string source)
	{
		this->source = source;
	}
	string  getSource()
	{
		return source;
	}

	void  setDate(Date date)
	{
		this->date = date;
	}
	Date  getDate()
	{
		return date;
	}


};

 

