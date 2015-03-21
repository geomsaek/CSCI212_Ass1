/****
*
*	Name:			Matthew Saliba
*	Desc:			List manager process class and string list class
*	Date Mod:		22nd March 2015
*	Task:			Assignment 1
*	Student #:		3284165
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

	snptr current_lister = NULL;
	snptr temp = new string_node;
	temp->value = new_value;
	temp->next = NULL;

	if(pvalues == NULL){
		pvalues = temp;
	}else {
		current_lister = pvalues;
		while(current_lister->next != NULL){
			current_lister = current_lister->next; 
		}
		current_lister->next = temp;
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
	
	snptr current_lister = pvalues;
	
	while(current_lister->next != NULL){
		cout << current_lister->value << endl;
		cur = current_lister->next;
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

	nptr temp = NULL;
	
	if(process != NULL){
		nptr temp = process;
		while(process->next != NULL){
		
			temp = process;
			process = process->next;
		
			delete temp;
		
		}
		process = NULL;
	}
	return;
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
	int slash_counter = 0;

	for(int i = 0; i < server_list.length(); i++){
			singular = server_list[i];
			if(server_list[i] == '/'){
				if(slash_counter >1){
					slash = true;
				}
				slash_counter++;
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
				slash_counter = 0;
			}
	}

 	add_values(process_array, temp);
 	delete [] process_array;
	
}

/************

	FORMAT STRING
		- add values to node in linked list

************/
void list::add_values(string process_array[10], string locationVal){
	
	nptr temp = new node;

	string temp_holder = process_array[1];
	char int_char_convert[100];
	char clear_chars[100] = { '\0' };
	
	if(locationVal != "<defunct>"){
	
		strcpy(int_char_convert,temp_holder.c_str());
		temp->uid = process_array[0];
	
		temp->pid = atoi(int_char_convert);
	
		temp_holder = process_array[2];
		strcpy(int_char_convert,clear_chars);
		strcpy(int_char_convert,temp_holder.c_str());

		temp->ppid = atoi(int_char_convert);
	
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
		int carry = 0;
		
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
		
		carry = convert_time_value(totalSec);
		if(carry != -1){
			totalMin = totalMin + carry;
			carry = convert_time_value(totalMin);
		}
		if(carry != -1){
			totalHour = totalHour + carry;
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

	GET TOTAL TIME
		- gets the total time of a list and associates this to referenced values

************/

void list::get_total_time(int &totalHour, int & totalMin, int & totalSec){

	nptr cur = process;
	int carry = -1;

	while(cur->next != NULL){
		convert_int_literal(cur->time, totalHour, totalMin, totalSec);
		cur = cur->next;
	}

	carry = convert_time_value(totalSec);
	if(carry != -1){
		totalMin = totalMin + carry;
		carry = convert_time_value(totalMin);
	}
	if(carry != -1){
		totalHour = totalHour + carry;
	}

	return;

}


/************

	CONVERT INTEGER
		- converts two characters into literal numeric values

************/

void list::convert_int_literal(string time, int & totalHour, int & totalMin, int & totalSec){

	string timeString = "";
	int tempLen = 0;
	int up_hr = 0, up_min = 0, up_sec = 0;

	int secIndex = time.length()-2;
	timeString = time;
	tempLen = time.length();

	up_sec = atoi (&timeString[secIndex]);

	int minIndex = time.length() - 5;
	up_min = atoi(&timeString[minIndex]);

	int hrIndex = time.length() - time.length();
	up_hr = atoi(&timeString[hrIndex]);

	totalSec = totalSec + up_sec;
	totalMin = totalMin + up_min;
	totalHour = totalHour + up_hr;

}

/************

	BASE TIME CONVERTER
		- converts a number into a value of of 60

************/

int list::convert_time_value(int & value){

	int time_convert = 0;
	int remain = 0;

	if(value > 60){
		time_convert = value / 60;
		remain = time_convert * 60;

		if((value - remain) > 0){
			value = value - remain;
			return time_convert;
		}else {
			value = value - remain;
			return -1;
		}

	}else {
		return -1;
	}
}


/************

	GET LIST LENGTH
		- gets the current length of a list item

************/

int list::list_length(){

	if(process != NULL){
		nptr cur = process;
		int counter = 0;
		while(cur->next != NULL){
			counter = counter + 1;
			cur = cur->next;
		}
		return counter;

	}else {
		return 0;
	}

}

/************

	GET USER ID
		- returns the name of the user id of the list

************/

string list::get_uid(){

	if(process != NULL){
		return process->uid;
	}else {
		return "";
	}
}

/************

	RETURNS PID
		- returns current pid

************/

int list::get_pid(){
	if(process != NULL){
		return process->pid;
	}else {
		return -1;
	}
}

/************

	GET THE LONGEST PATH OF THE LIST
		- returns the path with the longest length

************/

string list::get_longest_path(int & long_pid, string & long_uid){

	if(process != NULL){
		nptr cur = process;
		int longest = 0;
		string tempLong = "";

		while (cur->next != NULL){
			if(cur->location.length() > longest){
				longest = cur->location.length();
				tempLong =cur->location;
				long_pid = cur->pid;
				long_uid = cur->uid;
			}
			cur = cur->next;
		}
		return tempLong;
	}else {
		return "";
	}
}
