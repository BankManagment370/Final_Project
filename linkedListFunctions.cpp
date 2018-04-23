#include "LinkedListFunctions.h"
#include<iostream>
#include "Alt.h"
#include "Bank_Menu.h"
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

int LinkedListFunctions::findAccount(string fName, string lName) {
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

//O(n)
void LinkedListFunctions::deleteNode(string fName, string lName)
{
	if (head == NULL)
	{
		cout << "The list is empty can not delete the item: " << fName << " " << lName << endl;
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
				cout << "Item succesfully deleted!" << endl;
				length--;
			}
		}
	}
}

//O(n)
void LinkedListFunctions::displayList()
{
	system("CLS");
	Node *temp;
	temp = head;
	cout << endl << endl;
	cout << endl << endl;
	cout << "Current list of customer accounts:" << endl;
	cout << "**********************************" << endl;
	while (temp != NULL)
	{
		cout << "First Name: " << temp->firstName << "\t";
		cout << "Last Name: " << temp->lastName << "\t";
		cout << "Savings Balance: " << temp->savingsBalance << "\t";
		cout << "Checking Balance: " << temp->checkingBalance << "\t";
		cout << endl;
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

void LinkedListFunctions::savingsWithdraw(string fName, string lName)
{
	if (head == NULL)
	{
		cout << "The list is empty can not find the savings account with the name: " << fName << " " << lName << endl;
	}
	else
	{
		Node* temp = head;
		double withdrawAmount;
		if (fName == head->firstName  && lName == head->lastName) //if the node I am trying to delete is the first node
		{
			head = head->next;
			cout << "Savings Account Name: " << fName << " " << lName << endl;
			cout << "How much would you like to withdraw?: ";
			cin >> withdrawAmount;
			
			if (withdrawAmount > temp->savingsBalance || withdrawAmount < 0)
			{
				cout << endl;
				cout << "ERROR: Invalid number attempt. Returned to main menu" << endl;
			}
			else {
				cout << endl;
				temp->savingsBalance = temp->savingsBalance - withdrawAmount;
				cout << "New Savings Balance: " << temp->savingsBalance << endl << endl;
				system("pause");
				//system("CLS");
			}
		}
		else
		{
			while (temp->next != NULL && (fName != temp->next->firstName) && (lName != temp->next->lastName)) //and the next item is not the target
			{
				temp = temp->next;
			}
			Node * target = temp->next;
			if (target != NULL)
			{
				target = temp->next;
				//temp = temp->next;
				cout << "Savings Account Name: " << fName << " " << lName << endl;
				cout << "How much would you like to withdraw?: ";
				cin >> withdrawAmount;

				if (withdrawAmount > target->savingsBalance || withdrawAmount < 0)
				{
					cout << endl;
					cout << "ERROR: Invalid number attempt. Returned to main menu" << endl;
				}
				else {
					target->savingsBalance = target->savingsBalance - withdrawAmount;
					cout << "New Savings Balance: " << target->savingsBalance << endl << endl;
					system("pause");
					system("CLS");
				}
			}
		}
	}
}

void LinkedListFunctions::checkingWithdraw(string fName, string lName)
{
	if (head == NULL)
	{
		cout << endl;
		cout << "The list is empty can not find the checking account with the name: " << fName << " " << lName << endl;
	}
	else
	{
		Node* temp = head;
		double withdrawAmount;
		if (fName == head->firstName  && lName == head->lastName) //if the node I am trying to delete is the first node
		{
			head = head->next;
			cout << endl;
			cout << "Checking Account First Name and Last Name: " << fName << " " << lName << endl;
			cout << "How much would you like to withdraw?: ";
			cin >> withdrawAmount;
			
			if (withdrawAmount > temp->checkingBalance || withdrawAmount < 0)
			{
				cout << "ERROR: Invalid number attempt. Returned to main menu" << endl;
			}
			else {
				temp->checkingBalance = temp->checkingBalance - withdrawAmount;
				cout << "New Checking Balance: " << temp->checkingBalance << endl << endl;
				system("pause");
				//system("CLS");
			}
		}
		else
		{
			while (temp->next != NULL && (fName != temp->next->firstName) && (lName != temp->next->lastName)) //and the next item is not the target
			{
				temp = temp->next;
			}
			Node * target = temp->next;
			if (target != NULL)
			{
				target = temp->next;
				//temp = temp->next;
				cout << "Checking Account Name: " << fName << " " << lName << endl;
				cout << "How much would you like to withdraw?: ";
				cin >> withdrawAmount;
				if (withdrawAmount > target->checkingBalance || withdrawAmount < 0)
				{
					cout << endl;
					cout << "ERROR: Invalid number attempt. Returned to main menu" << endl;
				}
				else {
					cout << endl;
					target->checkingBalance = target->checkingBalance - withdrawAmount;
					cout << "New Checking Balance: " << target->checkingBalance << endl << endl;
					system("pause");
					//system("CLS");
				}
			}
		}
	}
}

void LinkedListFunctions::savingsDeposit(string fName, string lName)
{
	if (head == NULL)
	{
		cout << "The list is empty can not find the savings account with the name: " << fName << " " << lName << endl;
	}
	else
	{
		Node* temp = head;
		double depositAmount;
		if (fName == head->firstName  && lName == head->lastName) //if the node I am trying to delete is the first node
		{
			head = head->next;
			cout << endl;
			cout << "Savings Account Name: " << fName << " " << lName << endl;
			cout << "How much would you like to Deposit?: ";
			cin >> depositAmount;
			if (depositAmount >= 0)
			{
				temp->savingsBalance = temp->savingsBalance + depositAmount;
				cout << "New Savings Balance: " << temp->savingsBalance;
			}
			else {
				cout << "ERROR: Invalid number. Returned to main menu" << endl;
			}
		}
		else
		{
			while (temp->next != NULL && (fName != temp->next->firstName) && (lName != temp->next->lastName)) //and the next item is not the target
			{
				temp = temp->next;
			}
			Node * target = temp->next;
			if (target != NULL)
			{
				target = temp->next;
				//temp = temp->next;
				cout << endl;
				cout << "Savings Account Name: " << fName << " " << lName << endl;
				cout << "How much would you like to Deposit?: ";
				cin >> depositAmount;
				if (depositAmount >= 0)
				{
					target->savingsBalance = target->savingsBalance + depositAmount;
					cout << "New Savings Balance: " << target->savingsBalance;
				}
				else {
					cout << "ERROR: Invalid number. Returned to main menu" << endl;
				}
			}
		}
	}
}

void LinkedListFunctions::checkingDeposit(string fName, string lName)
{
	if (head == NULL)
	{
		cout << "The list is empty can not find the checking account with the name: " << fName << " " << lName << endl;
	}
	else
	{
		Node* temp = head;
		double depositAmount;
		if (fName == head->firstName  && lName == head->lastName) //if the node I am trying to delete is the first node
		{
			head = head->next;
			cout << endl;
			cout << "Checking Account Name: " << fName << " " << lName << endl;
			cout << "How much would you like to deposit?: ";
			cin >> depositAmount;
			temp->checkingBalance = temp->checkingBalance + depositAmount;
			cout << "Checking Balance: " << temp->checkingBalance;
		}
		else
		{
			while (temp->next != NULL && (fName != temp->next->firstName) && (lName != temp->next->lastName)) //and the next item is not the target
			{
				temp = temp->next;
			}
			Node * target = temp->next;
			if (target != NULL)
			{
				target = temp->next;
				//temp = temp->next;
				cout << endl;
				cout << "Checking Account First and Last Name: " << fName << " " << lName << endl;
				cout << "How much would you like to deposit?: ";
				cin >> depositAmount;
				if (depositAmount >= 0)
				{
					target->checkingBalance = target->checkingBalance + depositAmount;
					cout << "New Checking Balance: " << target->checkingBalance;
				}
				else {
					cout << "ERROR: Invalid number. Returned to main menu" << endl;
				}
			}
		}
	}
}

