#include "Address.h"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
	fstream filePointer;
	vector<Address> container;
	Address a1;
	a1.set_Address("1446 , Rue Marie Claire" , "Lasalle" , "Quebec" , "Canada" , "H8N-1R9" , 0 , 00);
	container.push_back(a1) ;
	a1.set_Address("815 , 8th Street East" , "Saskatoon" , "Saskatchewan" , "Canada" , "S7H 3E1" , 815 , 205);
	container.push_back(a1);
	a1.set_Address("146 , North Bonnington Ave." , "Scarborough" , "Ontario" , "Canada" , "M1K 1M1" , 0 , 0);
	container.push_back(a1);
	a1.set_Address("66 Lindsay Drive" , "Saskatoon" , "Saskatchewan" , "Canada" , "S7H 3E1" , 0 , 0);
	container.push_back(a1);
    a1.set_Address("8 Lindsey Drive" , "saskatoon" , "Saskatchewan" , "Canada" , "S7H 3E1" , 0 , 0);
    container.push_back(a1);
	filePointer.open("CheckAddressDriver.txt" , ios::out);
	for(int i = 0 ; i < container.size() ; i++){
        filePointer << container[i];
        cout << container[i];
	}
	filePointer.close();
	filePointer.clear();
	container.clear();
	filePointer.open("CheckAddressDriver.txt" , ios::in);
    filePointer >> a1;
    while(!filePointer.eof()){
		try
		{
			cout<<"The address is : "<<a1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		filePointer >> a1;
	}
	filePointer.close();
	return 0;
}
