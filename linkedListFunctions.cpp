#include "LinkedListFunctions.h"
#include "bankStack.h"
#include<iostream>
#include "Alt.h"
#include "Bank_Menu.h"
#include <fstream>
#include <sstream>

using namespace std;

myStack stack;
//O(1)

LinkedListFunctions::LinkedListFunctions()
{
	length = 0; //To keep track of the length to be O(1) otherwise it will be O(n) when we traverse throughout the whole linked list.
	head = NULL;  //The list is essentially empty
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
			cout << "Item deleted " << endl;
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
	
	stack.push(fName, lName, savingsBal, checkingBal);
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

void LinkedListFunctions::readDataFromFile()
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
		if (fName != "" || lName != "")
		{
			add(fName, lName, stod(savingBal), stod(checkingBal));
			stack.push(fName, lName, stod(savingBal), stod(checkingBal));
			count++;
		}
		else {

		}
	}

}

void LinkedListFunctions::save() {
	ofstream myfile;
	myfile.open("data.csv");
	Node *temp;
	temp = head;
	
	
	while (temp != NULL)
	{
		myfile << temp->firstName << ",";
		myfile << temp->lastName << ",";		
		myfile << temp->savingsBalance << ",";
		myfile << temp->checkingBalance << ",";
		myfile << endl;
		temp = temp->next;
	}
	myfile.close();
}

void LinkedListFunctions::showRecent(){
	stack.show();
}

void LinkedListFunctions::deleteRecent() {
	stack.pop();
}
