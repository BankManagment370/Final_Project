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
	
	art += "  __                                                                              __                          \n";
	art += "|/  |           /         /|/|                                         /         /              /             \n";
	art += "|___| ___  ___ (         ( / | ___  ___  ___  ___  ___  _ _  ___  ___ (___      (___       ___ (___  ___  _ _ \n";
	art += "|   )|   )|   )|___)     |   )|   )|   )|   )|   )|___)| | )|___)|   )|             )\\   )|___ |    |___)| | )\n";
	art += "|__/ |__/||  / | \\       |  / |__/||  / |__/||__/ |__  |  / |__  |  / |__        __/  \\_/  __/ |__  |__  |  / \n";
	art += "                                             __/                                       /                        \n";                                                         _       ___                 _\n";


	cout << art;
	cin.get();
	splashScreen();
	mainMenu();
	return 0;
}
