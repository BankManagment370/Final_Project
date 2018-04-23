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

void bankSkeleton::withdrawSavings(double w) {
	cout << "Enter amount" << endl;
	cin >> w;
}

void bankSkeleton::depositSavings(double d) {
	cout << "Enter amount" << endl;
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
			myFuncs.add(fName, lName, stod(savingBal), stod(checkingBal));
			count++;
		}
		else if (count >= 2) {
			myFuncs.add(fName, lName, stod(savingBal), stod(checkingBal));
		}
		count++;
	}

}
