#include <string>
#include <fstream>
using namespace std;

#pragma once
#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

class bankSkeleton {
private:
	string firstName;
	string lastName;

	double savingsBalance;
	double checkingBalance;
	

public:
	//constructor
	bankSkeleton();
	
	//Get the output file
	ifstream getFile();

	//Get methods for the variables
	string getFirstName();
	string getLastName();
	double getSavingsBalance();
	double getCheckingBalance();
	
	//Set methods for the variables
	void setFirstName(string fn);
	void setLastName(string ln);
	void setBalanceS(double balanceS);
	void setBalanceC(double balanceC);

	//Miscelaneous methods
	void withdrawSavings();
	void depositSavings(double d);
	void withdrawChecking(double w);
	void depositChecking(double d);
	void readDataFromFile();
};



#endif // !BANKING_FUNCTIONS_H

