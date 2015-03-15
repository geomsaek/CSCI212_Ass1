/****
*
*
*
*
*
*****/

#include<iostream>
#include<string>
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
 	temp->stime = process_array[3];
 	temp->tty = process_array[4];
 	temp->time = process_array[5];
 	temp->cmd = process_array[6];
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

	OUTPUT LIST
		- outputs the current list item

************/
void list::output_list(){

	if(process != NULL){	
		nptr cur = process;
	
		while(cur->next != NULL){
			cout << cur->uid << endl;
			cout << cur->ppid << endl;
			cout << cur->stime << endl;
			cout << cur->tty << endl;
			cout << cur->time << endl;
			cout << cur->cmd << endl;
			cout << cur->location << endl;

			cur = cur->next;
			cout << endl;
			cout << endl;
		}
	}
	
}
