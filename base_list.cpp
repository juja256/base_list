#include "base_list.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

base_list::node* init_base_list_node(char* data, base_list::node* n) {
	base_list::node* t = new base_list::node;
	t->data = new char[256];
	strcpy(t->data, data);
	t->next = n;
	return t;
}

base_list init_base_list() {
	base_list t;
	t.size = 0;
	t.head=0;
	t.tail=0;
	return t;
}

base_list init_base_list(char* data) {
	base_list t;
	base_list::node* head = init_base_list_node(data, 0);
	t.head = head;
	t.tail = head;
	t.size = 1;
	return t;
}

base_list init_base_list_by_array(char** a, int size) {
	base_list t = init_base_list();
	for (int i=0; i<size; i++)
		push_front(t, a[i]);
	return t;
}

base_list init_base_list_by_file(const char* filename) {
	char* word = new char[256]; 
	ifstream in(filename);
	base_list t = init_base_list();
	while (in >> word) {
		push_front(t, word);
	}
	
	return t;
}

void push_front(base_list& t, char* data) {
	if (t.head==0) {
		base_list::node* head = init_base_list_node(data, 0);
		t.head = head;
		t.tail = head;
	} else {
		base_list::node* new_node = init_base_list_node(data, 0);
		t.tail->next = new_node;
		t.tail = new_node;
	}
	
	t.size++;
}

void insert_after(base_list& t, char* data, int index) {
	base_list::node* tmp = t.head;
	if (t.size <= index) throw std::logic_error("index if out of permissible range");	 
	else {
		for (int i=0; i<index; i++) 
			tmp = tmp->next;
		base_list::node* new_node = init_base_list_node(data, tmp->next);
		tmp->next = new_node;
		if (index == t.size-1) t.tail = new_node;
		t.size++;
	}
}

char* get_element(base_list& t, int index) {
	base_list::node* tmp = t.head;
	if (index >= t.size) throw std::logic_error("accessing to undefined memory\n");
	else {
		for (int i=0; i<index; i++) 
			tmp = tmp->next;
		return tmp->data;
	}
}

void erase_element(base_list& t, int index) {
	base_list::node* tmp = t.head;
	if (index >= t.size) throw std::logic_error("trying to clear undefined memory\n");
	else {
		if (index==0) {
			t.head = tmp->next;
			delete tmp->data;
			delete tmp;
		}
		else if (index == t.size-1) {
			for (int i=0; i<index-1; i++) 
				tmp = tmp->next;
			base_list::node* old = tmp->next;
			tmp->next = 0;
			t.tail = tmp;
		}
		else {
			for (int i=0; i<index-1; i++) 
				tmp = tmp->next;
			base_list::node* old = tmp->next;
			tmp->next = tmp->next->next;
			delete old->data;
			delete old;
		}
		t.size--;
	}
}

void list_dump(base_list& t, std::ostream& s) {
	if (t.size == 0) s << "List is empty.\n";
	else {
		base_list::node* tmp = t.head;
		for (int i=0; i<t.size; i++) {
			s << tmp->data<<"\n";
			tmp = tmp->next;
		}
	}
} 

void clear(base_list& t) {
	static int size = t.size;
	for (int i=0; i < size; i++) {
		erase_element(t, 0);
	}
}