#include <iostream>
#include <string>

using namespace std;

class Node{
private:
	char elem;
	Node* next;
	Node* prev;

	friend class CharList;
};

class CharList{
private:
	Node* head;
	Node* tail;

public:
	CharList(string s);	//done
	~CharList();	//done

	bool empty();	//done
	int size();	//done

	void insert(char c);	//done
	void append(char c);	//done

	void insert(char c, char d);	//done
	void append(char c, char d);	//done

	void insert(char c, char d, int n);	//done
	void append(char c, char d, int n);	//done

	void remove(char c);	//done
	void remove(char c, int n);	//done;

	string toString();	//done

};
