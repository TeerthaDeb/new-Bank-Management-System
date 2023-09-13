#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <windows.h>

# define current_year  2023   // Change year here;
using namespace std;

class Date
{
private:
	int day, month, year;
	string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
	// Default constructor
	/**
	 * @brief Construct a new Date object
	 *
	 */
	Date()
	{
		day = 1;
		month = 1;
		year = 2023;
	}

	// Parameterized constructor
	/**
	 * @brief Construct a new Date object
	 *
	 * @param day [int] : 1 ~ 31
	 * @param month [int] : 1 ~ 12
	 * @param year [int] : 1900 ~ current_year
	 */
	Date(int day, int month, int year)
	{
		setDate(day, month, year);
	}

	// Setter methods

	/**
	 * @brief Set the Date object
	 *
	 * @param day [int] : 1 ~ 31
	 * @param month [int] : 1 ~ 12
	 * @param year [int] : 1900 ~ current_year
	 */
	void setDate(int day, int month, int year)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}

	/**
	 * @brief Set the Day object
	 *
	 * @param day [int] : 1 - 31
	 */
	void setDay(int day)
	{
		if (day > 31 or day < 0)
		{
			cout << "Out of bound setting the day = (" << day << ").\n Returning to the process where this was called from , without setting the Day.";
			return;
		}
		this->day = day;
	}

	/**
	 * @brief Set the Month object
	 *
	 * @param month [int] : 1 - 12
	 */
	void setMonth(int month)
	{
		if (month > 12 or month < 1)
		{
			cout << "Out of bound setting the Month = (" << month << ").\n Returning to the process where this was called from , without setting the Month.";
			return;
		}
		this->month = month - 1;
	}

	/**
	 * @brief Set the Year object
	 *
	 * @param year [int] : 1900 - current_year
	 */
	void setYear(int year)
	{
		if (year < 0 or year > current_year)
		{
			cout << "Out of bound setting the Year = (" << year << ").\n Returning to the process where this was called from , without setting the Year.";
			return;
		}
		this->year = year;
	}

	// Getter methods
	/**
	 * @brief Get the Day object
	 *
	 * @return int the Day
	 */
	int getDay()
	{
		return day;
	}

	/**
	 * @brief Get the Month object
	 *
	 * @return string : MMM = month
	 */
	string getMonth()
	{
		return months[month % 12];
	}

	/**
	 * @brief Get the Year object
	 *
	 * @return int year
	 */
	int getYear()
	{
		return year;
	}

	// Display the date
	/**
	 * The function "display" prints the date in the format "day/month/year".
	*/
	void display() const
	{
		cout << day << "/" << months[month] << "/" << year;
	}

	/**
	 * @brief returns string representation of the date
	 *
	 * @return string  to_string(day) + "/" + months[month] + "/" + to_string(year)
	 */
	string toString()
	{
		// return to_string( to_string(day) + "/" + months[month] + "/" + to_string(year));
		string message;
		message += to_string(getDay());
		message += " / ";
		message += months[month];
		message += " / ";
		message += to_string(getYear());
		return message;
	}

	// Operator Methods:
	// Overloading the assignment operator
	/**
	 * @brief
	 *
	 * @param other
	 * @return Date&
	 */
	Date &operator=(const Date &other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}

	// Overloading the less than operator
	/**
	 * @brief
	 *
	 * @param other
	 * @return true
	 * @return false
	 */
	bool operator<(const Date &other) const
	{
		if (year < other.year)
			return true;
		else if (year == other.year && month < other.month)
			return true;
		else if (year == other.year && month == other.month && day < other.day)
			return true;
		return false;
	}

	// Overloading the greater than operator
	/**
	 * @brief
	 *
	 * @param other
	 * @return true
	 * @return false
	 */
	bool operator>(const Date &other) const
	{
		if (year > other.year)
			return true;
		else if (year == other.year && month > other.month)
			return true;
		else if (year == other.year && month == other.month && day > other.day)
			return true;
		return false;
	}

	// Overloading the equality operator
	/**
	 * @brief
	 *
	 * @param other
	 * @return true
	 * @return false
	 */
	bool operator==(const Date &other) const
	{
		return (day == other.day && month == other.month && year == other.year);
	}

	// Overloading the inequality operator
	/**
	 * @brief
	 *
	 * @param other
	 * @return true
	 * @return false
	 */
	bool operator!=(const Date &other) const
	{
		return !(*this == other);
	}

	//Friend functions:
	friend ostream &operator<<(ostream& , const Date& );
	friend istream &operator>>(istream& , Date &);

};


/**
 * @brief this function overloads the << operator to allow for easy output of a Date object in the format
 * "day/month/year".
 *
 * @param strm
 * @param obj
 * @return ostream&
 */
ostream &operator<<(ostream &strm, const Date &obj)
{
	strm <<  obj.day << "/" << obj.months[obj.month] << "/" << obj.year ;
	return strm;
}

/**
 * @brief The above function overloads the >> operator to read a Date object from an input stream.
 *
 * @param strm
 * @param obj
 * @return istream&
 */

istream &operator>>(istream &strm , Date &obj)
{
	string line;
    getline(strm, line);
    istringstream iss(line);
    iss >> obj.day;     // Read day as integer
    iss.ignore();       // Ignore the '/'
    iss >> obj.month;   // Read month as integer
    iss.ignore();       // Ignore the '/'
    iss >> obj.year;    // Read year as integer
    return strm;
}
