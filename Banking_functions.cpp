#include <iostream>
#include "Banking_Functions.h"
#include <fstream>

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
