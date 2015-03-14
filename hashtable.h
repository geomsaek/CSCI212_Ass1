/****
*
*
*
*
*
*****/

#include<iostream>
using namespace std;

#include "linkedlist.h"

class table {

	public:
		
		table();
		~table();
		int hash_convert(string);
	
	private:
		list_pointer row[120];
		

};