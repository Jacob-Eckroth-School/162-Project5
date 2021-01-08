#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "./node.h"
class Linked_List {

	private:
		unsigned int length;
		Node* head;
	public:
		Linked_List();
		int get_length();
		void print();
		void clear();
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int, unsigned int);
		void sort_ascending();
		void sort_descending();
		void delete_next( Node*);
		Node* merge_sort_ascending(Node*,int);
		Node* selection_sort_descending(Node*);
		Node* merge_lists(Node*,Node*);
		int count_primes();
		void swapNodes(Node*&,Node*,Node*);
};



#endif
