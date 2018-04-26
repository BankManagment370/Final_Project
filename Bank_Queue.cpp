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
template <class T>
void Bank_Queue<T>::savingsWithdraw(string fName, string lName)
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
