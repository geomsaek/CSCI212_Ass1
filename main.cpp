/****
*
*	Name:			Matthew Saliba
*	Desc:			Main Function file
*	Date Mod:		22nd March 2015
*	Task:			Assignment 1
*	Student #:		3284165
*
*****/

#include<iostream>
#include<string>
#include<cstdlib>
#include <stdlib.h>
#include<cstring>
#include "hashtable.h"

using namespace std;
 
int main(){

	int counter = 0;

	string temp;
	string_list read;
	
	table hash_index;
	list cur_users;
	
	while (getline(cin, temp)) {
		
		if(counter > 0){
			read.insert(temp);
		}
		counter++;
	}
	
	temp = "";
	while(read.get_cur_increment() != false){
		temp = read.get_single_value();
		if(temp.length() > 0){
			cur_users.format_string(temp);
		}
	}

	hash_index.copy_sort_list(cur_users);

	hash_index.summary();

    return 0;
    
}
