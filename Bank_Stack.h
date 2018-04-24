#pragma once
#ifndef BANK_STACK.H
#define BANK_STACK.H

template <class  Type>
class Bank_Stack {
public:
	Bank_Stack();
	~Bank_Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(Type item);
	Type pop();
	Type top() const;
	void displayStack();
	int findAccount(string fName, string lName);
	void deleteNode(string fName, string lName);
	int getLength() const;
	void add(string fName, string lName, double savingsBal, double checkingBal);
	void sorting();
	void savingsWithdraw(string fName, string lName);
	void checkingWithdraw(string fName, string lName);
	void checkingDeposit(string fName, string lName);
	void savingsDeposit(string fName, string lName);
	void readDataFromFile();

};




#endif // !BANK_STACK.H

