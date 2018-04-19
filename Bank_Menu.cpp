#include <iostream>
#include "Alt.h"
#include "Bank_Menu.h"
#include "Bank.h"
#include <string>
#include <cctype>
#include <iomanip>
#include "List.h"

using namespace std;



void splashScreen()
{
	system("CLS");
	system("Color 2B");


	//ASCII Art
	gotoxy(50, 9);
	cout << "  __                                                                              __                          \n";
	gotoxy(50, 10);
	cout << "|/  |           /         /|/|                                         /         /              /             \n";
	gotoxy(50, 11);
	cout << "|___| ___  ___ (         ( / | ___  ___  ___  ___  ___  _ _  ___  ___ (___      (___       ___ (___  ___  _ _ \n";
	gotoxy(50, 12);
	cout << "|   )|   )|   )|___)     |   )|   )|   )|   )|   )|___)| | )|___)|   )|             )\\   )|___ |    |___)| | )\n";
	gotoxy(50, 13);
	cout << "|__/ |__/||  / | \\       |  / |__/||  / |__/||__/ |__  |  / |__  |  / |__        __/  \\_/  __/ |__  |__  |  / \n";
	gotoxy(50, 14);
	cout << "																												\n";

	gotoxy(50, 15);
	cin.get();

	system("PAUSE");

}
void getAccount(List &list, Bank &myBank)
{
	system("Color 2B");
	system("CLS");
	gotoxy(50, 9);
	cout << "***************************************************************" << endl;
	gotoxy(50, 10);
	cout << "*                                                             *" << endl;
	gotoxy(50, 11);
	cout << "*                                                             *" << endl;
	gotoxy(50, 12);
	cout << "*                                                             *" << endl;
	gotoxy(50, 13);
	cout << "*                        Get Account                          *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);
	system("PAUSE");

}

// We are trying to use a lunked list implementation, but cannot find a way to get store the data into
// the list, and perform functions on that data without the program crashing
void withdraw(List &list, Bank &myBank)
{
	system("Color 2B");
	system("CLS");
	gotoxy(50, 9);
	cout << "***************************************************************" << endl;
	gotoxy(50, 10);
	cout << "*                                                             *" << endl;
	gotoxy(50, 11);
	cout << "*                                                             *" << endl;
	gotoxy(50, 12);
	cout << "*                                                             *" << endl;
	gotoxy(50, 13);
	cout << "*                      Withdraw Screen                        *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);

	gotoxy(50, 22);
	string menu;

	gotoxy(50, 23);
	cout << "MENU OPTIONS: \n";
	gotoxy(50, 24);
	cout << "1. Make a withdrawal\n";
	gotoxy(50, 25);
	cout << "2. Display account balance\n";
	gotoxy(50, 26);
	cout << "x. Return to main menu\n";

	char choice = 'a';
	while (choice != 'x' || 'X')
	{
		gotoxy(50, 23);
		cout << "MENU OPTIONS: \n";
		gotoxy(50, 24);
		cout << "1. Make a withdrawal \n";
		gotoxy(50, 25);
		cout << "2. Display account balance\n";
		gotoxy(50, 26);
		cout << "x. Return to main menu\n";

		gotoxy(50, 28);
		cout << "Enter choice: ";

		gotoxy(66, 28);
		cin >> choice;

		switch (choice)
		{
		case '1':
			gotoxy(50, 31);
			myBank.readDataFromFile();
			break;

		case '2':
			gotoxy(50, 31);
			list.displayList();
			break;

		case 'x':
			cout << "Choice x selected" << endl;
			return;
			//break;

		default:
			gotoxy(50, 34);
			cout << "ERROR: Please enter a valid choice" << endl << endl;
			break;
		}

	}



	system("PAUSE");

}


void deposit(List &list, Bank &myBank)
{
	system("Color 2B");
	system("CLS");
	gotoxy(50, 9);
	cout << "***************************************************************" << endl;
	gotoxy(50, 10);
	cout << "*                                                             *" << endl;
	gotoxy(50, 11);
	cout << "*                                                             *" << endl;
	gotoxy(50, 12);
	cout << "*                                                             *" << endl;
	gotoxy(50, 13);
	cout << "*                     Deposit Screen                          *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);
	gotoxy(50, 22);
	string menu;


	char choice = 'a';
	while (choice != 'x' || 'X')
	{
		gotoxy(50, 23);
		cout << "MENU OPTIONS: \n";
		gotoxy(50, 24);
		cout << "1. Make a deposit\n";
		gotoxy(50, 25);
		cout << "2. Display account balance\n";
		gotoxy(50, 26);
		cout << "x. Return to main menu\n";

		gotoxy(50, 28);
		cout << "Enter choice: ";

		gotoxy(64, 28);
		cin >> choice;

		switch (choice)
		{
		case '1':
			gotoxy(50, 30);
			cout << "Choice 1 selected" << endl;
			break;

		case '2':
			gotoxy(50, 30);
			cout << "Choice 2 selected" << endl;
			break;

		case 'x':
			cout << "Choice x selected" << endl;
			return;
			//break;

		default:
			gotoxy(50, 34);
			cout << "ERROR: Please enter a valid choice" << endl << endl;
			break;
		}

	}
	system("PAUSE");


}


void showAccounts(List &list, Bank &myBank)
{
	system("Color 2B");
	system("CLS");
	gotoxy(50, 9);
	cout << "***************************************************************" << endl;
	gotoxy(50, 10);
	cout << "*                                                             *" << endl;
	gotoxy(50, 11);
	cout << "*                                                             *" << endl;
	gotoxy(50, 12);
	cout << "*                                                             *" << endl;
	gotoxy(50, 13);
	cout << "*                       Show Accounts                         *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);
	gotoxy(50, 22);


	char choice = 'a';
	while (choice != 'x' || 'X')
	{
		gotoxy(50, 23);
		cout << "MENU OPTIONS: \n";
		gotoxy(50, 24);
		cout << "1. Show accounts in alphabetical order\n";
		gotoxy(50, 25);
		cout << "2. Show accounts in reverse - alphabetical order\n";
		gotoxy(50, 26);
		cout << "x. Return to main menu\n";

		gotoxy(50, 28);
		cout << "Enter choice: ";

		gotoxy(64, 28);
		cin >> choice;

		switch (choice)
		{
		case '1':
			gotoxy(50, 30);
			cout << "Choice 1 selected" << endl;
			break;

		case '2':
			gotoxy(50, 30);
			cout << "Choice 2 selected" << endl;
			break;

		case 'x':
			gotoxy(50, 30);
			cout << "Choice x selected" << endl;
			return;
			//break;

		default:
			gotoxy(50, 34);
			cout << "ERROR: Please enter a valid choice" << endl << endl;
			break;
		}

	}
	system("PAUSE");

}


int validate(string input, string checkType)
{
	int numoccur = 0;

	if (checkType == "isalpha")
	{
		for (unsigned int x = 0; x < input.length(); x++)
		{
			if (!isalpha(input[x]))
				numoccur++;
		}
	}


	if (checkType == "isdigit")
	{
		for (unsigned int x = 0; x < input.length(); x++)
		{
			if (!isdigit(input[x]))
				numoccur++;
		}
	}

	return numoccur;

}

void userInput(List &list, Bank &myBank)
{
	system("Color 2B");
	system("CLS");
	gotoxy(50, 9);
	cout << "***************************************************************" << endl;
	gotoxy(50, 10);
	cout << "*                                                             *" << endl;
	gotoxy(50, 11);
	cout << "*                                                             *" << endl;
	gotoxy(50, 12);
	cout << "*                                                             *" << endl;
	gotoxy(50, 13);
	cout << "*                       User Input                            *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);
	system("PAUSE");
	system("cls");
	

	//Code to validate user input
	string firstName, lastName, savingBal, checkingBal;
	int invalidChractersFN = 0, invalidChractersLN = 0, invalidChractersSB = 0, invalidChractersCB = 0;

	int numoccur = 0;

	cout << "Please enter your first name: \n";
	cin >> firstName;
	invalidChractersFN = validate(firstName, "isalpha");

	cout << "Please enter our last name: \n";
	cin >> lastName;
	invalidChractersLN = validate(lastName, "isalpha");

	cout << "Please enter your Savings Balance: \n";
	cin >> savingBal;
	invalidChractersSB = validate(savingBal, "isdigit");


	cout << "Please enter your Checking Balance: \n";
	cin >> checkingBal;
	invalidChractersCB = validate(checkingBal, "isdigit");



	if (invalidChractersFN > 0)
	{
		cout << "You have " << invalidChractersFN << " invalid characters in first name" << endl;
	}

	if (invalidChractersLN > 0)
	{
		cout << "You have " << invalidChractersLN << " invalid characters in last name" << endl;
	}

	if (invalidChractersSB > 0)
	{
		cout << "You have " << invalidChractersSB << " invalid characters in savingBal" <<  endl;
	}

	if (invalidChractersCB > 0)
	{
		cout << "You have " << invalidChractersCB << " invalid characters in savingBal" << endl;
	}


	system("PAUSE");

}


void mainMenu()
{
	//Instances of bank and list classes
	Bank myBank;
	List list;

	char selection;

	myBank.readDataFromFile();

	//Main menu that calls submenu's (defined above)
	do
	{
		system("Color 1A");
		system("CLS");
		gotoxy(50, 9);
		cout << " Farmingdale Computer Systems Banking System\n";
		gotoxy(50, 10);
		cout << " ============================================\n";
		gotoxy(50, 11);
		cout << " 1. Find Account\n";
		gotoxy(50, 12);
		cout << " 2. Make Withdrawal\n";
		gotoxy(50, 13);
		cout << " 3. Make Deposit";
		gotoxy(50, 14);
		cout << " 4. See Accounts\n";
		gotoxy(50, 15);
		cout << " 5. User Input\n";
		gotoxy(50, 16);
		cout << " 6. Exit\n";
		gotoxy(50, 17);
		cout << " ============================================\n";
		gotoxy(50, 18);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':
			getAccount(list, myBank);
			break;

		case '2':
			withdraw(list, myBank);
			break;
		case '3':
			deposit(list, myBank);
			break;

		case '4':
			showAccounts(list, myBank);
			break;

		case '5':
			userInput(list, myBank);
			break;

		case '6':
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}

	} while (selection != 6);


}
