#include <iostream>
#include "Bank.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "Alt.h"
#include "MyNode.h"
#include "List.h"


using namespace std;
List myFuncs;
Node *myNode = new Node();

Bank::Bank() {

}

ifstream Bank::getFile() {
	ifstream myfile;
	return myfile;
}

string Bank::getLastName() {
	return lastName;
}

string Bank::getFirstName(){
	return firstName;  
}

double Bank::getSavingsBalance() {
	return savingsBalance;
}

double Bank::getCheckingBalance() {
	return checkingBalance;
}

void Bank::setFirstName(string fn){
	firstName = fn;
}

void Bank::setLastName(string ln) {
	lastName = ln;
}

void Bank::setBalanceS(double balanceS) {
	balanceS = balanceS;
}

void Bank::setBalanceC(double balanceC) {
	balanceC = balanceC;
}

void Bank::withdrawSavings() {
	string fName, lName, accType;
	double w;
	
	gotoxy(50, 32);
	cout << "What is the FIRST name of the account you are trying to withdraw to?" << endl;
	gotoxy(50, 33);
	cin >> fName;
	
	gotoxy(50, 34);
	cout << "What is the LAST name of the account you are trying to withdraw to?" << endl;
	gotoxy(50, 35);
	cin >> lName;

	gotoxy(50, 36);
	cout << "Which account would you like to withdraw from? \n NOTE: Please use(s) for savings or (c) for checking..." << endl;
	
	gotoxy(50, 38);
	cin >> accType;

	gotoxy(50, 40);
	cout << "Enter amount" << endl;

	gotoxy(50, 41);
	cin >> w;


	if (myNode->firstName == fName && myNode->lastName == lName && accType == "s" || "S")
	{
		if (myNode->savingsBalance < w)
		{
			gotoxy(50, 41);
			cout << "Node saving Balance for " << myNode->firstName << " "<< myNode->savingsBalance << endl;
			gotoxy(50, 41);
			cout << "ERROR: Cannot withdraw more than account balance, please try again" << endl;
			gotoxy(50, 42);
			cout << "Enter amount: " << endl;
			gotoxy(50, 43);
			cin >> w;
		}
		else
		{
			gotoxy(50, 44);
			cout << "Balance before withdrawal: " << myNode->savingsBalance << endl;
			myNode->savingsBalance -= w;

			gotoxy(50, 45);
			cout << "Balance after withdrawal: " << myNode->savingsBalance << endl;
		}
	}
	else
	{
		myNode = myNode->next;
	}
}

void Bank::depositSavings(double d) {
	cout<<"Enter amount"<<endl;
	cin >> d;
}

void Bank::withdrawChecking(double w) {
	cout << "Enter amount" << endl;
	cin >> w;
}

void Bank::depositChecking(double d)
{
	cout << "Enter amount" << endl;
	cin >> d;
}

void Bank::readDataFromFile()
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
	string savingBalAsString;
	string checkingBalAsString;
	double savingBal;  
	double checkingBal; 

	while (!ss.eof())
	{
		getline(ss, fName, ':');
		getline(ss, lName, ':');
		getline(ss, savingBalAsString, ':');
		getline(ss, checkingBalAsString, '\n');

		savingBal = stod(savingBalAsString);
		checkingBal = stod(checkingBalAsString);

		cout << endl;
		int count = 1;

		if (count == 1)
		{
			myFuncs.addAtEnd(fName, lName, savingBal, checkingBal);
			count++;
		}
		else if (count > 1) {
			myFuncs.addAtEnd(fName, lName, savingBal, checkingBal);
		}
		count++;
	}

	}
