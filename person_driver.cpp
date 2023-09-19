#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include "Person.h"

using namespace std;

int main()
{
    cout << "strarted" << endl;
	Person p1("Maharaj Teertha Deb", "57131115", "1446 , Rue Marie Claire", "Lasalle", "Quebec", "Canada", "H8N-1R9", 0, 0, 4, 8, 2001, 'M', "6399941386", "teertha.deb579@gmail.com");
	Person p2("Boishakhi Debi", "571e1115", "25 , College Road", "Sreemangal", "Sylhet", "Bangaldesh", "3210", 0, 0, 12, 06, 2001, 'F', "+8801975379990", "boishakhi.debi@gmail.com");
	Person p3("ABCD", "EFGLKJOIJLKJLKJOM54", "897 , linkedinPark", "IJKL", "MNOP", "QRAT", "879lkj", 0, 0, 5, 6, 2018, 'M', "+876416321", "jhkkjhjkl@hotmail.com");
	vector<Person> container;
	cout << "declared the persons";
	container.push_back(p1);
	container.push_back(p2);
	container.push_back(p3);
	cout << "Stored into the container";
    fstream outfile ;
	outfile.open("try_person.txt" , ios::out);
	cout << "file was open for writing";
	try{
		for(int i = 0 ; i < container.size() ; i++){
			outfile.write(reinterpret_cast<char *> (&container[i]) , sizeof(container[i]));
			cout << container[i];
		}
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	outfile.close();
	getch();
	system("cls");
	fstream infile;
	infile.open("try_person.txt" , ios::in);
	Person temp;
	try{
		while(!infile.eof()){
			infile.read(reinterpret_cast<char *> (&temp) , sizeof(temp));
			try{
       			temp.print_formatted_info_for_person();
				getch();
				system("cls");
    		}
			catch (string message){
				cout << "Exception thrown while trying to print p2 , the message is : " << message << endl;
				getch();
			}
		}
        infile.close();
        cout << "Done reading from file" << '\n';
    }
	catch (string message){
        cout << "Exception thrown while trying to read and the message is : " << message << endl;
        getch();
	}
    return 0;
}
