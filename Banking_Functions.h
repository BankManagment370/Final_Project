#include <string>
#include <fstream>
using namespace std;

#pragma once
#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

class bankSkeleton {
private:
	string accName;
	double balanceS;
	double balanceC;
	

public:
	bankSkeleton();
	ifstream getFile(ifstream infile);
	string getAccount();
	double getBalances();
	double getBalanceC();
	void setAccName();
	void setBalanceS();
	void setBalanceC();
	void withdraw(double w);
	void deposit(double d);
	Void searchRecords();
};





#endif // !BANKING_FUNCTIONS_H

