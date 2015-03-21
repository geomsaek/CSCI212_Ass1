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

/****

	Class manages the hash table and output of summaries
		- contains a nest class pointer to the list class, which is used to
		manage the lists for each process
****/

class table {

	public:
		
		// constructors and destructors
		table();
		~table();
		
		// converts the string to a value in the hash table
		int hash_convert(string);
		
		// copies existing list object to a row in the hash table
		void copy_sort_list(const list &);
		
		// shows the current table processes defined by list items
		void show_table();
		
		// calls the summary function of the list class to output a summary for each process list
		void summary();

	private:
		// holds the table size;
		int table_size;
		// pointer to a list class that holds the process list
		list_pointer row[120];
		
		// appends a new node to a list
		void append_item(int index, nptr & node);

};
