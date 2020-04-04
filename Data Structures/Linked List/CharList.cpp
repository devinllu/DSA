#include "CharList.h"

CharList::CharList(string s){
	head = NULL;
	tail = NULL;

	for(int i = 0; i < s.length(); i++){
		append(s[i]);
	}

}

CharList::~CharList(){
	
	
	while(!empty() && head != NULL){
		Node* temp = head;
		head = temp->next;
		delete temp;
	}
	
}

bool CharList::empty(){
	return head == NULL;
}

int CharList::size(){
	Node* temp = head;
	int counter = 0;


	while(temp != NULL){
		counter++;

		temp = temp->next;
	}

	return counter;


}

string CharList::toString(){
	string str = "";

	Node* temp = head;

	while(temp != NULL){
		str += temp->elem;

		temp = temp->next;

	}

	return str;
}

void CharList::append(char c){
	Node* n = new Node;
	n->elem = c;
	
	if(empty()){
		n->next = NULL;
		n->prev = NULL;

		head = n;	
		tail = n;
	}

	else{

		n->next = NULL;
		n->prev = tail;

		//linking in node n
		tail->next = n;
		tail = n;
	}



}

void CharList::append(char c, char d){	
	append(c, d, 1);
}

void CharList::append(char c, char d, int n){

	Node* temp = head;
	Node* new_node = new Node;
	int counter = 0;



	new_node->elem = c;

	while(temp != NULL){

		if(temp->elem == d){
			counter++;
		}

		if(counter == n){
			//end of the list
			if(temp->next == NULL){


				append(c);

				//delete new_node since we are using append(char c) now
				delete new_node;

				return;
			}

			//in between two nodes, so link in
			else{

				new_node->next = temp->next;
				new_node->prev = temp;

				temp->next->prev = new_node;
				temp->next = new_node;
				return;
			}
		}

		//traversing through linked list
		temp = temp->next;
	}

	if(empty() || counter < n){
		append(c);
		delete new_node;
	}
}

void CharList::insert(char c){
	Node* n = new Node;
	n->elem = c;

	//node n becomes the head for both cases
	if(empty()){
		n->next = NULL;
		n->prev = NULL;

		head = n;
	}

	else{
		n->next = head;
		n->prev = NULL;
		head = n;
	}
}

void CharList::insert(char c, char d){
	insert(c, d, 1);

}

//similar approach as append
void CharList::insert(char c, char d, int n){

	Node* temp = head;
	Node* new_node = new Node;
	int counter = 0;



	new_node->elem = c;

	if(empty()){
		append(c);
		delete new_node;
		return;
	}

	while(temp != NULL){

		if(temp->elem == d){
			counter++;
		}

		if(counter == n){
			//inserting before the head
			if(temp->prev == NULL){


				insert(c);
				delete new_node;

				return;
			}

			//inserting between two nodes
			else{

				new_node->next = temp;
				new_node->prev = temp->prev;

				temp->prev->next = new_node;
				temp->prev = new_node;
				return;
			}
		}

		temp = temp->next;
	}

	if(counter < n){
		append(c);
		delete new_node;
	}
}

void CharList::remove(char c){

	remove(c, 1);
}

void CharList::remove(char c, int n){

	Node* temp = head;
	int counter = 0;

	if(!empty()){

		if(size() == 1){
			head = NULL;
			tail = NULL;

			delete temp;
			return;
		}

		while(temp != NULL){

			if(temp->elem == c){
				counter++;
			}

			//nth occurrence of c
			if(counter == n){

				//char is in last position
				if(temp->next == NULL){	

					Node* last_node = temp->prev;
					last_node->next = NULL;

					delete temp;
					return;

				}

				else{

					//char is in first position
					if(n == 1 && temp == head){
						Node* first_node = temp->next;

						head = temp->next;
						first_node->prev = NULL;

						delete temp;
						return;

					}

					//char is in between two nodes
					else{
						Node* u = temp->next;	
						Node* w = temp->prev;

						//linking out, referenced to lecture slides
						u->prev = w;
						w->next = u;

						delete temp;

						return;	
					}
				}
				
			
			}




			temp = temp->next;

		}
	}

}
