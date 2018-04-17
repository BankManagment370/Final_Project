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
	int findNode(string fName, string lName, double savingsBal, double checkingBal);
	void deleteNode(string fName, string lName, double savingsBal, double checkingBal);
	void deleteAtPosition(int pos);
	int getLength() const;
	void displayList(void);
	void deleteBeg();
	void deleteEnd();
	void sorting();
private:
	int length;
	Node* head;
};