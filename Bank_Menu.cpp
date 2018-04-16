#include <iostream>
#include "Alt.h"
#include "Bank_Menu.h"
#include <string>
#include <cctype>

using namespace std;


void splashScreen()
{
	system("CLS");
	system("Color 2B");



	gotoxy(50, 9);
	cout <<"  __                                                                              __                          \n";
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
	system("PAUSE");

}

//int validate(string input, string checkType)
//{
//	int numoccur = 0;
//
//	if (checkType == "isalpha")
//	{
//		for (int x = 0; x < input.length(); x++)
//		{
//			if (!isalpha(input[x]))
//				numoccur++;
//		}
//	}
//
//
//	if (checkType == "isdigit")
//	{
//		for (int x = 0; x < input.length(); x++)
//		{
//			if (!isdigit(input[x]))
//				numoccur++;
//		}
//	}
//
//	return numoccur;
//
//}

void userInput()
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

	string firstName, lastName, studentID;
	int invalidChractersFN = 0, invalidChractersLN = 0, invalidChractersID = 0;;

	int numoccur = 0;

	/*cout << "Please enter your first name: \n";
	cin >> firstName;
	invalidChractersFN = validate(firstName, "isalpha");

	cout << "Please enter our last name: \n";
	cin >> lastName;
	invalidChractersLN = validate(lastName, "isalpha");

	cout << "Please enter your student ID #: \n";
	cin >> studentID;
	invalidChractersID = validate(studentID, "isdigit");*/



	if (invalidChractersFN > 0)
	{
		cout << "You have " << invalidChractersFN << " invalid characters in first name" << endl;
	}

	if (invalidChractersLN > 0)
	{
		cout << "You have " << invalidChractersLN << " invalid characters in last name" << endl;
	}

	if (invalidChractersID > 0)
	{
		cout << "You have " << invalidChractersID << " invalid characters in student id" << endl;
	}

	system("PAUSE");

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
			userInput();
			break;

		case '6':
			cout << "Goodbye.\n";
			return;
			
		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}

	} while (selection != 6);


}
