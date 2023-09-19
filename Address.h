/**
 * @file Address.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Address {
private:
    // The code is declaring private member variables of the class Address.
	// These variables represent the street, city, state, country, postal code, apartment number, and unit number of an address.
	string Street , City ,  State , Country , PostalCode;
	int ApartmentNumber , UnitNumber;

public:
    // Default constructor

	/**
	 * @brief Default Constructor of the `Address` class
	 * It initializes the private member variables of the class to their default values.
	 * In this case, it sets the `Street`, `City`, `State`, `PostalCode`, and `Country` variables to empty strings,
	 * and the `ApartmentNumber` and `UnitNumber` variables to 0.
	*/
	Address() {
		Street = "" ;
		City = "" ;
		State = "" ;
		PostalCode = "" ;
		Country = "" ;
		ApartmentNumber = 0 ;
		UnitNumber = 0 ;
	}

    // Parameterized constructor
	/**
	 * @brief Construct a new Address object
	 *
	 * @param Street : the name of the street
	 * @param City : the name of the city
	 * @param State : state / Province
	 * @param Country : Country Name
	 * @param PostalCode : Full Postal Code
	 * @param ApartmentNumber : Default : 00
	 * @param UnitNumber : Default : 00
	 */
	Address(string Street , string City , string State , string Country , string PostalCode , int ApartmentNumber = 0 , int UnitNumber = 0) {
		set_Address(Street , City , State , Country , PostalCode , ApartmentNumber , UnitNumber);
	}

	//Copy Constructor
	
	/**
	 * @brief Construct a new Address object
	 * 
	 * @param a [Address]
	 */
	Address(const Address &a)
	{
		set_Address(a.Street , a.City , a.State , a.Country , a.PostalCode , a.ApartmentNumber , a.UnitNumber);
	}

    // Setter methods
	/**
	 * @brief Set the Address object
	 * The `set_Address` method is a setter method that allows you to set all the member variables of the `Address` class at once.
	 * This method provides a convenient way to set all the address details in one function call.
	 *
	 * @param Street [string] : the name of the street
	 * @param City [string]: the name of the city
	 * @param State [string]: state / Province
	 * @param Country [string]: Country Name
	 * @param PostalCode [string]: Full Postal Code
	 * @param ApartmentNumber [int]: Default : 00
	 * @param UnitNumber [int]: Default : 00
	 */
	void set_Address(string Street , string City , string State , string Country , string PostalCode , int ApartmentNumber = 0 , int UnitNumber = 0){
		setStreet(Street);
		setCity(City);
		setState(State);
		setCountry(Country );
		setPostalCode(PostalCode);
		setApartmentNumber(ApartmentNumber);
		setUnitNumber(UnitNumber);
	}

	/**
	 * @brief Set the Street object
	 *
	 * @param Street [String] : house + street name
	 */
    void setStreet(string Street) {
		//The code snippet is a part of the `setStreet` method in the `Address` class.
		//It is used to remove any extra spaces or commas from the `Street` string before assigning it to the `Street` member variable.
		string actualStreet;
		for(int i = 0 ; Street[i] ; i++){
			if(Street[i] == ',' or (Street[i] == ' ' and Street[i+1] == ',')){
                continue; // Check again spaces not working correctly.
			}
			else{
                actualStreet += Street[i];
			}
		}
        this->Street = actualStreet;
    }

	/**
	 * @brief Set the City object
	 *
	 * @param City : the name of the City
	 */
    void setCity(string City) {
		this->City = City;
    }

	/**
	 * @brief Set the State object
	 *
	 * @param State : State / Province Name
	 */
    void setState(string State) {
        this->State = State;
    }

	/**
	 * @brief Set the Postal Code object
	 *
	 * @param PostalCode : Full Postal Code.
	 */
    void setPostalCode(string PostalCode) {
        this->PostalCode = PostalCode;
    }

	/**
	 * @brief Set the Country object
	 *
	 * @param Country : The Name of the Country.
	 */
	void setCountry(string Country) {
		this->Country= Country ;
	}

	/**
	 * @brief Set the Apartment Number object
	 *
	 * @param ApartmentNumber : Default 0
	 */
	void setApartmentNumber(int ApartmentNumber){
		this->ApartmentNumber = ApartmentNumber;
	}

	/**
	 * @brief Set the Apartment Number object
	 * 
	 * @param ApartmentNumber [string] : apartment number
	 * @throws "invalid number exception" 
	 */
	void setApartmentNumber(string ApartmentNumber){
		try{
			this->ApartmentNumber = stoi(ApartmentNumber);
		}
		catch(const exception& e){
			throw "ivalid Number. Error: " + string(e.what());
		}
	}

	/**
	 * @brief Set the Unit Number object
	 *
	 * @param UnitNumber : Default 0
	 */
	void setUnitNumber(int UnitNumber){
		this->UnitNumber = UnitNumber;
	}

	/**
	 * @brief Set the Unit Number object
	 * 
	 * @param UnitNumber [string] : unit number
	 * @throws "invalid number exception" 
	 */
	void setUnitNumber(string UnitNumber){
		try{
			this->UnitNumber = stoi(UnitNumber);
		}
		catch(const exception& e){
			throw "ivalid Number. Error: " + string(e.what());
		}
	}

    // Getter methods

    string getStreet() const {
        return Street;
    }

    string getCity() const {
        return City;
    }

    string getState() const {
        return State;
    }

    string getPostalCode() const {
        return PostalCode;
    }

	string getCountry() const{
		return  Country;
	}

	int getApartmentNumber() const{
		return ApartmentNumber;
	}

	int getUnitNumebr() const{
		return UnitNumber;
	}



	/**
	 * @brief The `display()` function is a member function of the `Address` class.
	 * It is used to display the address details on the console.
	 */
	void display() const{
		cout << Street << " , " << City << " , " << State << " , " << Country << " , Postal Code : " << PostalCode << ". Apartment number : " << ApartmentNumber << ". Unit : " << UnitNumber;
	}

	/**
	 * @brief The `toString()` function is a member function of the `Address` class
	 *
	 * @return [string] : It returns a string representation of the address object.
	 */
	string toString() const{
		return string(Street + ", " + City + ", " + State + ", " + Country + ", " + PostalCode + ", " + to_string(ApartmentNumber) + ".Unit: " + to_string(UnitNumber));
	}


    // Overloading the assignment operator
	/**
	 * @brief the assignment operator overload function for the `Address` class
	 *
	 * @param other [Address] : Another Address.
	 * @return const Address reference
	*/
	const Address& operator= (const Address& other) {
        if (this == &other) {
            return *this;
        }
        Street = other.Street;
        City = other.City;
        State = other.State;
		Country = other.Country;
        PostalCode = other.PostalCode;
		ApartmentNumber = other.ApartmentNumber;
		UnitNumber = other.UnitNumber;
        return *this;
    }

    // Overloading the equality operator
	/**
	 * @brief overloading the equality operator (`==`) for the `Address` class.
	 *
	 * @param other [Address] : Another Address
	 * @return true if every attributes are same
	 * @return false otherwise.
	 */
    bool operator== (const Address& other) {
        return (Street == other.Street and
				 City == other.City and
				 State == other.State and
				 PostalCode == other.PostalCode and
				 Country == other.Country and
				 ApartmentNumber == other.ApartmentNumber and
				 UnitNumber == other.UnitNumber );
    }


    // Overloading the inequality operator
	/**
	 * @brief overloading the inequality operator (`!=`) for the `Address` class.
	 *
	 * @param other [Address] : Another Address
	 * @return true if any attributes is different
	 * @return false otherwise.
	 */
    bool operator!= (const Address& other) 
	{
        return (Street != other.Street and
				 City != other.City and
				 State != other.State and
				 PostalCode != other.PostalCode and
				 Country != other.Country and
				 ApartmentNumber != other.ApartmentNumber and
				 UnitNumber != other.UnitNumber );
    }

	friend ostream& operator<<(ostream & , const Address &);
	friend istream& operator>>(istream & , Address &);
};



/**
 * @brief is an overloaded output stream operator (`<<`) for the `Address` class
 *
 * @param obj
 * @return ostream&
 */
ostream &operator<<(ostream &strm, const Address &obj)
{
	strm << obj.Street << " , " << obj.City << " , " << obj.State << " , " << obj.Country << " , "
		 << obj.PostalCode << " , " << obj.ApartmentNumber << " , " << obj.UnitNumber << '\n';
	return strm;
}

/**
 * @brief : The code snippet is using the `getline` function to extract values from the `iss` input string stream and assign them to the corresponding member variables 
 * 			 of the `Address` object `obj`.
 * 
 * @param strm [input_stream] : 
 * @param obj [Address] : the address to be read
 * @return istream& [input_Stream]
 */
istream& operator>>(istream & strm, Address &obj)
{
	string line;
    getline(strm, line);
    istringstream iss(line);
    //The code snippet is using the `getline` function to extract values from the `iss` input string stream and assign them to the corresponding member variables 
	// of the `Address` object `obj`.
	getline(iss, obj.Street, ',');
    getline(iss, obj.City, ',');
    getline(iss, obj.State, ',');
    getline(iss, obj.Country, ',');
    getline(iss, obj.PostalCode, ',');
    iss >> obj.ApartmentNumber;
    iss.ignore(); // Ignore the comma separator
    iss >> obj.UnitNumber;
    return strm;
}