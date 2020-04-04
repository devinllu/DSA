#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer();
	Customer(string, char, int);

	string getLastName() const;
	char getFirstInitial() const;
	int getBalance() const;

	void setBalance(int b);

	//setters for the customer
	void setLastName(string s);
	void setFirstInitial(char c);

	bool operator<(const Customer& c);
	bool operator<=(const Customer& c);
	bool operator>(const Customer& c);
	bool operator>=(const Customer& c);
	bool operator==(const Customer& c);
	bool operator!=(const Customer& c);


private:
	friend ostream& operator<<(ostream& os, Customer& c);


	char firstInitial;
	string lastName;
	int balance;


};

#endif
