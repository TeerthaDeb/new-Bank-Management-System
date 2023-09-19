#include <bits/stdc++.h>
#include "Person.h"
#include "Date.h"
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;


class Employee : public Person
{
private:
	static long long int total_employee;

	//variables:

	Date joiningDate;
	double salary , total_Work_Hours;
	bool isManager , isExecutive;
	string rank;
	long long int employeeId = 1000001 , accounts_Created = 0;

	//functions:

	/**
	 * The function sets a new employee number by adding the total number of employees to a base number.
	 */
	void set_new_employeeID()
	{
		employeeId = 1000001 + total_employee + 10; //Because , The Owner will be 1000001 and the rest will start from 1000011
	}

public:
	//variables:

	//functions:

	//default constructor:
	
	/**
	 * The Employee() function increments the total number of employees and sets a new employee ID.
	 */
	Employee()
	{
		total_employee++;
		set_new_employeeID();
	}

	//constructor(s):

	/**
	 * The Employee constructor initializes the attributes of an Employee object.
	 *
	 * @param user_name [String] The name of the employee.
	 * @param user_password [String] The password for the employee's account.
	 * @param user_street [String] The street address of the employee's residence.
	 * @param user_city [String] The city where the employee resides.
	 * @param user_province [String] The province where the employee resides.
	 * @param user_country [String] The country where the employee resides.
	 * @param user_PostalCode [String] The user_PostalCode parameter is a string that represents the postal code of
	 * 							the employee's address.
	 * @param user_ApartmentNumber [int] The apartment number of the employee's residence.
	 * @param user_unitNumber [int] The user_unitNumber parameter is an integer that represents the unit number
	 * 							of the employee's apartment.
	 * @param user_birth_date [short] The birth date of the employee (day).
	 * @param user_birth_month [short] The user_birth_month parameter represents the month of birth for the
	 *							 employee. It is a short integer value.
	 * @param user_birth_year [short] The year in which the employee was born.
	 * @param user_sex [char] The user_sex parameter is a character that represents the gender of the employee.
	 * 						It can be either 'M' for male or 'F' for female.
	 * @param user_phone_number [String] The user_phone_number parameter is a string that represents the phone
	 * 								number of the employee.
	 * @param user_email [String] The email address of the employee.
	 * @param joiningDate [Date] The joiningDate parameter is of type Date and represents the date when the
	 * 							employee joined the company.
	 * @param salary [double] The salary parameter is a double data type that represents the employee's salary.
	 * @param isManager [bool] Whether the employee is a manager or not.
	 * @param isExecutive [bool] Whether the employee is an executive or not.
	 * @param rank [String] The "rank" parameter in the Employee constructor is a string that represents the rank
	 * 				or position of the employee within the company. It could be something like "Junior Developer",
	 * 				"Senior Manager", "Executive Vice President", etc.
	 *
	 * @throws [string] "Invalid Email passed" exception;
	 * @throws [String] The password is less than 8 words. Can not set password.
	 * @throws [String] The password is less than 8 words. Can not set password.
	 * @throws UserName can not have a digit in it
	 * @throws [String] Invalid Phone Number
	 */
	Employee(string user_name , string user_password , string user_street , string user_city , string user_province , string user_country , 
				string user_PostalCode , int user_ApartmentNumber , int user_unitNumber , short int user_birth_date , short int user_birth_month , 
				short int user_birth_year , char user_sex , string user_phone_number , string user_email , Date joiningDate , double salary ,
				bool isManager , bool isExecutive , string rank)
	{
		setEverythingForEmployee(user_name , user_password , user_street , user_city , user_province , user_country , user_PostalCode , user_ApartmentNumber , user_unitNumber 
								, user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , user_email ,
									 joiningDate , salary , isManager , isExecutive , rank);
	}

	//copy constructors: 
	// Employee(const Employee &object)
	// {
		
	// 	return *this;
	// }

	//setters:

	/**
	 * @brief This function sets the joining date of an object to the specified date.
	 * 
	 * @param date The parameter "date" is of type "Date", which suggests that it is expecting an object
	 * of the "Date" class as input.
	 */
	void set_joining_date(Date date)
	{
		joiningDate = Date(date);
	}

	/**
	 * @brief The function sets the joining date of an employee.
	 * 
	 * @param day An integer representing the day of the month.
	 * @param month The month parameter represents the month of the joining date. It should be an integer
	 * 			value between 1 and 12, where 1 represents January and 12 represents December.
	 * @param year The year parameter represents the year of the joining date. It is an integer value.
	 */
	void set_joining_date(int day , int month , int year)
	{
		joiningDate = Date(day , month , year);
	}

	/**
	 * @brief Set the salary object
	 * 
	 * @param salary [double]
	 */
	void set_salary(double salary)
	{
		this->salary = salary;
	}

	/**
	 * @brief Set the is manager object
	 * 
	 * @param managerial_Status [bool] : true / False
	 */
	void set_is_manager(bool managerial_Status)
	{
		this->isManager = managerial_Status;
	}

	/**
	 * @brief Set the is Executive object, but if not a manager, can not be an executive
	 * 
	 * @param Executive_status [bool] : true / False
	 */
	void set_is_Executive(bool Executive_status)
	{
		if(isManager == false and Executive_status == true){
			cout << "Can not make anyone executive who is not a manager";
		}
		else{
			this->isExecutive= Executive_status;
		}
	}

	/**
	 * @brief Set the Rank object
	 * 
	 * @param rank [String] : Rank of the employee
	 */
	void set_Rank(string rank)
	{
		this->rank = rank;
	}

	/**
	 * The function sets all the necessary information for an employee, including personal details,
	 * joining date, salary, and job-related information.
	 * 
	 * @param user_name [String] The name of the employee.
	 * @param user_password [String] The password for the employee's account.
	 * @param user_street [String] The street address of the employee's residence.
	 * @param user_city [String] The city where the employee resides.
	 * @param user_province [String] The province where the employee resides.
	 * @param user_country [String] The country where the employee resides.
	 * @param user_PostalCode [String] The user_PostalCode parameter is a string that represents the postal code of
	 * 							the employee's address.
	 * @param user_ApartmentNumber [int] The apartment number of the employee's residence.
	 * @param user_unitNumber [int] The user_unitNumber parameter is an integer that represents the unit number
	 * 							of the employee's apartment.
	 * @param user_birth_date [short] The birth date of the employee (day).
	 * @param user_birth_month [short] The user_birth_month parameter represents the month of birth for the
	 *							 employee. It is a short integer value.
	 * @param user_birth_year [short] The year in which the employee was born.
	 * @param user_sex [char] The user_sex parameter is a character that represents the gender of the employee.
	 * 						It can be either 'M' for male or 'F' for female.
	 * @param user_phone_number [String] The user_phone_number parameter is a string that represents the phone
	 * 								number of the employee.
	 * @param user_email [String] The email address of the employee.
	 * @param joiningDate [Date] The joiningDate parameter is of type Date and represents the date when the
	 * 							employee joined the company.
	 * @param salary [double] The salary parameter is a double data type that represents the employee's salary.
	 * @param isManager [bool] Whether the employee is a manager or not.
	 * @param isExecutive [bool] Whether the employee is an executive or not.
	 * @param rank [String] The "rank" parameter in the Employee constructor is a string that represents the rank
	 * 				or position of the employee within the company. It could be something like "Junior Developer",
	 * 				"Senior Manager", "Executive Vice President", etc.
	 * 
	 * @throws [string] "Invalid Email passed" exception;
	 * @throws [String] The password is less than 8 words. Can not set password.
	 * @throws [String] The password is less than 8 words. Can not set password.
	 * @throws UserName can not have a digit in it
	 * @throws [String] Invalid Phone Number
	 */
	void setEverythingForEmployee(string user_name, string user_password, string user_street, string user_city, string user_province, string user_country,
								  string user_PostalCode, int user_ApartmentNumber, int user_unitNumber, short int user_birth_date, short int user_birth_month,
								  short int user_birth_year, char user_sex, string user_phone_number, string user_email, Date joiningDate, double salary,
								  bool isManager, bool isExecutive, string rank)
	{
		Person::set_every_thing_for_user(user_name , user_password , user_street , user_city , user_province , user_country , user_PostalCode , user_ApartmentNumber , 
											user_unitNumber , user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , user_email);	
		
		set_joining_date(joiningDate);
		set_salary(salary);
		set_is_manager(isManager);
		set_is_Executive(isExecutive);
		set_Rank(rank);
	}

	/**
	 * The function "created_New_account" increments the number of accounts created and increases the
	 * salary by 0.5 as a reward.
	 */
	void created_New_account()
	{
		this->accounts_Created++;
		salary += 0.5; // As a reward
	}
	//getters:

	//friend functions:

};
