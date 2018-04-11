#include <iostream>
#include <string>

using namespace std;

#ifndef BANK_MENU_H					
#define BANK_MENU_H


void splashScreen();
void getAccount();
void withdraw();
void deposit();
void seeDatabase();
void mainMenu();
int validate(string input, string checkType);
void userInput();
#endif
