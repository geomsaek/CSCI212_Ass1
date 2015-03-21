/****
*
*	Name:			Matthew Saliba
*	Desc:			List manager process class and string list class defs
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

// class to and manage the process list nodes
class list;
typedef list * list_pointer;

struct node;
typedef node * nptr;

// node to hold process info
struct node {
	string uid;
	int pid;
	int ppid;
	string c;
	string stime;
	string tty;
	string time;
	string location;

	nptr next;
};

// struct to hold a string value in a list

struct string_node;
typedef string_node * snptr;

struct string_node {
	string value;
	snptr next;	
};

/***************************************************************************************************
******************************************** STRING CLASS ******************************************
****************************************************************************************************/

// class holds a list of string values in a list
// responsible for receiving unbroken process strings via command input

class string_list {

	public:
		string_list();
		~string_list();
		void insert(string);
		string get_single_value();
		void output_list();
		bool get_cur_increment();
		void reset_cur_pointer();
		
	private:
		snptr pvalues;
		snptr cur;
		int curIncrement;
};

/***************************************************************************************************
******************************************** LIST CLASS ********************************************
****************************************************************************************************/

// class list used to manage a list of nodes

class list {

	// allows the table class to access private members for summary output
	friend class table;

	public:
		// constructor destructors
		list();
		~list();
		
		// formats a string containing the process information
		void format_string(string);
		
		// adds values of the broken string to a process node to include in a list
		void add_values(string[10], string);
		
		// adds a set of individual values to a process node to include in a list
		void add_values_singular(string, int, int, string, string, string, string, string);
		
		// outputs the current list
		void output_list();
		
		// outputs the list with a special output character
		void output_list_char(string);
		
		// outputs a summary of a list
		void list_summary();
		
		// gets the total time of a process
		void get_total_time(int &, int &, int &);
		
		// converts and carries time based on whether the values are over 60
		void convert_int_literal(string, int &, int &, int &);
		
		// outputs a summary of the process nodes of a list
		void summary();
		
		// gets the length of a list
		int list_length();
		
		// gets the uid from head of the list
		string get_uid();
		
		// gets the pid from the head of the list
		int get_pid();
		
		// returns the longest path of a list
		// and stores pid and uid of process with this path
		string get_longest_path(int &, string &);

	private:
		
		// contains a pointer to a list of process nodes
		nptr process;
		// converts time string to hrs, mins, secs
		int convert_time_value(int &);
	
};
