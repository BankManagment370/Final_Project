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

string bankSkeleton::getAccName() {
	return accName;
}

string bankSkeleton::getMemberName(){
	return accName;  
}

double bankSkeleton::getBalanceS() {
	return balanceS;
}

double bankSkeleton::getBalanceC() {
	return balanceC;
}

void bankSkeleton::setMemberName(string memberName){
	memberName = memberName;
}

void bankSkeleton::setAccName(string accName) {
	accName = accName;
}

void bankSkeleton::setBalanceS(double balanceS) {
	balanceS = balanceS;
}

void bankSkeleton::setBalanceC(double balanceC) {
	balanceC = balanceC;
}

void bankSkeleton::withdraw(double w) {
	cout<<"Enter amount"<<endl;
	cin>>w;
	if(accName == "Savings" || accName == "savings")
	{
		balanceS = balanceS - w;
	}
	else if(accName == "Checking" || accName == "checking")
	{
		balanceC = balanceC - w;
	}
}

void bankSkeleton::deposit(double d) {
	cout<<"Enter amount"<<endl;
	cin>>d;
	
	if(accName == "Savings" || accName == "savings")
	{
		balanceS = balanceS + d;
	}
	
	else if(accName == "Checking" || accName == "checking")
	{
		balanceC = balanceC + d;
	}
}
