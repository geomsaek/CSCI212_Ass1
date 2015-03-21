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

class list;
typedef list * list_pointer;

struct node;
typedef node * nptr;

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

struct string_node;
typedef string_node * snptr;

struct string_node {
	string value;
	snptr next;	
};

/***************************************************************************************************
******************************************** STRING CLASS ******************************************
****************************************************************************************************/

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

class list {

	friend class table;

	public:
		list();
		~list();
		void format_string(string);
		void add_values(string[10], string);
		void add_values_singular(string, int, int, string, string, string, string, string);
		void output_list();
		void output_list_char(string);
		void list_summary();
		void get_total_time(int &, int &, int &);
		void convert_int_literal(string, int &, int &, int &);
		void summary();

		int list_length();
		string get_uid();
		int get_pid();
		string get_longest_path(int &, string &);

	private:
		
		nptr process;
		int convert_time_value(int &);
	
};
