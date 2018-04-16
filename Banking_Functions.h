#include <string>
#include <fstream>
using namespace std;

#pragma once
#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

class bankSkeleton {
private:
	string memberName;
	string accName;
	double balanceS;
	double balanceC;
	

public:
	bankSkeleton();
	ifstream getFile(ifstream infile);
	string getAccount();
	string getMemberName();
	double getBalanceS();
	double getBalanceC();
	void setMemberName();
	void setAccName();
	void setBalanceS();
	void setBalanceC();
	void withdraw(double w);
	void deposit(double d);
	void searchRecords();
	void print();
};





#endif // !BANKING_FUNCTIONS_H

