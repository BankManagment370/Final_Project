#include <iostream>
#include <string>
#include "linkedListFunctions.h"
#include "Bank_Menu.h"
#include "MyNode.h"
#include "bankStack.h"

using namespace std;

/**************************************************************************/
//                            Stack functions
/**************************************************************************/

// PUSH Operation
myStack::myStack()// constructor
{
	top = NULL;
}

void myStack::push(string fName, string lName, double chkBal, double savBal)
{
	struct Node *ptr;
	ptr = new Node;
	ptr->firstName = fName;
	ptr->lastName = lName;
	ptr->checkingBalance = chkBal;
	ptr->savingsBalance = savBal;

	if (top != NULL)
		ptr->next = top;
	top = ptr;
	cout << "\nNew item is inserted to the stack! ";

}

// POP Operation
void myStack::pop()
{
	struct Node *temp;
	if (top == NULL)
	{
		cout << "\nThe stack is empty!!!";
	}
	temp = top;
	top = top->next;
	cout << "\nPOP Operation........\nPoped value is " << temp->firstName << " " << temp->lastName << " " << temp->savingsBalance << " " << temp->checkingBalance;
	system("pause");
	delete temp;
}

// Show stack
void myStack::show()
{
	struct Node *ptr1 = top;
	cout << "\nThe most recently added record: \n";
	cout << ptr1->firstName << " " << ptr1->lastName << " " << ptr1->savingsBalance << " " << ptr1->checkingBalance << endl;	
	system("pause");
}
