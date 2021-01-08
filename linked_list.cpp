#include "./linked_list.h"
#include <cassert>
#include <iostream>
using namespace std;
/**********************
 *Function: Linked_List::Linked_List()
 *Purpose: Default Linked_List constructor
 * *******************/
Linked_List::Linked_List(){
	length = 0;
	head = NULL;
}
/**********************
 *Function: Linked_List::count_primes()
 *Purpose: Counts the amount of primes that are in a linked list. Returns that number.
 * *******************/
int Linked_List::count_primes(){
	Node* currentnode = head;
	int primecount = 0;
	while(currentnode != NULL){
		if(currentnode->val <= 1){ //negatives, 1 and 0 can't be prime.
			currentnode = currentnode->next;
			continue;
		}else{
			bool isprime;
			for(int i = 2; i < currentnode->val; i++){
				if( currentnode->val % i ==0){ //if it's divisible by any number before it 2 or greater, then it is not prime.
					isprime = false;
					break;
				}else{
					isprime = true;
				}
			}
			if(isprime || currentnode->val ==2){
				primecount++;
				isprime = false;
			}
		}
		currentnode = currentnode->next;//check the next node.
	}
	return primecount;
}
/**********************
 *Function: Linked_List::get_length()
 *Purpose: Getter that returns the length of the linked_list
 * *******************/
int Linked_List::get_length(){
	return length;
}
/**********************
 *Function: Linked_List::print()
 *Purpose: Prints all the values within the linked list.
 * *******************/
void Linked_List::print(){
	Node* currentnode = head;
	cout<<"Your linked list:";
	while(currentnode!= NULL){ //when we're not at the end of the list.
		cout<<currentnode->val<<" ";
		currentnode = currentnode->next;
	}
	cout<<endl;
}
/**********************
 *Function: Linked_List::push_front(int)
 *Purpose: Adds a new node onto the front of the linked list with newvalue as the value.
 * *******************/
unsigned int Linked_List::push_front(int newvalue){
	Node *new_node = new Node(newvalue);
	new_node->next = head;
	head = new_node;
	length++;
	return length;
}

/**********************
 *Function: Linked_List::push_back(int)
 *Purpose: Adds a new node to the end of the linked list with newvalue as the value.
 * *******************/
unsigned int Linked_List::push_back(int newvalue){
	Node *new_node = new Node(newvalue);
	if(length == 0){
		head = new_node;
	}else{
		Node* tail_node = head;
		while(tail_node->next != NULL){
			tail_node = tail_node->next;
		}
		tail_node->next = new_node;
	}
	length++;
	return length;
}
/**********************
 *Function: Linked_List::insert(int,unsigned int)
 *Purpose: Inserts a node with value newvalue at the location in the linked list. Asserts to make sure that the value is not out of the range of the linked list.
 * *******************/
unsigned int Linked_List::insert(int newvalue, unsigned int location){
	assert(location <= length);	
	Node *new_node = new Node(newvalue);

	Node* currentnode = NULL;
	Node *nextnode = head;

	for(int i = 0; i < location; i++){
		currentnode = nextnode;
		nextnode = nextnode->next;
	}
	if(location ==0){//because we only need to change head if we're changing the first element in the list.
		new_node->next = head;
		head = new_node;
	}else{
		currentnode->next = new_node;
		new_node->next = nextnode;
	}
	length++;
	return length;
}
/**********************
 *Function: Linked_List::clear();
 *Purpose: Calls delete_next on the head of the linked_list.
 * *******************/
void Linked_List::clear(){
	delete_next(head); //recursive call	


}
/**********************
 *Function: Linked_List::delete_next(Node*)
 *Purpose: Recursively deletes every node in the list backwards, once it reaches a null pointer i.e. the end of the list.
 * *******************/
void Linked_List::delete_next(Node* currentnode){

	if(currentnode->next != NULL){//if we're not at the end of this list.

		delete_next(currentnode->next); //call this function on the next node.
	}
	if(currentnode != NULL){ //if the list doesn't have 0 elements in it.

		delete currentnode; //delete the memory	
	}
}
/**********************
 *Function: Linked_List::sort_ascending()
 *Purpose: Calls the recursive merge sort using the head node and passing in the length.
 * *******************/
void Linked_List::sort_ascending(){
	head = merge_sort_ascending(head,length);
}
/**********************
 *Function: Linked_List::merge_sort_ascending(Node*, int)
 *Purpose: Recursively merge sorts the linked list in ascending values.
 * *******************/
Node* Linked_List::merge_sort_ascending(Node* head, int length){

	if(length == 1){//it's sorted!

		return head;
	}
	int left_length = length/2; //left length will be the smaller one
	int right_length = length-left_length; //makes sure the right length and the left length add up to the total.

	Node* left = head; //the head to the left node is just the start of the list.

	for(int i = 0; i < left_length-1; i++){

		head = head->next; //we can change head since we already kept track of it in the left.
	}

	Node* right = head->next; //sets the right node.
	head->next = NULL;//breaking chain



	left = merge_sort_ascending(left, left_length);//sorts the left list.
	right = merge_sort_ascending(right,right_length);//sorts the right list.

	return merge_lists(left,right);//returns the two lists combined.
}
/**********************
 *Function: Linked_List::merge_lists(Node*, Node*)
 *Purpose: Combines 2 lists, when sorting from lowest to highest of left and right lists, returns the head of the newly created list of nodes.
 * *******************/
Node* Linked_List::merge_lists(Node* left, Node* right){
	/*cout<<"\nLeft list:";
	  Node* left_temp = left;
	  Node* right_temp = right;
	  while(left_temp !=NULL){
	  cout<<left_temp->val<<" ";
	  left_temp = left_temp->next;
	  }
	  cout<<"\nRight list:";
	  while(right_temp != NULL){
	  cout<<right_temp->val<<" ";
	  right_temp = right_temp->next;    			//uncomment for error handling
	  }*/

	Node* new_node=NULL;
	Node* temp = NULL;
	while(left!= NULL && right != NULL){//while we're not at the end of either list.
		if(new_node == NULL){ //if it's the first node in the list we need to change the head.
			if(left->val < right->val){ 
				new_node = left;
				temp = new_node;
				left = left->next;	
			}else{
				new_node = right;
				temp = new_node;
				right = right->next;
			}
		}else{ //if we're past the first node and don't need to care about the head anymore.
			if(left->val < right->val){
				temp->next = left;
				temp = temp->next;
				left = left->next;
			}else{
				temp->next = right;
				temp = temp->next;
				right = right->next;
			}
		
		}
	}
	if(left==NULL){ //Whichever list we reached the end of first, we point the last element of temp to the rest of the other list.
		temp->next = right;
	}else{
		temp->next = left;
	}
	/*if(left==NULL && new_node == NULL){ //uncomment for error handling
	  new_node = right;
	  }else if(right==NULL && new_node == NULL){
	  new_node = left;


	  right_temp = new_node;
	  cout<<"\nFull list:";
	  while(right_temp != NULL){
	  cout<<right_temp->val<<" ";
	  right_temp = right_temp->next;
	  }
	  */
	return new_node; //return the head to the merged list.
}
/**********************
 *Function: Linked_List::sort_descending()
 *Purpose: Calls the recursive selection sort using the head as a parameter.
 * *******************/
void Linked_List::sort_descending(){
	head = selection_sort_descending(head);
}
/**********************
 *Function: Linked_List::selection_sort_descending(Node*)
 *Purpose: Recursive selection sort.
 * *******************/
Node* Linked_List::selection_sort_descending(Node* head){
	if(head->next == NULL){ //if we're at the end of the list.
		
		return head;
	}
	
	Node* max = head;//to start off.
	Node* beforeMax = NULL; //to start off
	Node* ptr = head;//node that we'll move around so we keep track of head.
	
	while(ptr->next != NULL){
		if(max->val < ptr->next->val){ //finding the max value and keeping track of the ptr before max.
			max = ptr->next;
			beforeMax = ptr;
		}
		ptr = ptr->next;
	}
	if(max!= head){	//if it's not already sorted correctly
		swapNodes(head,max,beforeMax);	//swap the head, and the max node
	}
	head->next = selection_sort_descending(head->next); //do the next node.
	return head;
}



/**********************
 *Function: Linked_List::swap_nodes(Node*&,Node*,Node*)
 *Purpose: swaps 2 nodes in a linked list.
 * *******************/
void Linked_List::swapNodes( Node*& head,  Node* max, Node* beforeMax)  //swaps nodes without losing memory
{  
	Node* temp_head = head;
	head = max;
	beforeMax->next = max->next; 
	head->next = temp_head;	
} 

