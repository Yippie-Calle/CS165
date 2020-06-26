//
//      startMenu.cpp
//      startMenu
//

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <cstdlib> 
#include <sstream>
#include <cstring>
using namespace std;
#include "startMenu.h"

void Start::startMenuOptions()
{
	cout << "Options:\n";
	cout << "   ?  Show the instructions\n";
	cout << "   S  Start game\n";
	cout << "   Q  Quit\n";
}

void Start::instructions()
{
	cout << "Use error keys to move.\n";
	cout << "You must guide the lander safetly from the starting point to the landing pad.\n";
	cout << "To land successfull, the Lander must: ";
	cout << "have its center within the horizontal boundaries of the platform.\n";
	cout << "Every time you thrust you will cause fuel to go down.\n";
	cout << " You lose if your lander crashes or your fuel reaches zero.\n";
}
void Start::executeCommand()
{
	option = 'z';

	while (option != 'Q')
	{
		cout << "> ";
		cin >> option;
		option = toupper(option);
		switch (option)
		{
		case '?':
			instructions();
			cout << endl
				<< endl;
			break;
		case 'D':
			//display(board);
			cout << endl;
			break;
		default:
			break;
		}
	}
}

void Start::playAgain()
{
	response = 0;
	executeCommand();
}
