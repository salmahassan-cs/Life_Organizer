#pragma once
#include<iostream>
using namespace std;
#include"Date.h"
static class Common
{ 
public:

	bool static validateDate(Date date)
	{
		if (date.month == 2 && date.day > 29)
		{
			return false;
		}
		else if (date.month > 12 || date.month < 1 || date.day < 1 || date.day>31/*date.year>2026)*/)
		{
			return false;

		}
		else
		{
			return true;
		}
	}



};

