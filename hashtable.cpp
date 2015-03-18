/****
*
*
*
*
*
*****/

#include<iostream>
#include<string>
#include "hashtable.h"
using namespace std;

// initialise all pointers to NULL;

table::table(){
	for(int i = 0; i < 120; i++){
		row[i] = NULL;
	}
	table_size = 120;
//	user_ids[120] = "";
//	user_id_size = -1;
}

table::~table(){
	
	
}

/************

	OUTPUT LIST
		- outputs the current list item

************/
int table::hash_convert(string key){
	
	int total = 0;
	char set = '\0';
	int temp = 0;

	for(int i = 0; i < key.length(); i++){
		set = key[i];

		temp = static_cast<int>(key[i]);
		if(total == 0){
			total = temp;
		}else {
			total = total + temp;
		}
	}
	return total % table_size;
	
}

/************

	COPY SORT LIST
		- copies a list to the hash table

************/

void table::copy_sort_list(const list & object){

	nptr cur = object.process;
	string curUser;
	int returnTotal = 0;

	while(cur->next != NULL){
		curUser = cur->uid;
		returnTotal = hash_convert(curUser);
		append_item(returnTotal, cur);

		cur = cur->next;
	}
}

/************

	APPEND ITEM
		- adds list node to key in array

************/

void table::append_item(int index, nptr & node){

	// create the new list class if there is not a list at the current key value of the table
	if(row[index] == NULL){
		row[index] = new list();
	}
	// add the values to the list. the nested class will handle this
	row[index]->add_values_singular(node->uid, node->pid, node->ppid, node->c, node->stime, node->tty, node->time, node->location);

}

/************

	SHOW TABLE
		- displays the keys and table lists

************/

void table::show_table(){

	for(int i = 0; i < 120; i++){
		if(row[i] != NULL){
			cout << endl;
			//cout << "****************************************************************************************************************************************************************************************************" << endl;
			cout << "UID" << "\t\t" << "PID" << "\t\t" << "PPID" << "\t\t" << "C" << "\t\t" << "STIME" << "\t\t" << "TTY" << "\t\t" << "TIME" << "\t\t" << "LOCATION" << endl;
			row[i]->output_list_char("\t\t");
			//cout << "****************************************************************************************************************************************************************************************************" << endl;
			cout << endl;
		}

	}

}

/************

	SUMMARY
		- outputs a summary of each list

************/

void table::summary(){

	int processCount = 0;
	string curLong = "";
	int tempLong = 0;
	string retLong = "";
	int long_pid = 0;
	string long_uid = "";

	int greatLength = 0;
	string lengthUser = "";

	int leastLength = 9999;
	string leastUser = "";

	for(int i = 0; i < 120; i++){
		if(row[i] != NULL){

			row[i]->list_summary();
			retLong = row[i]->get_longest_path();
			if(retLong.length() > tempLong){
				tempLong = retLong.length();
				curLong = retLong;
				long_pid = row[i]->get_pid();
				long_uid = row[i]->get_uid();
			}
			processCount = processCount + 1;
			if(row[i]->list_length() > greatLength){
				greatLength = row[i]->list_length();
				lengthUser = row[i]->get_uid();
			}
			if(row[i]->list_length() < leastLength){
				leastLength = row[i]->list_length();
				leastUser = row[i]->get_uid();
			}

		}
	}
	cout << "Statistical Summary" << endl;
	cout << "==================" << endl;
	cout << "There are a total of " << processCount << " processes in the process table." << endl;
	cout << endl;
	cout << "User " << lengthUser << " has the most processes in the table (count = " << greatLength << ")" << endl;
	cout << "User " << leastUser << " has the least processes in the table (count = " << leastLength << ")" << endl;
	cout << endl;
	cout << "The process with the longest path name is pid " << long_pid << " with the path name " << curLong << " belongong to the " << long_uid << " user" << endl;

}
