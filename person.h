/**
 * @file Person.h
 * @author Maharaj Teertha Deb (teertha.deb579@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include "Date.h"
#include "Address.h"
#include "gotoxy.h"

using namespace std;

class Person
{
	private:
	//variables:
		//These lines are declaring variables for storing the user's name, phone number, password, email, sex, birth date, and address.
		string userName, userPhoneNumber , userPassword , userEmail;
		char userSex;
		Date userBirthDate;
		Address userAddress;
		//functions:
	public:
		//variables:

		//functions:

		//default constructor:
			/**
			 * @brief Construct a new Person object
			 * It initializes the member variables `name`, `sex`, `Birth_date`, and `user` with default values.
			 */
			Person()
			{
				userName = "NoName";
				userSex ='N';
				userPassword = "Password";
				userEmail = "abcd@abcd.com";
			}

		//constructor(s):
			/**
			 * @brief Construct a new Person object
			 * The `Person` constructor is creating a new `Person` object with the provided parameters.
			 * It takes in various details such as the user's name, password, address, birth date, sex, phone number, and email.
			 * It then calls the `set_every_thing_for_user` function to set all the member variables of the `Person` object with the provided values.
			 * @param user_name [string] : Name of the person
			 * @param user_password [string] : password for that person
			 * @param user_street [string] : street from Address
			 * @param user_city [string] : city from Address
			 * @param user_province [string] : province from Address
			 * @param user_country [string] : country from Address
			 * @param user_PostalCode [string] : Postal Code from Address
			 * @param user_ApartmentNumber [int] : Dfault 0, The user's apartment number, if applicable.
			 * @param user_unitNumber [int] : Dfault 0 , The user_unitNumber
			 * @param user_birth_date [int] : day from Date
			 * @param user_birth_month [int] : month from Date
			 * @param user_birth_year [int] : year from Date
			 * @param user_sex [char] : Expected ('M' / 'F' / 'G' / 'T')
			 * @param user_phone_number [string] : User phone number with country code
			 * @param user_email [string] : User email address. Expected '@xx....com' at the end
			 * 
			 * @throws [string] : "Invalid Email passed" exception;
			 * @throws [String] The password is less than 8 words. Can not set password.
			 * @throws [String] The password is less than 8 words. Can not set password.
			 * @throws UserName can not have a digit in it
			 * @throws [String] Invalid Phone Number
			 */
			Person(string user_name , string user_password , string user_street , string user_city , string user_province , string user_country ,
					string user_PostalCode , int user_ApartmentNumber , int user_unitNumber , short int user_birth_date , short int user_birth_month , 
					short int user_birth_year , char user_sex , string user_phone_number , string user_email)
			{
				set_every_thing_for_user(user_name , user_password , user_street , user_city , user_province , user_country , user_PostalCode , 
				user_ApartmentNumber , user_unitNumber, user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , user_email);
			}


			// //copy constructors:
			// customers(const customers &obj)
			// {
			// 	//return *this;
			// }

			// //destructor:
			// ~Person()
			// {

			// }


		//setters:
			/**
			 * @brief Set the user password object
			 *
			 * @param new_password [String] : expected more than 8 words. otherwise exception thrown;
			 * 
			 * @throws [String] The password is less than 8 words. Can not set password.
			 */
			void set_user_password(string new_password)
			{
				if(new_password.size() < 8){
					throw string ("The password is less than 8 words. Can not set password.");
				}
				userPassword = new_password;
			}


			/**
			 * @brief Set the user name object
			 * 
			 * @param user_name [String] : name of the user
			 * 
			 * @throws UserName can not have a digit in it
			 */
			void set_user_name(string user_name)
			{

				if(stringHasAnyDigit(user_name)){
					throw string ("UserName can not have a digit in it");
				}
				userName = user_name;
			}

			/**
			 * @brief: function sets the address of a user by taking in the street, city, province, country, postal
			 * code, apartment number, and unit number as parameters.
			 *
			 * @param user_street [string] : The name of the street where the user lives.
			 * @param user_city [string] : The name of the city where the user resides.
			 * @param user_province [string] : The user_province parameter represents the state or province of the user's address.
			 * @param user_country [string] : The name of the country where the user resides.
			 * @param user_PostalCode [string] : The user_PostalCode parameter is a string that represents the full postal
			 * code of the user's address.
			 * @param user_apartmentNumber [int] : The user's apartment number.
			 * @param user_unitNumber [int] : The unit number of the user's address.
			 * 
			 */
			void set_user_address(string user_street , string user_city , string user_province , string user_country , string user_PostalCode , int user_apartmentNumber , int user_unitNumber)
			{
				userAddress.set_Address(user_street , user_city , user_province , user_country , user_PostalCode , user_apartmentNumber , user_unitNumber);
			}

			/**
			 * @brief Set the user address object
			 * 
			 * @param a [Address] : Address of the user 
			 */
			void set_user_address(Address a)
			{
				this->userAddress = Address(a);
			}

			/**
			 * @brief: function sets the user's phone number if it consists only of digits or if the first character
			 * is '+' and the rest are digits, otherwise it throws an exception.
			 *
			 * @param user_phone_number [string] : The parameter `user_phone_number` is a string that represents the phone
			 * number of a user.
			 * 
			 * @throws [String] Invalid Phone Number
			 */
			void set_users_phone_number(string user_phone_number)
			{
				if (all_of(user_phone_number.begin(), user_phone_number.end(), ::isdigit)) {
					userPhoneNumber = user_phone_number;
				}
				else if(all_of(user_phone_number.begin() + 1, user_phone_number.end(), ::isdigit)) { // the first char could be '+'
					userPhoneNumber = user_phone_number;
				}
				else{
					throw string("Invalid Phone Number");
				}
			}


			/**
			 * @brief : The function sets the email address for a user, but throws an exception if the email is invalid.
			 * 
			 * @param email[string] : The email parameter is a string that represents the email address that needs to be set.
			 * 
			 * @throws [string] : "Invalid Email passed" exception;
			 */
			void set_email(string email)
			{
				if(checkIfValidEmail(email)){
					userEmail = email;
				}
				else{
					throw string("Invalid Email passed");
				}
			}

			/**
			 * @brief : function "set_user_sex" sets the sex of the user to a new value.
			 *
			 * @param newSex[char] : The newSex parameter is a character that represents the user's sex.
			 */
			void set_user_sex(char newSex)
			{
				userSex = newSex;
			}


			/**
			 * The function sets the birth date of a user using the provided day, month, and year.
			 *
			 * @param day [int] : 1 ~ 31
			 * @param month [int] : 1 ~ 12
			 * @param year [int] : 1900 ~ current_year
			 */
			void set_user_birth_date(short int user_birth_day , short int user_birth_month , short int user_birth_year)
			{
				userBirthDate.setDate(user_birth_day , user_birth_month , user_birth_year);
			}

			/**
			 * @brief Set the every thing for user object
			 * The code is defining a function called "set_every_thing_for_user" that sets various attributes for a user object.
			 * The function takes in multiple parameters including the user's name, password, address, birth date, sex, phone number, and email.
			 * It then calls various setter functions to set these attributes for the user object.
			 *
			 * @param user_name [string] : Name of the person
			 * @param user_password [string] : password for that person
			 * @param user_street [string] : street from Address
			 * @param user_city [string] : city from Address
			 * @param user_province [string] : province from Address
			 * @param user_country [string] : country from Address
			 * @param user_PostalCode [string] : Postal Code from Address
			 * @param user_ApartmentNumber [int] : Dfault 0, The user's apartment number, if applicable.
			 * @param user_unitNumber [int] : Dfault 0 , The user_unitNumber
			 * @param user_birth_date [int] : day from Date
			 * @param user_birth_month [int] : month from Date
			 * @param user_birth_year [int] : year from Date
			 * @param user_sex [char] : Expected ('M' / 'F' / 'G' / 'T')
			 * @param user_phone_number [string] : User phone number with country code
			 * @param user_email [string] : User email address. Expected '@xx....com' at the end
			 *
			 *
			 * @throws [string] : "Invalid Email passed" exception;
			 * @throws [String] The password is less than 8 words. Can not set password.
			 * @throws [String] The password is less than 8 words. Can not set password.
			 * @throws UserName can not have a digit in it
			 * @throws [String] Invalid Phone Number
			 */
			void set_every_thing_for_user(string user_name , string user_password , string user_street , string user_city , string user_province , string user_country , string user_PostalCode, int user_apartmentNumber , int user_UnitNumber , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , string user_email)
			{
				set_user_name(user_name);
				set_users_phone_number(user_phone_number);
				set_user_password(user_password);
				set_email(user_email);
				set_user_address(user_street , user_city , user_province , user_country , user_PostalCode , user_apartmentNumber , user_UnitNumber);
				set_user_sex(user_sex);
				set_user_birth_date(user_birth_date , user_birth_month , user_birth_year);
				set_users_phone_number(user_phone_number);
			}

			//getters:

			/**
			 * @brief: function "get_name" returns the value of the variable "userName" as a string.
			 *
			 * @return [string] the value of the variable "userName", which is a string.
			 */
			string get_name()
			{
				return userName;
			}


			/**
			 * @brief: function "get_phoneNumber" returns the user's phone number.
			 *
			 * @return [string] the value of the variable "userPhoneNumber", which is a string.
			 */
			string get_phoneNumber()
			{
				return userPhoneNumber;
			}


			/**
			 * @brief : function "get_email" returns the value of the variable "userEmail".
			 *
			 * @return [string] : The email address stored in the variable userEmail.
			 */
			string get_email()
			{
				return userEmail;
			}


			/**
			 * The function "get_address" displays the user's address.
			 */
			string get_address()
			{
				return userAddress.toString();
			}


			/**
			 * @brief: function "get_city" returns the city of the user's address.
			 *
			 * @return [string] The city of the user's address.
			 */
			string get_city()
			{
				return userAddress.getCity();
			}


			/**
			 * @brief: The function "get_province" returns the state of the user's address.
			 *
			 * @return [string] : The state of the user's address.
			 */
			string get_province()
			{
				return userAddress.getState();
			}


			/**
			 * @brief: The function "get_country" returns the country of the user's address.
			 *
			 * @return [string] The country of the user's address.
			 */
			string get_country()
			{
				return userAddress.getCountry();
			}

			/**
			 * @brief Get the DateOfBirth object
			 *
			 * @return [string] string format of date of birth
			 */
			string get_DateOfBirth()
			{
				return userBirthDate.toString();
			}

			char get_sex()
			{
				return userSex;
			}
		//others:

			/**
			 * @brief: function "matchPassword" checks if the given password matches the user's password.
			 *
			 * @param passwordToBeChecked A string representing the password that needs to be checked against
			 * the user's password.
			 *
			 * @return a boolean value;
			 * [true] if password matches
			 * [false] , otherwise
			 */
			bool matchPassword(const string passwordToBeChecked)
			{
				return passwordToBeChecked == userPassword;
			}


			/**
			 * @brief : The code defines a function called "print_formatted_info_for_person" that prints formatted
			 * information for a person.
			 * The function uses the "gxy" function to set the cursor position on the console and then uses the "cout"
			 * statement to print the information.
			 * The information includes the person's name, address, phone number, sex, birth date, and email.
			 *
			 */
			void print_formatted_info_for_person()
			{
				gxy(2 , 1) , cout<<"Name:				"<< userName;
				gxy(2 , 2) , cout<<"Address:			"<< get_address();
				gxy(2 , 3) , cout<<"Phone Number:			"<< userPhoneNumber;
				gxy(2 , 4) , cout<<"Sex:				"<< userSex;
				gxy(2 , 5) , cout<<"Birh Date:			"<< get_DateOfBirth();
				gxy(2 , 6) , cout<<"Email:			"<< userEmail;
			}

			/**
			 * @brief checks if the passed string contains a number or not
			 * The code is defining a function called "stringHasAnyDigit" that takes a string as input and checks if the string contains any digits.
			 * It uses the "any_of" function from the algorithm library to iterate over each character in the string
			 * and checks if it is a digit using the "isdigit" function.
			 * If any digit is found, the function returns true, otherwise it returns false.
			 *
			 * @param s [String] : the string to be checked.
			 * @return true : if there is a number in the string.
			 * @return false : if no number in the string.
			 */
			static bool stringHasAnyDigit(const string s)
			{
				return any_of(s.begin(), s.end(), ::isdigit);
			}

			/**
			 * The function checks if a given string is a valid email address ending with ".com".
			 *
			 * @param str [string] : The input string that needs to be checked if it is a valid email address.
			 *
			 * @return a boolean value. It returns true if the given string is a valid email address, and false otherwise.
			 */
			static bool checkIfValidEmail(const string& str)
			{
				int at_occurance = -1 ;
				for(int i=0 ; str[i] ; i++){
					if(str[i] == '@'){
						at_occurance = i;
					}
					else if(str[i] == '.' and str[i+1] and str[i+1] == 'c' and
							str[i+2] and str[i+2] == 'o' and str[i+3] and
							str[i+3] == 'm' and i > at_occurance + 4 and
							str[i +4 ] == 0){
						return true;
					}
				}
				return false;
			}
			friend ostream &operator<<(ostream & , const Person &);
			//friend istream &operator>>(istream & , Person &);
};

/**
 * @brief : The above code is overloading the << operator for the Person class.
 * It allows an object of the Person class to be printed to an output stream (such as cout) using the << operator.
 * The output stream is passed as the first parameter, and the Person object is passed as the second parameter.
 * The function then prints the various member variables of the Person object to the output stream and returns the output stream.
 *
 * @param strm [ostream] :
 * @param obj [Person]
 * @return ostream& [ostream] : that will be written in the screen.
 */
ostream &operator<<(ostream &strm, const Person &obj)
{
	strm << obj.userName << obj.userAddress << obj.userPhoneNumber
			<< obj.userSex << obj.userBirthDate << obj.userEmail << '\n';
	return strm;
}


/**
 * @brief The code snippet defines an overloaded `>>` operator for the `Person` class in C++, which
 * allows extraction of values from an input stream and assigns them to the corresponding member
 * variables of a `Person` object.
 *
 * @return The `ostream&` object `strm` is being returned.
 */
// ostream& operator>>(istream & strm, Person &obj)
// {
// 	string line;
//     getline(strm, line);
//     istringstream iss(line);
//     //The code snippet is using the `getline` function to extract values from the `iss` input string stream and assign them to the corresponding member variables
// 	// of the Person object `obj`.
// 	getline(iss , obj.userName , ',');
// 	getline(iss , obj.userAddress , ',');
// 	getline(iss , obj.userPhoneNumber , ',');
// 	getline(iss , obj.userSex , ',');
// 	getline(iss , obj.userBirthDate , ',');
// 	getline(iss , obj.userEmail );
//     return strm;
// }
