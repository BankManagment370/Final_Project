#include "MyNode.h"


class LinkedListFunctions {
public:
	LinkedListFunctions(void);	// constructor
	~LinkedListFunctions(void);	// destructor

	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();

	int findAccount(string fName, string lName);
	void deleteNode(string fName, string lName);
	int getLength() const;
	void displayList(void);
	void deleteBeg();
	void deleteEnd();
	void add(string fName, string lName, double savingsBal, double checkingBal);

	void savingsWithdraw(string fName, string lName);
	void checkingWithdraw(string fName, string lName);
	void checkingDeposit(string fName, string lName);
	void savingsDeposit(string fName, string lName);
	void readDataFromFile();
	void save();
	void showRecent();
	void deleteRecent();
private:
	int length;
	Node* head;
};
