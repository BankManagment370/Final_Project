#include <iostream>
#include <string>

using namespace std;

#ifndef BANK_MENU_H					
#define BANK_MENU_H


void splashScreen();
void getAccount();
void withdraw();
void deposit();
void showDatabase();
void mainMenu();
void userInput();
int validate(string input, string checkType);
#endif
