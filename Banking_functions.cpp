#include <iostream>
#include "Banking_Functions.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "Alt.h"

using namespace std;

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
	cout<<"Enter amount"<<endl;
	cin>>w;
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
	string fileName;
	cout << "Enter a file to read from: " << endl;
	cin >> fileName;

	ifstream myFile;
	myFile.open(fileName);


	stringstream ss;
	vector<string> result;

	while (ss.good())
	{
		string fName, lName, savingBal, checkingBal;
		int counter = 0;

		while (counter < 5)
		{
			string substr;
			getline(myFile, substr, ',');
			result.push_back(substr);

			if (counter == 0)
			{
				fName = substr;
				counter++;
			}
			else if(counter == 1)
			{
				lName = substr;
				counter++;
			}
			else if(counter == 2)
			{
				savingBal = substr;
				counter++;
			}
			else
			{
				checkingBal = substr;
				counter =0;
			}
			gotoxy(50, 70);
			cout << "First name: " << fName << endl;
			gotoxy(50, 71);
			cout << "Last name: " << fName << endl;
			gotoxy(50, 72);
			cout << "Savings Account Bal: " << fName << endl;
			gotoxy(50, 73);
			cout << "Checking account Bal: " << fName << endl;

		}
	}
}
