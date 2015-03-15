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


void table::copy_sort_list(const list & object){


	nptr cur = object.process;
	string curUser;
	int returnTotal = 0;

	while(cur->next != NULL){
		curUser = cur->uid;
		returnTotal = hash_convert(curUser);

		cout << returnTotal << endl;
		cur = cur->next;
	}

}

/************

	OUTPUT LIST
		- outputs the current list item

************

bool table::check_user_list(string new_user){

	if(user_id_size == -1){
		user_id_size = 0;
		user_ids[0] = new_user;
	}else {
		for(int i = 0; i < user_id_size; i++){

		}
	}

}
*//
