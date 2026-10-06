
#pragma once
#include <string>

class Date
{
public:

	class Triad 
	{
	private:
		int first;
		int second;
		int third;
	public:
		Triad();

		int GetFirst() const { return first; }
		int GetSecond() const { return second; }
		int GetThird() const { return third; }

		void SetFirst(int value) { first = value; }
		void SetSecond(int value) { second = value; }
		void SetThird(int value) { third = value; }

		bool Init(int f, int s, int t);
		void Read();
		void Display() const;
		std::string toString() const;

		void IncrementFirst() { first++; }
		void IncrementSecond(){ second++;}
		void IncrementThird() { third++; }
		void IncrementAll();

	};

private:
	Triad triad;

	static bool IsLeapYear(int year);
	static int DaysInMonth(int year, int month);
public:
	Date();

	Triad GetTriad() const { return triad; }
	void SetTriad(const Triad& t);

	int GetYear() const { return triad.GetFirst(); }
	int GetMonth() const { return triad.GetSecond(); }
	int GetDay() const { return triad.GetThird(); }

	bool SetYear(int y);
	bool SetMonth(int m);
	bool SetDay(int d);

	bool Init(int year, int month, int day);
	bool Init(const Triad& t);
	void Read();
	void Display() const;
	std::string toString() const;

	void IncrementDay();
	void IncrementMonth();
	void IncrementYear();

	void AddDays(int n);
};

