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
}

table::~table(){
	
	
}

int table::hash_convert(string key){
	
	int total;
	
	for(int i = 0; key.length(); i++){
		total = total + (int)key[i];
	}
	return total;
	
}