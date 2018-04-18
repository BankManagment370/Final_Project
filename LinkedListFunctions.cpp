#include "LinkedListFunctions.h"
#include<iostream>
#include "Alt.h"
#include "MyNode.h"

using namespace std;

//O(1)
LinkedListFunctions::LinkedListFunctions()
{
	length = 0; //To keep track of the length to be O(1) otherwise it will be O(n) when we traverse throughout the whole linked list.
	head = NULL;  //The list is essentially empty
}

//O(1)
void LinkedListFunctions::insertBeg(string fName, string lName, double savingsBal, double checkingBal)
{
	Node* node1 = new Node();
	Node * current = new Node();

	node1->firstName = fName;
	node1->lastName = lName;
	node1->savingsBalance = savingsBal;
	node1->checkingBalance = checkingBal;

		/* Locate the node before the point of insertion */
		current = head;
	
		node1->next = current->next;
		current->next = node1;
	}

//O(n)
void LinkedListFunctions::insertEnd(string fName, string lName, double savingsBal, double checkingBal)
{
	Node *newNode = new Node();
	newNode->firstName = fName;
	newNode->lastName = lName;
	newNode->savingsBalance = savingsBal;
	newNode->checkingBalance = checkingBal;
	newNode->next = NULL;

	length++;
}

void LinkedListFunctions::insertNode(int pos, string fName, string lName, double savingsBal, double checkingBal)
{
	Node* prev = new Node();
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->firstName = fName;
	newNode->lastName = lName;
	newNode->savingsBalance = savingsBal;
	newNode->checkingBalance = checkingBal;

	int tempPos = 0;   // Traverses through the list

	curr = head;      // Initialize current to head;

	if (head != NULL)
	{
		while (curr->next != NULL && tempPos != pos)
		{
			prev = curr;
			curr = curr->next;
			tempPos++;
		}
		if (pos == 0 && curr->firstName > fName)
		{
			cout << "Adding at Head! " << endl;
			insertBeg(fName, lName, savingsBal, checkingBal);
		}
		else if (curr->next == NULL && pos == tempPos + 1)
		{
			cout << "Adding at Tail! " << endl;
			insertEnd(fName, lName, savingsBal, checkingBal);
		}
		else if (pos > tempPos + 1)
			cout << " Position is out of bounds " << endl;
		//Position not valid 

		else
		{
			prev->next = newNode;
			newNode->next = curr;
			cout << "Node added at position: " << pos << endl;
		}
	}
	else
	{
		head = newNode;
		newNode->next = NULL;
		cout << "Added at head as list is empty! " << endl;
	}
}


//O(1)
bool LinkedListFunctions::isFull() const
{
	Node* location;
	try
	{
		location = new Node;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

//O(1)
bool LinkedListFunctions::isEmpty() const
{
	return length == 0;
}

//O(n)
void LinkedListFunctions::makeEmpty()
{
	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

//O(n)
LinkedListFunctions::~LinkedListFunctions()
{
	makeEmpty();
}

int LinkedListFunctions::findNode(string fName, string lName, double savingsBal, double checkingBal) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->firstName != fName) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) return currIndex;
	return 0;
}

//O(n)
void LinkedListFunctions::deleteNode(string fName, string lName, double savingsBal, double checkingBal)
{
	if (head == NULL)
	{
		cout << "The list is empty can not delete the item: " << fName << " "<<  lName << " " <<  savingsBal << " " <<  checkingBal << endl;
	}
	else
	{
		Node* temp = head;
		if (fName == head->firstName) //if the node I am trying to delete is the first node
		{
			head = head->next;
			delete temp;
			length--;
		}
		else
		{
			while (temp->next != NULL && (fName != temp->next->firstName)) //and the next item is not the target
			{
				temp = temp->next;
			}
			Node * target = temp->next;
			if (target != NULL)
			{
				temp->next = target->next;
				delete target;
				length--;
			}
		}
	}
}

//O(n)
void LinkedListFunctions::displayList()
{
	Node *newNode;
	newNode = head;
	cout << "Inside the displayList function" << endl;

	while (newNode != NULL);
	{
		cout << newNode->firstName << "\t";
		cout << newNode->lastName << "\t";
		cout << newNode->savingsBalance << "\t";
		cout << newNode->checkingBalance << "\t";

		newNode = newNode->next;
	} 
	cout << endl;
}

void LinkedListFunctions::add(string fName, string lName, double savingsBal, double checkingBal) {
	Node *newNode = new Node();
	newNode->firstName = fName;
	newNode->lastName = lName;
	newNode->savingsBalance = savingsBal;
	newNode->checkingBalance = checkingBal;
	newNode->next = NULL;


	if (head == NULL) {
		head = newNode;
		cout << "Node added at the head!" << endl;
	}
	else {
		Node *temp = head;
		int count = 1;
		while (temp->next != NULL)
		{
			temp = temp->next;
			cout << count << ": number of nodes created" << endl

			++count;
		}
		temp->next = newNode;
	}	
	length++;
}




//O(1)
int LinkedListFunctions::getLength() const
{
	return length;
}
