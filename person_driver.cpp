#include<bits/stdc++.h>
#include "Person.h"

using namespace std;

int main()
{
   Person p1("Maharaj Teertha Deb" , "57131115" , "1446 , Rue Marie Claire" , "Lasalle" , "Quebec" , "Canada" , "H8N-1R9" , 0 , 0 , 4 , 8 , 2001 , 'M' , "6399941386" , "teertha.deb579@gmail.com");
   p1.print_formatted_info_for_person();
   
   try{
	p1.set_user_name("Maharaj Teerth4 D3B");
   }
   catch(string message){
	cout <<"Error: " <<  message << '\n';
   }
   

}
