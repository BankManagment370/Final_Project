#include "MyNode.h"

class LinkedListFunctions {
public:
	LinkedListFunctions(void);	// constructor
	~LinkedListFunctions(void);	// destructor

	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();
	void insertBeg(string fName, string lName, double savingsBal, double checkingBal);
	void insertEnd(string fName, string lName, double savingsBal, double checkingBal);
	void insertNode(int pos, string fName, string lName, double savingsBal, double checkingBal);
	int findAccount(string fName, string lName);
	void deleteNode(string fName, string lName);
	void deleteAtPosition(int pos);
	int getLength() const;
	void displayList(void);
	void deleteBeg();
	void deleteEnd();
	void add(string fName, string lName, double savingsBal, double checkingBal);
	void sorting();
	void savingsWithdraw(string fName, string lName);
	void checkingWithdraw(string fName, string lName);
	void checkingDeposit(string fName, string lName);
	void savingsDeposit(string fName, string lName);
private:
	int length;
	Node* head;
};
