#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

	//void getRoot();

private:


	Node* root;

	//helper methods

	bool emptyNode(Node*);


	//helper method for copy constructor
	void copyTree(Node*, const BSTree& rbt);


	//helper method for destructor
	void postOrderDestruct(Node*);	


	//helper method for insert
	Node* setNode(Node*, Node*);


	//helper methods for remove
	Node* findMaxLeft(Node*);
	Node* deleteCustomer(Node*, Customer);


	//helper method for search 
	bool preOrderSearch(Node*, Customer&);


	//helper method for range search
	void rangeSearchFind(Node*, Customer&, Customer&, vector<Customer>&);


	//helper method for print function
	void inOrderTraversal(Node*);




};

#endif
