#include "Customer.h"

//default constructor
Customer::Customer()
: firstInitial('\0'), lastName(""), balance(0) 
{ }

Customer::Customer(string x, char y, int z){
	firstInitial = y;
	lastName = x;
	balance = z;
}

char Customer::getFirstInitial() const{
	return firstInitial;
}

string Customer::getLastName() const{
	return lastName;
}

int Customer::getBalance() const{
	return balance;
}

void Customer::setBalance(int b){
	balance = b;
}

bool Customer::operator<(const Customer& c){
	if(lastName < c.lastName){
		return true;
	}

	else if(lastName == c.lastName){
		if(firstInitial < c.firstInitial){
			return true;
		}
	}

	return false;
}

bool Customer::operator<=(const Customer& c){
	if(lastName < c.lastName){
		return true;
	}

	else if(lastName == c.lastName){
		if(firstInitial <= c.firstInitial){
			return true;
		}
	}

	return false;

}

bool Customer::operator>(const Customer& c){
	if(lastName > c.lastName){
		return true;
	}

	else if(lastName == c.lastName){
		if(firstInitial > c.firstInitial){
			return true;
		}
	}

	return false;

}

bool Customer::operator>=(const Customer& c){
	if(lastName > c.lastName){
		return true;
	}

	else if(lastName == c.lastName){
		if(firstInitial >= c.firstInitial){
			return true;
		}
	}

	return false;
}

bool Customer::operator==(const Customer& c){
	if(lastName == c.lastName){
		if(firstInitial == c.firstInitial){
			return true;
		}
	}

	return false;
}

bool Customer::operator!=(const Customer& c){
	if(lastName != c.lastName){
		if(firstInitial != c.firstInitial){
			return true;
		}
	}

	return false;
}

ostream& operator<<(ostream& os, Customer& c){
	os << c.lastName << ", " << c.firstInitial << ". (" << c.balance << ")";
	return os;
}


void Customer::setFirstInitial(char c){
	firstInitial = c;
}

void Customer::setLastName(string s){
	lastName = s;
}
