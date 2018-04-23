#include <iostream>
#include "Alt.h"
#include "Bank_Menu.h"
#include "Banking_Functions.h"
#include <string>
#include <cctype>
#include <iomanip>
#include "linkedListFunctions.h"

using namespace std;

bankSkeleton myBank;
LinkedListFunctions myFunctions;

int invalidChractersFN = 0, invalidChractersLN = 0, invalidChractersID = 0;


string withdrawCheckingFirstName, withdrawCheckingLastName, withdrawSavingsFirstName, withdrawSavingsLastName;
string depositCheckingFirstName, depositCheckingLastName, depositSavingsFirstName, depositSavingsLastName;
string findAccFirstName, findAccLastName;
char accountType;
string checkingAcc = "Checking";
string savingsAcc = "Savings";
void splashScreen()
{
	system("CLS");
	system("Color 2B");

	myFunctions.add("Chris", "Belyski", 2000.00, 500.00);
	myFunctions.add("David", "Hartglass", 1500.00, 700.00);
	myFunctions.add("Brandon", "Livingston", 2500.00, 600.00);


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
void getAccount()
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

	gotoxy(50, 20);
	cout << endl;
	gotoxy(50, 22);
	cout << "Enter the name under the account you are searching for: ";
	cin >> findAccFirstName >> findAccLastName;
	myFunctions.findAccount(findAccFirstName, findAccLastName);
	system("PAUSE");

}


void withdraw()
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
		cout << "1. Make a withdrawal\n";
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
			system("CLS");
			gotoxy(50, 31);
			//myBank.readDataFromFile();
			myFunctions.displayList();
			cout << "Which account would you like to withdraw from, Checking(c) or Savings(s)?: ";
			cin >> accountType;

			cout << "Account Type: " << accountType << endl;
			if (accountType == 'c' || 'C')
			{
				cout << "Enter the name under the Checking Account " << endl;
				cout << "First Name: ";
				cin >> withdrawCheckingFirstName;
				invalidChractersFN = validate(withdrawCheckingFirstName, "isalpha");
				cout << "Last Name: "; cin >> withdrawCheckingLastName;
				invalidChractersFN = validate(withdrawCheckingLastName, "isalpha");

				if (invalidChractersFN > 0)
				{
					cout << "You have " << invalidChractersFN << " invalid characters in first name" << endl;
				}

				if (invalidChractersLN > 0)
				{
					cout << "You have " << invalidChractersLN << " invalid characters in last name" << endl;
				}

				cout << endl;
				myFunctions.checkingWithdraw(withdrawCheckingFirstName, withdrawCheckingLastName);
			}
			else if(accountType == 's' || 'S')
			{
				cout << "Enter the name under the Savings Account: " << endl;
				cout << "First Name: ";
				cin >> withdrawSavingsFirstName;
				invalidChractersFN = validate(withdrawSavingsFirstName, "isalpha");
				cout << "Last Name: "; cin >> withdrawSavingsLastName;
				invalidChractersLN = validate(withdrawSavingsLastName, "isalpha");
				cout << endl;
				if (invalidChractersFN > 0)
				{
					cout << "You have " << invalidChractersFN << " invalid characters in first name" << endl;
				}

				if (invalidChractersLN > 0)
				{
					cout << "You have " << invalidChractersLN << " invalid characters in last name" << endl;
				}
				cout << endl;
				myFunctions.savingsWithdraw(withdrawSavingsFirstName, withdrawSavingsLastName);
			}

			break;

		case '2':
			system("CLS");
			cout << "Enter the name under the account you are searching for: " << endl;
			cout << "First Name: "; cin >> findAccFirstName;
			invalidChractersFN = validate(findAccFirstName, "isalpha");
			cout << "Last Name: "; cin >> findAccLastName;
			invalidChractersLN = validate(findAccLastName, "isalpha");

			if (invalidChractersFN > 0)
			{
				cout << "You have " << invalidChractersFN << " invalid characters in first name" << endl;
			}

			if (invalidChractersLN > 0)
			{
				cout << "You have " << invalidChractersLN << " invalid characters in last name" << endl;
			}

			cout << endl;
			myFunctions.findAccount(findAccFirstName, findAccLastName);

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


void deposit()
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

	gotoxy(50, 23);
	cout << "MENU OPTIONS: \n";
	gotoxy(50, 24);
	cout << "1. Make a deposit\n";
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
			myFunctions.displayList();
			cout << "Which account would you like to deposit to, Checking(c) or Savings(s)?: ";
			cin >> accountType;

			cout << "Account Type: " << accountType << endl;
			if (accountType == 'c' || 'C')
			{
				cout << "Enter the name under the Checking Account: " << endl;
				cout << "First Name: "; cin >> depositCheckingFirstName;
				cout << "Last Name: "; cin >> depositCheckingLastName;
				myFunctions.checkingDeposit(depositCheckingFirstName, depositCheckingLastName);
			}
			else if (accountType == 's' || 'S')
			{
				cout << "Enter the name under the Savings Account: " << endl;
				cin >> depositSavingsFirstName >> depositSavingsLastName;
				myFunctions.savingsDeposit(depositSavingsFirstName, depositSavingsLastName);
			}
			break;

		case '2':
			myFunctions.displayList();
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


void showDatabase()
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
	cout << "*                       Show Database                         *" << endl;
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
		cout << "1. Display all customer accounts\n";
		gotoxy(50, 25);
		cout << "x. Return to main menu\n";

		gotoxy(50, 28);
		cout << "Enter choice: ";

		gotoxy(64, 28);
		cin >> choice;

		switch (choice)
		{
		case '1':
			gotoxy(50, 30);
			myFunctions.displayList();
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



void addOrDelete()
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
	cout << "*                      Add or Delete an Account               *" << endl;
	gotoxy(50, 14);
	cout << "*                                                             *" << endl;
	gotoxy(50, 15);
	cout << "*                                                             *" << endl;
	gotoxy(50, 16);
	cout << "*                                                             *" << endl;
	gotoxy(50, 17);
	cout << "***************************************************************" << endl;
	gotoxy(50, 18);

	char choice = 'a';
	while (choice != 'x' || 'X')
	{
		gotoxy(50, 23);
		cout << "MENU OPTIONS: \n";
		gotoxy(50, 24);
		cout << "1. Add an account \n";
		gotoxy(50, 25);
		cout << "2. Delete an account \n";
		gotoxy(50, 26);
		cout << "x. Exit \n";



		gotoxy(50, 29);
		cout << "Enter choice: ";

		gotoxy(64, 29);
		cin >> choice;
		string fname, lname;

		switch (choice)
		{
		case '1':
			break;

		case '2':
			myFunctions.displayList();

			cout << "First Name: "; cin >> fname;
			invalidChractersFN = validate(findAccFirstName, "isalpha");
			cout << "Last Name: "; cin >> lname;
			invalidChractersLN = validate(findAccLastName, "isalpha");
			myFunctions.deleteNode(fname, lname);

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

		system("PAUSE");
		system("cls");
	
	}
}


void mainMenu()
{


	char selection;

	do
	{
		system("Color 1A");
		system("CLS");
		gotoxy(50, 9);
		cout << " Farmingdale Computer Systems Banking System\n";
		gotoxy(50, 10);
		cout << " ====================================\n";
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
		cout << " ====================================\n";
		gotoxy(50, 18);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':
			getAccount();
			break;

		case '2':
			withdraw();
			break;
		case '3':
			deposit();
			break;

		case '4':
			showDatabase();
			break;

		case '5':
			addOrDelete();
			break;

		case '6':
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}

	} while (selection != 6);
}

int validate(string input, string checkType)
{
	int numoccur = 0;

	if (checkType == "isalpha")
	{
		for (int x = 0; x < input.length(); x++)
		{
			if (!isalpha(input[x]))
				numoccur++;
		}
	}


	if (checkType == "isdigit")
	{
		for (int x = 0; x < input.length(); x++)
		{
			if (!isdigit(input[x]))
				numoccur++;
		}
	}

	return numoccur;

}
