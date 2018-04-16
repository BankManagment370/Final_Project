#include "Bank_Menu.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	system("mode 650");
	system("Color 1A");
	system("cls");

	//http://www.kammerl.de/ascii/AsciiSignature.php
	string art = "";


	        art += "___  ____ _  _ _  _    _  _ ____ _  _ ____ ____ ____ _  _ ____ _  _ ___    ____ _   _ ____ ___ ____ _  _\n"
		art += "|__] |__| |\ | |_/     |\/| |__| |\ | |__| | __ |___ |\/| |___ |\ |  |     [__   \_/  [__   |  |___ |\/|\n"
		art += "|__] |  | | \| | \_    |  | |  | | \| |  | |__] |___ |  | |___ | \|  |     ___]   |   ___]  |  |___ |  |\n"
		art += "                                                                                                        \n"

	cout << art;
	cin.get();
	splashScreen();
	mainMenu();
	return 0;
}
