#include "./node.h"
#include <iostream>
using namespace std;

/**********************
 *Function: Node::Node()
 *Purpose: Default node constructor.
 * *******************/
Node::Node(){
	val = 0;
	next = NULL;
}
/**********************
 *Function: Node::Node()
 *Purpose: Default node constructor.
 * *******************/
Node::Node(int val){
	this->val = val;
	next = NULL;
}

