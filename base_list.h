#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <cstring>
#include <ostream>

struct base_list {
	struct node { char* data; node* next; } *head, *tail;
	int size;
};

base_list::node* init_base_list_node(char* data, base_list::node* n);
// initialization of a node

base_list init_base_list(char* data);
// initialization of list with head

base_list init_base_list();
// initialization of empty list

base_list init_base_list_by_array(char** a, int size);
// initialization of list by array

base_list init_base_list_by_file(const char* filename);
// initialization of list by file

void push_front(base_list& t, char* data);
// push new head to list

void insert_after(base_list& t, char* data, int index);
// insert new element after existing element

char* get_element(base_list& t, int index);
// get element by index

void erase_element(base_list& t, int index);
// delete element from list

void list_dump(base_list& t, std::ostream& s);
// output all elements in list 

void clear(base_list& t);
// delete all elements in list

#endif
