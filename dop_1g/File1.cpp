#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[]) 
{
	int x, b, i;
	cin >> b;
	x = b;
	while (x > 0)
	{
		for (i = 0; i < 5; i++) 
		{
			x -= 1;
		}
	}
	if (x == 0) 
	{
		cout <<	"the number is divisible by 5" << endl;
	}
	else
	{
		cout <<	"number is not divisible by 5" << endl;
	}

		x = b;
	while (x > 0)
	{
		for (i = 0; i < 29; i++) 
		{
			x -= 1;
		}
	}
	if (x == 0) 
	{
		cout <<	"the number is divisible by 29" << endl;
	}
	else
	{
		cout <<	"number is not divisible by 29" << endl;
	}

		x = b;
	while (x > 0)
	{
		for (i = 0; i < 223; i++) 
		{
			x -= 1;
		}
	}
	if (x == 0) 
	{
		cout <<	"the number is divisible by 223" << endl;
	}
	else
	{
		cout <<	"number is not divisible by 223" << endl;
	}
	getch();
	return 0;
}
