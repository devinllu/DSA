#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:

	//default constructor, sets both left/right to nullptr
	Node();

	Node* left;
	Node* right;

	Customer c;




	
};

#endif 
