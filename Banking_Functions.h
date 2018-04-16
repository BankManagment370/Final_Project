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
	//constructor
	bankSkeleton();
	
	//Get the output file
	ifstream getFile();

	//Get methods for the variables
	string getAccName();
	string getMemberName();
	double getBalanceS();
	double getBalanceC();
	
	//Set methods for the variables
	void setMemberName(string memberName);
	void setAccName(string accName);
	void setBalanceS(double balanceS);
	void setBalanceC(double balanceC);

	//Miscelaneous methods
	void withdraw(double w);
	void deposit(double d);
};



#endif // !BANKING_FUNCTIONS_H

