/****
*
*
*
*
*
*****/

#include <iostream>
#include <cstdlib>
#include<string>
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
	hash_index.show_table();
	hash_index.summary();

    return 0;
    
}
