#include<bits/stdc++.h>
#include<string>
using namespace std;

class Address {
private:
    string Street , City ,  State , Country , PostalCode;

public:
    // Default constructor
    Address() {
        Street = "";
        City = "";
        State = "";
        PostalCode = "";
    }

    // Parameterized constructor
    Address(string Street , string City , string State , string Country , string PostalCode) {
       set_Address(Street , City , State , Country , PostalCode);
    }

    // Setter methods

	void set_Address(string Street , string City , string State , string Country , string PostalCode){

	}

    void setStreet(string Street) {
        this->Street = Street;
    }

    void setCity(string City) {
		this->City = City;
    }

    void setState(const string& st) {
        State = st;
    }

    void setPostalCode(const string& pc) {
        PostalCode = pc;
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

    // Overloading the assignment operator
    Address& operator=(const Address& other) {
        if (this == &other) {
            return *this;
        }

        Street = other.Street;
        City = other.City;
        State = other.State;
        PostalCode = other.PostalCode;

        return *this;
    }

    // Overloading the less than operator
    bool operator<(const Address& other) const {
        if (PostalCode < other.PostalCode)
            return true;
        else if (PostalCode == other.PostalCode && City < other.City)
            return true;
        else if (PostalCode == other.PostalCode && City == other.City && Street < other.Street)
            return true;

        return false;
    }

    // Overloading the greater than operator
    bool operator>(const Address& other) const {
        if (PostalCode > other.PostalCode)
            return true;
        else if (PostalCode == other.PostalCode && City > other.City)
            return true;
        else if (PostalCode == other.PostalCode && City == other.City && Street > other.Street)
            return true;

        return false;
    }

    // Overloading the equality operator
    bool operator==(const Address& other) const {
        return (Street == other.Street && City == other.City && State == other.State && PostalCode == other.PostalCode);
    }

    // Overloading the inequality operator
    bool operator!=(const Address& other) const {
        return !(*this == other);
    }
};
