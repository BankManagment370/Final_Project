#include "Node.h"
#include "Bank_Stack"
#include <cassert>
#include <iostream>

using namespace std;


template<class Type>
Bank_Stack<Type>::Stack()		 // constructor
{
	length = 0;
	stackTop = NULL;
}

template<class Type>
bool Bank_Stack<Type>::isEmpty() const
{
	return  (stackTop == NULL);
}

template <class Type>
Bank_Stack<Type>::~Stack() {
	makeEmpty();
}

template<class Type>
void Bank_Stack<Type>::push(Type newItem)
{
	Node<Type>*  newNode;
	newNode = new  Node<Type>;
	newNode->data = newItem;
	newNode->next = stackTop;
	stackTop = newNode;
	length++;
}


template <class Type>
Type Bank_Stack<Type>::pop()
{
	Node<Type>*  tempPtr;
	Type item = stackTop->data;
	tempPtr = stackTop;
	stackTop = stackTop->next;
	delete  tempPtr;
	length--;
	return item;
}

template<class Type>
bool Bank_Stack<Type>::isFull() 	const
{
	Node* newNode;
	try
	{
		newNode = new Node;
		delete newNode;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

template<class Type>
void Bank_Stack<Type>::makeEmpty()
{
	// Post:  Stack is empty; all elements deallocated.
	Node<Type>*  tempPtr;
	while (stackTop != NULL)
	{
		tempPtr = stackTop;
		stackTop = stackTop->next;
		delete  tempPtr;
	}
	length = 0;
}

template<class Type>
Type Bank_Stack<Type>::top() const
{
	if (isEmpty())
	{
		cout << "Stack is Empty\n";
		return NULL;
	}
	else
		return stackTop->data;
}

template<class Type>
void Bank_Stack<Type>::displayStack()
{
	Node<Type>*  tempPtr;
	tempPtr = stackTop;

	cout << "\n\n\ntop -->";

	while (tempPtr != NULL)
	{
		cout << "\t|\t" << tempPtr->data << "\t|" << endl;
		tempPtr = tempPtr->next;
	}
	cout << "\t|---------------|\n\n" << endl;
}
