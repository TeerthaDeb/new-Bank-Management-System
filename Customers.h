#include <bits/stdc++.h>
#include <string>
#include "Person.h"
#include "gotoxy.h"

using namespace std;


class Customer : public Person
{
private:
	//variables:
	bool active_status = false , has_credit_card = false , is_employe = false;
	short number_of_transctions_made = 00;
	double checking_amount = 0 , saving_amount = 0 , visa_amount = 0 , interest_rate , points = 0 , loans = 0;
	long long int account_number = 100000000 + (rand() % 899999999) , credit_card_number = 1000000000 + (rand() % 8999999999) , employee_number = 0 ;
	static numbers_of_customers = 0;
	
	//functions:

public:
	//variables:

	//functions:

	//default constructor:
	Customer()
	{
		numbers_of_customers++;
	}

	//constructor(s):
	Customer(Person p) : Customer()
	{

	}

	//copy constructors: 
	Customer(const Customer &object)
	{
		
		return *this;
	}

	//destructor:
	~Customer()
	{
		
	}
	//setters:

	void set_everything_for_customer(string customer_name , string customer_password , string customer_street , string customer_city , string customer_province , string customer_country , string customer_PostalCode, int customer_apartmentNumber , int customer_UnitNumber , short int customer_birth_date , short int customer_birth_month , short int customer_birth_year , char customer_sex , string customer_phone_number , string customer_email , 
										bool customer_active_status , bool customer_has_credit_card , bool is_cusomer_employe , short number_of_transections_made , double checking_amount , double saving_amount , double visa_amount , double interest_rate , double points , double loans)
	{
		set_every_thing_for_user(customer_name , customer_password , customer_street , customer_city , customer_province , customer_country , customer_PostalCode , customer_apartmentNumber , customer_UnitNumber , customer_birth_date , customer_birth_month , customer_birth_year , customer_sex , customer_phone_number , customer_email);

	}

	/**
	 * The function sets the active status of a customer.
	 * 
	 * @param customer_active_status [bool] : true / false;
	 * 	 	The parameter "customer_active_status" is a boolean variable that represents the
	 * 		active status of a customer. It is used to set the active status of the customer object.
	 */
	void set_active_status(bool customer_active_status)
	{
		this->active_status = customer_active_status;
	}

	/**
	 * The function sets the value of the "has_credit_card" variable for a customer.
	 * 
	 * @param customer_has_credit_card [bool] : true / false
	 *  		A boolean value indicating whether the customer has a credit card or not.
	 */
	void set_has_credit_card(bool customer_has_credit_card)
	{
		this->has_credit_card = customer_has_credit_card;
	}

	/**
	 * The function sets the value of the is_employe variable to the provided boolean value.
	 * 
	 * @param is_customer_employee [bool] : true / false
	 * 			A boolean value indicating whether the customer is an employee or not.
	 */
	void set_is_employe(bool is_customer_employee)
	{
		this->is_employe = is_customer_employee;
	}
	
	/**
	 * The function sets the checking amount to a new value.
	 * 
	 * @param new_checking_amount The new value for the checking amount that you want to set.
	 */
	void set_checking_amont(double new_checking_amount)
	{
		this->checking_amount = new_checking_amount;
	}

	void 

	//getters:

	//friend functions: