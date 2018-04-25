#include <iostream>
#include <cassert>
using namespace std;


template <class T>
struct Node
{
	T info;
	Node<T> *next;
};


template <class T>
class Queue
{
public:

	bool empty() const;
	bool full() const;
	void initializeQueue();
	T front() const;
	T back() const;
	void enqueue(const T& queueElement);
	T dequeue();
	int size() const;
	Bank_Queue(); //Default constructor
	~Bank_Queue(); //Destructor
	void savingsWithdraw(string fName, string lName);
	void checkingWithdraw(string fName, string lName);
	void checkingDeposit(string fName, string lName);
	void savingsDeposit(string fName, string lName);
	int findAccount(string fName, string lName);

private:
	Node<T> *queueFront; //pointer to the front of the queue
	Node<T> *queueRear;  //pointer to the rear of the queue
	int length;
};
