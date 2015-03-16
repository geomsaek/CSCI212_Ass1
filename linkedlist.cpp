/****
*
*
*
*
*
*****/

#include<iostream>
#include<string>
#include<cstdlib>
#include <stdlib.h>
#include "linkedlist.h"
using namespace std;


/***************************************************************************************************
******************************************** STRING CLASS ******************************************
****************************************************************************************************/

/************ CONSTRUCTOR  ************/

string_list::string_list(){
	pvalues = NULL;
	cur = NULL;
	curIncrement = -1;
}

/************ DESTRUCTOR  ************/

string_list::~string_list(){

	if(pvalues != NULL){	
		snptr temp = pvalues;
		while(pvalues->next != NULL){
		
			temp = pvalues;
			pvalues = pvalues->next;
	
			delete temp;
		}
		pvalues = NULL;
	}
	return;
}

/************ INSERT FUNCTION  ************/

void string_list::insert(string new_value){

	snptr temp = new string_node;
	temp->value = new_value;
	temp->next = NULL;
	
	
	if(pvalues == NULL){
		pvalues = temp;
	}else {
		snptr cur = pvalues;
		while(cur->next != NULL){
			cur = cur->next; 
		}
		cur->next = temp;
		temp = pvalues;
	}

	return;
}

/************  
	
	GET SINGLE VALUE
		- gets the next value in the list. 
		  Returns false if there it has reached the end of the list
		  
************/

string string_list::get_single_value(){
	
	if(cur== NULL){
		cur = pvalues;
		curIncrement = true;
		return cur->value;
	}else {
		if(cur->next != NULL){
			cur = cur->next;
			curIncrement = true;
			return cur->value;
		}else {
			cur = cur->next;
			curIncrement = false;
			return "";
		}
	}

}

/************ 
	- GET CUR INCREMENT
		checks the status of whether the
		node pointer has a value or not	
************/

bool string_list::get_cur_increment(){
	return curIncrement;
}

/************ 
	- RESET THE COUNTER POINTER
		resets the current cur pointer to the start of the list
************/

void string_list::reset_cur_pointer(){

	cur = pvalues;
	curIncrement = true;
	
}


/************ OUTPUT LIST ITEMS  ************/

void string_list::output_list(){
	
	snptr cur = pvalues;
	
	while(cur->next != NULL){
		cout << cur->value << endl;
		cur = cur->next;
	}
	
}

/***************************************************************************************************
******************************************** LIST CLASS ********************************************
****************************************************************************************************/

/************ CONSTRUCTOR  ************/

list::list(){
	process = NULL;
}

/************ DESTRUCTOR  ************/

list::~list(){
	
}

/************ 
	
	FORMAT STRING
		- breaks apart a server process string
	
************/

void list::format_string(string server_list){
	
	int counter = 0;
	bool start = false, slash = false;

	string temp;
	string process_array[10];
	char singular = '\0';

	for(int i = 0; i < server_list.length(); i++){
			singular = server_list[i];
			if(server_list[i] == '/'){
				slash = true;
			}

			if(!slash){
				if(!isspace(singular)){
					if(!start){
						start = true;
					}
					if(start){

						if(temp.length() == 0){
							temp = singular;
						}else {
							temp = temp + singular;
						}
					}
				}else {
					if(temp.length() > 0){
						process_array[counter] = temp;
						counter++;
						start =false;
						temp.clear();
					}
				}
			}else {
				temp = temp + singular;
			}
	}

 	add_values(process_array, temp);
	
}

/************

	FORMAT STRING
		- add values to node in linked list

************/
void list::add_values(string process_array[10], string locationVal){
	
	nptr temp = new node;

	temp->uid = process_array[0];
	temp->pid = stoi(process_array[1]);
	temp->ppid = stoi(process_array[2]);
	temp->c = process_array[3];
 	temp->stime = process_array[4];
 	temp->tty = process_array[5];
 	temp->time = process_array[6];
 	temp->location = locationVal;
 	temp->next = NULL;
	
	if(process == NULL){
		process = temp;
	}else {
		nptr cur = process;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = temp;
		temp = process;
	}
	
	return;
}

/************

	FORMAT STRING
		- add values to node in linked list

************/
void list::add_values_singular(string new_uid, int new_pid, int new_ppid, string new_c, string new_stime, string new_tty, string new_time, string new_location){
	
	nptr temp = new node;
	
	temp->uid = new_uid;
	temp->pid = new_pid;
	temp->ppid = new_ppid;
	temp->c = new_c;
 	temp->stime = new_stime;
 	temp->tty = new_tty;
 	temp->time = new_time;
 	temp->location = new_location;
 	temp->next = NULL;
	
	if(process == NULL){
		process = temp;
	}else {
		nptr cur = process;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = temp;
		temp = process;
	}
	
	return;
}

/************

	OUTPUT LIST
		- outputs the current list item

************/
void list::output_list(){

	if(process != NULL){	
		nptr cur = process;
	
		while(cur->next != NULL){
			cout << cur->uid << endl;
			cout << cur->pid << endl;
			cout << cur->ppid << endl;
			cout << cur->c << endl;
			cout << cur->stime << endl;
			cout << cur->tty << endl;
			cout << cur->time << endl;
			cout << cur->location << endl;

			cur = cur->next;
			cout << endl;
			cout << endl;
		}
	}
	
}

/************

	OUTPUT LIST WITH CHARACTER
		- outputs the current list with a spacing character

************/
void list::output_list_char(string space){

	if(process != NULL){	
		nptr cur = process;
	
		while(cur->next != NULL){
			cout << cur->uid << space;
			cout << cur->pid << space;
			cout << cur->ppid << space;
			cout << cur->c << space;
			cout << cur->stime << space;
			cout << cur->tty << space;
			cout << cur->time << space;
			cout << cur->location << endl;

			cur = cur->next;
		}
	}
}

/************

	LIST SUMMARY
		- summarises the information for a given list

************/

void list::list_summary(){

	if(process != NULL){	
		
		nptr cur = process;
		
		int processCounter = 0;
		
		int totalHour = 0, totalMin = 0, totalSec = 0;
		
		string longest = "", curUser = "";
		int long_pid = 0, longLength = 0;
		
		// need to change to reflect collision users
		curUser = process->uid;
		
		while(cur->next != NULL){

			convert_int_literal(cur->time, totalHour, totalMin, totalSec);
			
			if(cur->location.length() > longLength){
				longest = cur->location;
				longLength = cur->location.length();
				long_pid = cur->pid;
			}
			processCounter = processCounter + 1;
			cur = cur->next;
		}
		
		cout << "user " << curUser << endl;
		cout << "=========" << endl;
		cout << endl;
		cout << "User " << curUser << "  has a total of " << processCounter << " processes" << endl;
		cout << "User " << curUser << " has consumed a total of " << totalHour << " hours, " << totalMin << " minutes, and " << totalSec << " seconds of CPU time" << endl;
		cout << "The process id with the longest path name is pid " << long_pid << " " << longest << endl;
		cout << endl;
		cout << endl;
			
	}
}

/************

	CONVERT INTEGER
		- converts two characters into literal numeric values

************/

void list::convert_int_literal(string time, int & totalHour, int & totalMin, int & totalSec){
	
	string timeString = "";
	int tempLen = 0, hourCount = 0, minuteCount = 0, secCount = 0;
	char firstDigit = '\0', secondDigit = '\0', extra = '\0';
	
	string hourTemp="", minTemp="", secTemp="";
	
	timeString = time;
	tempLen = time.length();
	
	int secIndex = time.length()-2;

// gettitng time conversion correct. seems to show seconds correctly through current cnversion
// however minutes seems different
	int secVal = 0;
	secVal = atoi (&timeString[secIndex]);
	
	cout << "TIME: " << time << endl;
	cout << secVal << endl;
	
	int minVal = 0;
	int minIndex = time.length() - 4;
	minVal = atoi(&timeString[minIndex]);
	
	cout << minVal << endl;
	
//	secondDigit = timeString[time.length() -1];
//	cout << firstDigit << secondDigit << endl;

//	secTemp = timeString[time.length()-2] + timeString[time.length() -1];
	
//	cout << secTemp << endl;
	/*	
	firstDigit = timeString[time.length()-5];
	secondDigit = timeString[tempLen-4];
	
	minTemp = firstDigit + secondDigit;
	
	
	firstDigit = timeString[tempLen-8];
	secondDigit = timeString[tempLen-7];

	if(time.length() > 7){
		extra = timeString[tempLen-9];
		hourTemp = extra + firstDigit + secondDigit;
	}else {
		hourTemp = firstDigit + secondDigit;
	}
	
	hourCount = stoi(hourTemp);
	minuteCount = stoi(minTemp);
	secCount = stoi(secTemp);*/
	
	//totalHour = totalHour + hourCount;
	//totalMin = totalMin + minuteCount;
//	totalSec = totalSec + secCount;

}
