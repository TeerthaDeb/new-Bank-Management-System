#include <bits/stdc++.h>
#include <iostream>
#include "Person.h"
#include "Employee.h"

using namespace std;
int main()
{
	SetConsoleTitle("    ");
	//Date d1;
    d1.setDate(4 , 8 , 2001);
	Employee e1 = new Employee("Maharaj Teertha Deb" , "571e1115" , "1446 , Rue Marie Claire" , "Lasalle" , "Quebec" , "Canada" , "H8N-1R9" , 0 , 0 , 4 , 8 , 2001 , 'M' , "+1 639 994 1386" , "teertha.deb579@gmail.com" , d1 , 15000 , 1 , 1 , "Senior Programmer");

	e1.print_formatted_info_for_Employee();

	printf("\n\n\nthat's the end of the program. press any key to exit...\n\n");
	getch();
	return 0;
}
