#include "Bank_Menu.h"
#include "Alt.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("mode 650");
	system("Color 1A");
	system("cls");


	//string art = "";
	gotoxy(10, 1);
	cout << " ######   #####  #######  #####    #####  ####### ######  ### ###  # ###  ####### ### ### ######  #######  #####    ######  ######   #####      ### #######  # ###  #######\n";
	gotoxy(10, 2);
	cout << "####### ####### ####### #######  ####### ####### ####### ### ### ####### ####### ### ### ####### ####### #######    ####### ####### #######     ### ####### ####### #######\n";
	gotoxy(10, 3);
	cout << "### ### ### ###   ###   ### ###  ###       ###   ### ### ### ### ### ###   ###   ### ### ### ### ###     ###        ### ### ### ### ### ###     ### ###     ### ###   ###\n";
	gotoxy(10, 4);
	cout << "### ### #######   ###   #######   #####    ###   ######  ### ### ###       ###   ### ### ######  #######  #####     ######  ######  ### ### ### ### ####### ###       ###\n";
	gotoxy(10, 5);
	cout << "### ### ### ###   ###   ### ###      ###   ###   ### ### ### ### ### ###   ###   ### ### ### ### ###         ###    ###     ### ### ### ### ### ### ###     ### ###   ###\n";
	gotoxy(10, 6);
	cout << "#######  #  ###   ###    #  ###  #######   ###   ### ### ####### #######   ###   ####### ### ### ####### #######    ###     ### ### ####### ####### ####### #######   ###\n";
	gotoxy(10, 7);
	cout << "######  ### ###   ###   ### ###   #####    ###   ### ###  #####   #####    ###    #####  ### ### #######  #####     ###     ### ###  #####   #####  #######  #####    ###\n";
	gotoxy(0, 8);



	cin.get();
	splashScreen();
	mainMenu();
	return 0;
}
