#include <iostream>
#include "Banking_Functions.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "Alt.h"
#include "MyNode.h"
#include "LinkedListFunctions.h"


using namespace std;
LinkedListFunctions myFuncs;
Node *myNode = new Node;

bankSkeleton::bankSkeleton() {

}

ifstream bankSkeleton::getFile() {
	ifstream myfile;
	return myfile;
}

string bankSkeleton::getLastName() {
	return lastName;
}

string bankSkeleton::getFirstName(){
	return firstName;  
}

double bankSkeleton::getSavingsBalance() {
	return savingsBalance;
}

double bankSkeleton::getCheckingBalance() {
	return checkingBalance;
}

void bankSkeleton::setFirstName(string fn){
	firstName = fn;
}

void bankSkeleton::setLastName(string ln) {
	lastName = ln;
}

void bankSkeleton::setBalanceS(double balanceS) {
	balanceS = balanceS;
}

void bankSkeleton::setBalanceC(double balanceC) {
	balanceC = balanceC;
}

void bankSkeleton::withdrawSavings() {
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

void bankSkeleton::depositSavings(double d) {
	cout<<"Enter amount"<<endl;
	cin >> d;
}

void bankSkeleton::withdrawChecking(double w) {
	cout << "Enter amount" << endl;
	cin >> w;
}

void bankSkeleton::depositChecking(double d)
{
	cout << "Enter amount" << endl;
	cin >> d;
}

void bankSkeleton::readDataFromFile()
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
		
		if (count == 1)
		{
			myFuncs.add(fName, lName, savingBal, checkingBal);
			count++;
		}
		else if (count > 1) {
			myFuncs.add(fName, lName, savingBal, checkingBal);
		}
		count++;
	}

	}
