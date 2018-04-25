#include "Node.h"
#include "Bank_Stack.h"
#include <cassert>
#include <iostream>

using namespace std;


template<class Type>
Bank_Stack<Type>::Bank_Stack()		 // constructor
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
Bank_Stack<Type>::~Bank_Stack() {
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
template<class Type>
int Bank_Stack<Type>::findAccount(string fName, string lName) {
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




template<class Type>
void Bank_Stack<Type>::displayList()
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

template<class Type>
void Bank_Stack<Type>::deleteBeg()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	length--;
}

template<class Type>
void Bank_Stack<Type>::deleteEnd()
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

//template<class Type>
//void LinkedListFunctions::add(string fName, string lName, double savingsBal, double checkingBal) {
//	Node *node1 = new Node();
//	node1->firstName = fName;
//	node1->lastName = lName;
//	node1->savingsBalance = savingsBal;
//	node1->checkingBalance = checkingBal;
//	node1->next = head;
//	head = node1;
//
//	length++;
//}

template<class Type>
int Bank_Stack<Type>::getLength() const
{
	return length;
}
template<class Type>
void Bank_Stack<Type>::savingsWithdraw(string fName, string lName)
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
template<class Type>
void Bank_Stack<Type>::checkingWithdraw(string fName, string lName)
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
template<class Type>
void Bank_Stack<Type>::savingsDeposit(string fName, string lName)
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
template<class Type>
void Bank_Stack<Type>::checkingDeposit(string fName, string lName)
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
template<class Type>
void Bank_Stack<Type>::readDataFromFile()
{
	string fileName = "data.csv";
	string line = "";
	ifstream myFile;
	stringstream ss;
	int count = 1, rows = 0, numbOfTimes = 0;

	myFile.open(fileName);

	while (!myFile.eof())
	{
		getline(myFile, line, ',');
		ss << line << ':';
	}
	myFile.seekg(0);

	//Get number of rows in file

	string fName = "";
	string lName = "";
	string savingBal = "";
	string checkingBal = "";

	while (!ss.eof())
	{
		getline(ss, fName, ':');
		getline(ss, lName, ':');
		getline(ss, savingBal, ':');
		getline(ss, checkingBal, '\n');


		cout << endl;

		if (count == 1)
		{
			add(fName, lName, stod(savingBal), stod(checkingBal));
			count++;
		}
		else if (count >= 2) {
			add(fName, lName, stod(savingBal), stod(checkingBal));
		}
		count++;
	}

}
