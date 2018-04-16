#include <string>
#include <iostream>

#ifndef MYNODE_H
#define MYNODE_H

using namespace std;

struct Node
{
	string firstName;
	string lastName;
	double savingsBalance;
	double checkingBalance;

	Node* next;	//pointer to next
};

#endif
