/****
*
*
*
*
*
*****/

#include<iostream>
using namespace std;

#include "linkedlist.h"

class table {

	public:
		
		table();
		~table();
		int hash_convert(string);
		void copy_sort_list(const list &);
		void show_table();

	private:

		int table_size;
//		int user_id_size;
//		string user_ids[120];
		list_pointer row[120];
		
		void append_item(int index, nptr & node);
//		bool check_user_list(string);


};
