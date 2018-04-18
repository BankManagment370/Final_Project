#include "LinkedListFunctions.h"
#include<iostream>
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

void LinkedListFunctions::deleteAtPosition(int pos)
{
	if (pos < 0 || pos > length)
	{
		cout << "Wrong position\n";
	}
	else
	{
		if (head == NULL)
		{
			cout << "The List is Empty\n";
		}
		else if (pos == 1)
		{
			Node * temp = head;
			head = head->next;
			delete temp;
			length--;
		}
		else
		{
			Node *cur = head;
			Node *pre = head;

			for (int i = 1; i < pos; i++)
			{
				pre = cur;

				cur = cur->next;
			}

			pre->next = cur->next;
			delete cur;
			length--;
		}
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
	Node *temp;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->firstName << "\t";
		cout << temp->lastName << "\t";
		cout << temp->savingsBalance << "\t";
		cout << temp->checkingBalance << "\t";

		temp = temp->next;
	}
	cout << endl;
}

void LinkedListFunctions::deleteBeg()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	length--;
}


void LinkedListFunctions::deleteEnd()
{
	Node *currNode = head;

	while (currNode->next && currNode->next->next != NULL)
	{
		currNode = currNode->next;
	}
	delete currNode->next;
	currNode->next = NULL;

	length--;
}


void LinkedListFunctions::add(string fName, string lName, double savingsBal, double checkingBal) {
	Node *node1 = new Node();
	node1->firstName = fName;
	node1->lastName = lName;
	node1->savingsBalance = savingsBal;
	node1->checkingBalance = checkingBal;
	node1->next = head;
	head = node1;
	
	length++;
}




//O(1)
int LinkedListFunctions::getLength() const
{
	return length;
}


/*
void UnSortedType::sorting() {
Node * temphead = head;
Node * tempnode = NULL;
double tempdata;
string tempname;
int counter = 0;
while (temphead)
{
temphead = temphead->next;
counter++;
}
temphead = head;

for (int j = 0; j<counter; j++)
{
while (temphead->next)  //iterate through list until next is null
{
if (temphead->data > temphead->next->data)
{
tempnode = temphead;
temphead = temphead->next;
temphead->next = tempnode;
tempdata = temphead->data;
temphead->data = temphead->next->data;
temphead->next->data = tempdata;
temphead = temphead->next;//increment node
}
else
temphead = temphead->next;//increment node
}
temphead = head;//reset temphead
}
}
*/
