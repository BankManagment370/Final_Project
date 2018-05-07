#pragma once

#include "MyNode.h"

class myStack
{
	 Node *top;
public:

	void push(string fName, string lName, double chkBal, double savBal); // to insert an element
	void pop();  // to delete an element
	void show(); // to show the stack'
	myStack();
};
