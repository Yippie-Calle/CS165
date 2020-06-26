#include<iostream>
#include<conio.h>
#include<dos.h>
#include<Windows.h>
using namespace std;
#include "timer.h"

void Timer::timer()
{
	system("CLS");
	cout << HH << ":" << MM << ":" << SS;
	_getch();
	while (!_kbhit())
	{
		SS++;
		Sleep(1000);
		if (SS > 59)
		{
			MM++;
			SS = 0;
		}
		if (MM > 59)
		{
			HH++;
			MM = 0;
		}
	}
}

