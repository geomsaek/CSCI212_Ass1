/****
*
*	Name:			Matthew Saliba
*	Desc:			Hash Table class function defs
*	Date Mod:		22nd March 2015
*	Task:			Assignment 1
*	Student #:		3284165
*
*****/

#include<iostream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <stdlib.h>
using namespace std;

#include "linkedlist.h"

class table {

	public:
		
		table();
		~table();
		int hash_convert(string);
		void copy_sort_list(const list &);
		void show_table();
		void summary();

	private:

		int table_size;
		list_pointer row[120];
		
		void append_item(int index, nptr & node);

};
