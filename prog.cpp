/************************
 * Program: linked_list.cpp
 * Author: Jacob Eckroth
 * Date: 3/5/2020
 * Description: This program creates a linked_list data structure and allows the user to add numbers to it, then sort it accordingly via merge sort ascending or selection sort descending
 * Input: User inputs for number, and selections for sorts.
 * Output: Numbers in the linked list sorted.
 * **********************/

#include <iostream>
#include "./node.h"
#include "./linked_list.h"
#include <chrono> //for tracking algorithm time
using namespace std;
using namespace std::chrono; //for tracking algorithm time

int get_number();
bool more_numbers();
char sort_type();
bool runagain();
void print_time(std::chrono::time_point<std::chrono::system_clock>);//because apparently you can't have auto be your function parameter.
/**********************
 *Function: main()
 *Purpose: runs the program. Yay! 
 * *******************/
int main(){

	do{
		Linked_List link;
		bool again = false;
		do{
			link.push_back(get_number());
			again = more_numbers();
		}while(again);
		//link.push_front(125);
		//link.insert(-123,0); //uncomment these lines if you want to test the push_front and insert functionality of the linked_list.
		link.print();
		char sorting = sort_type();
		auto start = high_resolution_clock::now(); //sets the start time before the sort.
		(sorting == 'a')? link.sort_ascending() : link.sort_descending();
		print_time(start);
		link.print();
		cout<<"Your list has "<< link.count_primes()<<" prime number(s) in it."<<endl;
		link.clear();
	}while(runagain());
	return 0;
}
/**********************
 *Function: print_time(std::chrono::time_point<std::chrono::system_clock>)
 *Purpose: Prints the difference between the start time passed to the function and the current time, which is calcuated in this function.
 * *******************/
void print_time(std::chrono::time_point<std::chrono::system_clock> start){
	auto stop = high_resolution_clock::now(); //sets the end time after the algorithm.
	auto duration = duration_cast<nanoseconds>(stop-start); //calculates the duration.
	cout<<"This sort took "<<duration.count()<< " nanoseconds."<<endl; //prints the duration.

}
/**********************
 *Function: runagain()
 *Purpose: Asks if the user wants to make another linked list
 * *******************/
bool runagain(){
	cout<<"Do you want to do this again (y or n)? ";
	bool valid = false;
	string input = "";
	do{
		getline(cin,input);
		if(input != "y" && input != "n"){
			valid = false;
			cout<<"Invalid. Please enter y or n:";
		}else{
			valid = true;
		}
	}while(!valid);
	return (input =="y")?  true : false;
}

/**********************
 *Function: sort_type()
 *Purpose: Asks the user whether they want to sort ascending or descending, and returns the value that they choose.either a or d.
 * *******************/
char sort_type(){
	cout<<"Sort ascending or descending (a or d)? ";
	string user_input = "";
	bool valid = false;
	do{
		getline(cin,user_input);
		if(user_input != "a" && user_input != "d"){
			valid = false;
			cout<<"Invalid, please enter either a or d:";
		}else{
			valid = true;
		}

	}while(!valid);
	return user_input[0];
}

/**********************
 *Function: get_number()
 *Purpose: Returns the number that the user enters, error handles to make sure it's a valid number.
 * *******************/
int get_number(){
	cout<<"Enter a number: ";
	string user_input = "";;
	bool valid;
	do{
		valid = false;
		getline(cin,user_input);
		for(int i = 0; i < user_input.length(); i++){
			if(!(user_input[i] >= '0' && user_input[i] <= '9')){
				if(!(i == 0 && user_input[i] == '-')){ //if the first character is a minus sign.
					valid = false; //if its not a number.
					break;
				}
			}
			valid = true;
		}
		if(!valid){
			cout<<"Invalid input, please enter an integer: ";
		}
	}while(!valid);
	return stoi(user_input);
}
/**********************
 *Function: more_numbers()
 *Purpose: Asks if the user wants to enter more numbers, returns true if they do, false if they don't.
 * *******************/
bool more_numbers(){
	cout<<"Do you want another num(y or n):";
	bool valid = false;
	string userinput = "";
	do{
		getline(cin,userinput);
		if(userinput[0] != 'y' && userinput[0] != 'n'){
			valid = false;
			cout<<"Invalid input, please enter y or n:";
		}else{
			valid = true;
		}
	}while(!valid);
	if(userinput[0] == 'y'){
		return true;
	}
	return false;
}

