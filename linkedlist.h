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
	string stime;
	string tty;
	string time;
	string cmd;

	nptr next;
};

struct string_node;
typedef string_node * snptr;

struct string_node {
	string value;
	snptr next;	
};

class string_list {

	public:
		string_list();
		~string_list();
		void insert();
	
	private:
		snptr pvalues;
		
};

class list {

	public:
		list();
		~list();
		void add_values(string, int, int, string, string, string, string);	
		void summary();
	
	private:
		nptr process;
	

		
};