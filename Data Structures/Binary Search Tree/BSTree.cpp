#include "BSTree.h"


BSTree::BSTree()
: root(nullptr)
{ }

BSTree::BSTree(const BSTree & rbt){
	root = nullptr;	//default constructor not called, so set root to nullptr
	copyTree(rbt.root, rbt);


}

//destructor that deletes tree post order
BSTree::~BSTree(){
	postOrderDestruct(root);

}

//insert algorithm either sets the element at the root node
//or it goes left/right recursively depending on the comparison of values
bool BSTree::insert(string x, char y, int z){
	Node* newCustomer = new Node;

	(newCustomer->c).setBalance(z);
	(newCustomer->c).setLastName(x);
	(newCustomer->c).setFirstInitial(y);

	if(emptyNode(root)){


		root = newCustomer;


		return true;
	}

	else if(newCustomer->c <= root->c){

		root->left = setNode(root->left, newCustomer);
	}

	else{

		root->right = setNode(root->right, newCustomer);
	}

	return true;
	
}

//removes a node recursively with helper methods
bool BSTree::remove(string x, char y){
	if(search(x, y)){
		Customer newCustomer(x, y, 0);

		root = deleteCustomer(root, newCustomer);
		return true;
	}
	return false;
	
}


//creates a customer object and compares
//it with the whole tree to find a match
bool BSTree::search(string x, char y){
	Customer cust(x, y, 0);
	return preOrderSearch(root, cust);
}

//creates two customer objects and traverses whole tree to find
//all the customers in range, inclusive
vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a){
	Customer c1(x, y, 0);
	Customer c2(z, a, 0);

	vector<Customer> vec;

	if(emptyNode(root)){
		return vec;
	}

	rangeSearchFind(root, c1, c2, vec);

	return vec;
}

//prints tree in order recursively with helper method
void BSTree::inOrderPrint(){
	inOrderTraversal(root);

}


//HELPER METHODS




//check if entire tree is empty
bool BSTree::emptyNode(Node* currentNode){
	return currentNode == nullptr;
}

//inserts current node and then goes left and right
//starting from the root
void BSTree::copyTree(Node* currentNode, const BSTree& rbt){
	if(emptyNode(currentNode)){
		return;
	}

	Customer temp = currentNode->c;

	string x = temp.getLastName();
	char y = temp.getFirstInitial();
	int z = temp.getBalance();

	insert(x, y, z);

	copyTree(currentNode->left, rbt);
	copyTree(currentNode->right, rbt);
}

void BSTree::postOrderDestruct(Node* currentNode){
	if(emptyNode(currentNode)){
		return;
	}

	postOrderDestruct(currentNode->left);
	postOrderDestruct(currentNode->right);

	delete currentNode;
}

//recursive helper method for insert method
Node* BSTree::setNode(Node* currentNode, Node* newNode){
	if(emptyNode(currentNode)){

		return newNode;
	}

	else if(newNode->c <= currentNode->c){

		currentNode->left = setNode(currentNode->left, newNode);
	}

	else{

		currentNode->right = setNode(currentNode->right, newNode);
	}

	return currentNode;

}

Node* BSTree::deleteCustomer(Node* currentNode, Customer customer){
	if(emptyNode(currentNode)){
		return currentNode;
	}

	else if(customer < currentNode->c){
		currentNode->left = deleteCustomer(currentNode->left, customer);
	}

	else if(customer > currentNode->c){
		currentNode->right = deleteCustomer(currentNode->right, customer);
	}

	//customer equals currentNode
	else{

		//case 1: the node to be deleted has no children
		//so delete node and return nullptr
		if((currentNode->left == nullptr) && (currentNode->right == nullptr)){
			delete currentNode;
			return nullptr;
		}

		//case 2: the node to be deleted has no right child
		//so set the left child to replace the deleted node
		else if(((currentNode->left != nullptr) && (currentNode->right == nullptr))){
			Node* temp = currentNode;
			currentNode = currentNode->left;
			delete temp;
			return currentNode;


		}

		//case 3: the node to be deleted has no left child
		//so set the right child to replace the deleted node
		else if(((currentNode->left == nullptr) && (currentNode->right != nullptr))){
			Node* temp = currentNode;
			currentNode = currentNode->right;
			delete temp;
			return currentNode;
		}

		//case 4: the node to be deleted has both children
		//set the max value in left subtree to replace/override the deleted node
		//recursively call the function to the left side to delete max node we found
		else{
			Node* max = findMaxLeft(currentNode->left);

			currentNode->c = max->c;
			currentNode->left = deleteCustomer(currentNode->left, max->c);
			
		}

	}

	return currentNode;
}

Node* BSTree::findMaxLeft(Node* currentNode){
	//go to right subtree
	if(!emptyNode(currentNode->right)){
		return findMaxLeft(currentNode->right);
	}

	//no children, 
	return currentNode;
}


//recursive helper method for search method
bool BSTree::preOrderSearch(Node* currentNode, Customer& customer){
	if(emptyNode(currentNode)){
		return false;
	}

	if(customer == currentNode->c){
		return true;
	}

	if(customer < currentNode->c){
		return preOrderSearch(currentNode->left, customer);
	} 

	else{
		return preOrderSearch(currentNode->right, customer);
	}

	return false;
	
}

//uses in order traversal
void BSTree::rangeSearchFind(Node* currentNode, Customer& firstCust, Customer& secondCust, vector<Customer>& v){
	if(emptyNode(currentNode)){
		return;
	}

	rangeSearchFind(currentNode->left, firstCust, secondCust, v);

	if(firstCust <= currentNode->c){
		if(currentNode->c <= secondCust){
			v.push_back(currentNode->c);
		}
	}

	rangeSearchFind(currentNode->right, firstCust, secondCust, v);

	return;

}

//recursive helper method for in order traversal print
void BSTree::inOrderTraversal(Node* currentNode){
	if(emptyNode(currentNode)){

		return;
	}

	inOrderTraversal(currentNode->left);


	cout << currentNode->c << endl;
	

	inOrderTraversal(currentNode->right);

}


