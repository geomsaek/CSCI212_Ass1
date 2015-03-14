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
//	string current_processes[2000];
	string temp;
	snptr node  = NULL;
	snptr tempNode = NULL;
	snptr cur = NULL;
	
	while (getline(cin, temp)) {
		if(node == NULL){
			node = new string_node;
			node->value = temp;
			node->next = NULL;
		}else {
			tempNode = new string_node;
			tempNode->value = temp;
			tempNode->next = NULL;
			cur = node;
			while(cur->next != NULL){
				cur = cur->next;
			}
			cur->next = tempNode;
			tempNode = node;
			
		}
		
	//	current_processes[counter] = temp;

	}
	
	/*
		cout << temp << endl;	
		for(int i = 0; i < temp.length(); i++){

			cout << temp[i] << " -- " << (int)temp[i] << endl;

		}*/
		
		cur = node;
		while(cur->next != NULL){
			if(counter < 10){
			cout << cur->value << endl;
						}
			cur = cur->next;

					counter++;
		}

    return 0;
    
}