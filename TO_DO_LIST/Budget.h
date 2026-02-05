#pragma once

#include"Date.h"
#include<vector>
#include"Expense.h"
#include"Income.h"


class Budget
{
private:
	vector<Expense>expenses;
	vector<Income>incomes;
	bool   isSameWeek(Date d, Date  startDate)

	{
		if (d.year != startDate.year || d.month != startDate.month)
			return false;

		int diff = d.day - startDate.day;
		return (diff >= 0 && diff <= 6);
	}
public:


	void  addExpense(Expense newExpense)
	{
		expenses.push_back(newExpense);
	}

	void  deleteExpense(int expenseId)
	{
		if (expenses.empty())
		{
			cout << "Expenses list is Empty \n";
			return;
		}
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getId() == expenseId)
			{
				expenses.erase(it);
				return;
			}
		}
	}
	void updateExpense(double amount, string category, int id)
	{
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getId() == id)
			{
				it->setAmount(amount);
				it->setCategory(category);
				return;
			}
		}
		cout << "This ID is not Found \n";
	}
	Expense* getExpense(int expenseId)
	{
		if (!searchExpense(expenseId))
		{
			return nullptr;
		}
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getId() == expenseId)
			{

				return &(*it);
			}
		}

	}
	bool  searchExpense(int expenseId)
	{
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getId() == expenseId)
			{

				return true;
			}
		}
		return false;
	}
	void  displayExpenses()
	{
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			it->display();
			cout << "========================================\n";
		}
	}
	double  calculateExpensesByCategory(string category)
	{
		double totalExpenses = 0;
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getCategory() == category)
			{
				totalExpenses += it->getAmount();

			}
		}
		return totalExpenses;
	}
	void  displayExpensesByCategory(string category)
	{
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getCategory() == category)
			{
				it->display();

			}
		}

	}
	void  displayExpensesByDate(Date date)
	{
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			if (it->getDate().day == date.day && it->getDate().month == date.month && it->getDate().year == date.year)
			{
				it->display();

			}
		}
	}
	double  calculateTotalExpenses()
	{
		double totalExpenses = 0;
		for (auto it = expenses.begin(); it != expenses.end(); it++)
		{
			totalExpenses += it->getAmount();

		}
		return totalExpenses;
	}


	void  addIncome(Income newIncome)
	{
		incomes.push_back(newIncome);
	}
	void  deleteIncome(int incomeId)
	{

		if (incomes.empty())
		{
			cout << "Incomes list is Empty \n";
			return;
		}
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getId() == incomeId)
			{
				incomes.erase(it);
				return;
			}
		}
	}
	void updateIncome(double amount, string source, int id)
	{
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getId() == id)
			{
				it->setAmount(amount);
				it->setSource(source);
				return;
			}
		}
		cout << "This ID is not Found \n";
	}
	Income* getIncome(int incomeId)
	{
		if (!searchIncome(incomeId))
		{
			return nullptr;
		}
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getId() == incomeId)
			{

				return &(*it);
			}
		}
	}
	bool  searchIncome(int incomeId)
	{
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getId() == incomeId)
			{

				return true;
			}
		}
		return false;
	}
	void  displayIncome()
	{
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			it->display();
			cout << "========================================\n";
		}
	}
	void  displayIncomesBySource(string source)
	{
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getSource() == source)
			{
				it->display();

			}
		}
	}
	double  calculateIncomesBySource(string source)
	{
		double totalIncomes = 0;
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getSource() == source)
			{
				totalIncomes += it->getAmount();

			}
		}
		return totalIncomes;
	}
	void   displayIncomesByDate(Date date)
	{
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			if (it->getDate().day == date.day && it->getDate().month == date.month && it->getDate().year == date.year)
			{
				it->display();

			}
		}
	}
	double  calculateTotalIncomes()
	{
		double totalIncomes = 0;
		for (auto it = incomes.begin(); it != incomes.end(); it++)
		{
			totalIncomes += it->getAmount();

		}
		return totalIncomes;
	}

	double  calculateBalance()
	{
		return calculateTotalIncomes() - calculateTotalExpenses();
	}
	void  dailyReport(Date& d)
	{
		double totalExpenses = 0;
		double totalIncome = 0;
		bool hasExpenses = false;
		bool hasIncome = false;

		cout << "===== Daily Report =====\n";
		cout << "Date: " << d.day << "/" << d.month << "/" << d.year << endl;
		cout << "------------------------\n";

		cout << "Expenses:\n";

		for (Expense& e : expenses)
		{
			Date ed = e.getDate();

			if (ed.day == d.day && ed.month == d.month && ed.year == d.year)
			{
				e.display();
				totalExpenses += e.getAmount();
				hasExpenses = true;
			}
		}

		if (!hasExpenses)
		{
			cout << "No expenses recorded for this day \n";
		}

		cout << "Income:\n";

		for (Income& i : incomes)
		{
			Date id = i.getDate();

			if (id.day == d.day && id.month == d.month && id.year == d.year)
			{
				i.display();
				totalIncome += i.getAmount();
				hasIncome = true;
			}
		}

		if (!hasIncome)
		{
			cout << "No income recorded for this day \n";
		}

		cout << "------------------------\n";
		cout << "Total Expenses: " << totalExpenses << endl;
		cout << "Total Income:   " << totalIncome << endl;

		double balance = totalIncome - totalExpenses;
		cout << "Daily Balance:  " << balance << endl;

		if (balance < 0)
		{
			cout << "Expenses exceeded income today!\n";
		}

		cout << "========================\n";

	}
	void weeklyReport(Date& startDate)
	{
		double totalExpenses = 0;
		double totalIncome = 0;
		bool hasExpenses = false;
		bool hasIncome = false;

		cout << "===== Weekly Report =====\n";
		cout << "From : "
			<< startDate.day << "/"
			<< startDate.month << "/"
			<< startDate.year << endl;
		cout << "To :   "
			<< startDate.day + 6 << "/"
			<< startDate.month << "/"
			<< startDate.year << endl;
		cout << "-------------------------\n";

		cout << "Expenses:\n";

		for (Expense& e : expenses)
		{
			Date ed = e.getDate();

			if (isSameWeek(ed, startDate))
			{
				e.display();
				totalExpenses += e.getAmount();
				hasExpenses = true;
			}
		}

		if (!hasExpenses)
		{
			cout << "No expenses recorded this week.\n";
		}
		cout << "Income:\n";

		for (Income& i : incomes)
		{
			Date id = i.getDate();

			if (isSameWeek(id, startDate))
			{
				i.display();
				totalIncome += i.getAmount();
				hasIncome = true;
			}
		}

		if (!hasIncome)
		{
			cout << "No income recorded this week.\n";
		}

		cout << "-------------------------\n";
		cout << "Total Weekly Expenses: " << totalExpenses << endl;
		cout << "Total Weekly Income:   " << totalIncome << endl;

		double balance = totalIncome - totalExpenses;
		if (balance < 0)
		{
			balance = 0;

		}
		cout << "Weekly Balance:        " << balance << endl;

		if (balance < 0)
		{
			balance = 0;
			cout << "You spent more than you earned this week!\n";
		}

		cout << "=========================\n";
	}

	void  monthlyReport(int month, int year)
	{
		double totalExpenses = 0;
		double totalIncome = 0;
		bool hasExpenses = false;
		bool hasIncome = false;

		cout << "===== Monthly Report =====\n";
		cout << "Month: " << month << " / " << year << endl;
		cout << "--------------------------\n";

		cout << "Expenses:\n";

		for (Expense& e : expenses)
		{
			Date ed = e.getDate();

			if (ed.month == month && ed.year == year)
			{
				e.display();
				totalExpenses += e.getAmount();
				hasExpenses = true;
			}
		}

		if (!hasExpenses)
		{
			cout << "No expenses recorded for this month.\n";
		}

		cout << "Income:\n";

		for (Income& i : incomes)
		{
			Date id = i.getDate();

			if (id.month == month && id.year == year)
			{
				i.display();
				totalIncome += i.getAmount();
				hasIncome = true;
			}
		}

		if (!hasIncome)
		{
			cout << "No income recorded for this month \n";
		}

		cout << "--------------------------\n";
		cout << "Total Monthly Expenses: " << totalExpenses << endl;
		cout << "Total Monthly Income:   " << totalIncome << endl;

		double balance = totalIncome - totalExpenses;
		if (balance < 0)
		{
			balance = 0;
			 
		}
		cout << "Monthly Balance:        " << balance << endl;

		if (balance < 0)
		{
			 
			cout << "Expenses exceeded income this month!\n";
		}

		cout << "==========================\n";
	}
	void  summaryReport()
	{
		double totalExpenses = calculateTotalExpenses();
		double totalIncomes = calculateTotalIncomes();
		double balance = calculateBalance();

		cout << "========== Summary Report ==========\n";
		cout << "Total Income :    " << totalIncomes << endl;
		cout << "Total Expenses :   " << totalExpenses << endl;
		cout << "Expenses Percentage of Income: " << calculateExpensePercentage() << "%\n";


		cout << "-----------------------------------\n";
		if (balance < 0)
		{
			balance = 0;

		}
		cout << "Balance:    " << balance << endl;

		if (balance > 0)
		{
			cout << "Status: You are saving money \n";
		}
		else if (balance == 0)
		{
			cout << "Status:your income equals your expenses\n";
		}
		else
		{
			balance = 0;
			cout << "Status: Overspending \n";
		}

		cout << "===================================\n";
	}
	double  calculateExpensePercentage()
	{
		double totalIncome = calculateTotalIncomes();
		if (totalIncome == 0)
			return 0;
		double totalExpenses = calculateTotalExpenses();
		return (totalExpenses / totalIncome) * 100;
	}



};



