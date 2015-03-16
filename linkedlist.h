/****
*
*
*
*
*
*****/

#include<iostream>
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
		void convert_int_literal(string, int &, int &, int &);
		void summary();
	
	private:
		
		nptr process;
	
};
