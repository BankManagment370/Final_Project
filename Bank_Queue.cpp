#include "Bank_Queue.h"
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
Bank_Queue<T>::Queue()
{
	queueFront = nullptr; 
	queueRear = nullptr;  
	length = 0;
} //end default constructor

template <class T>
bool Bank_Queue<T>::empty() const
{
	return (queueFront == nullptr);
} //end empty

template <class T>
bool Bank_Queue<T>::full() const
{
	return false;
} 

template <class T>
void Bank_Queue<T>::enqueue(const T& newElement)
{
	Node<T> *newNode;

	newNode = new Node <T> ;   

	newNode->info = newElement; 
	newNode->next = nullptr;    
	

	if (queueFront == nullptr) 
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else        
	{
		queueRear->next = newNode;
		queueRear = queueRear->next;
	}
	length++;
}

template <class T>
T Bank_Queue<T>::front() const
{
	if (queueFront != nullptr)
	{
		return queueFront->info;
	}
	else
	{
		return NULL;
	}
} 

template <class T>
T Bank_Queue<T>::back() const
{
	if (queueRear != nullptr)
	{
		return queueRear->info;
	}
	else
	{
		return NULL;
	}

} 

template <class T>
T Bank_Queue<T>::dequeue()
{
	Node<T> *temp;

	if (!empty())
	{
		T returnValue = queueFront->info;
		temp = queueFront; 
		
		queueFront = queueFront->next; 

		delete temp;   

		if (queueFront == nullptr) 
			queueRear = nullptr;   
		length--;
		return returnValue;
	}
	else
	{
		cout << "Cannot remove from an empty queue" << endl;
		return NULL;
	}

}


template <class T>
int Bank_Queue<T>::size() const
{
	return length;
}


template <class T>
Bank_Queue::~Queue()
{
	
} 

template <class T>
int Bank_Queue<T>::findAccount(string fName, string lName) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->firstName != fName && currNode->lastName != lName) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode)
	{
		cout << "Name under account: " << currNode->firstName << " " << currNode->lastName << endl;
		cout << "Checking Balance: " << currNode->checkingBalance << endl;
		cout << "Savings Balance: " << currNode->savingsBalance << endl;
	}
	return 0;
}
