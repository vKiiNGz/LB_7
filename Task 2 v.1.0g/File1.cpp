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
#include <string>
#include <cstring>

using namespace std;
int len(string str)
{
	int i;
	for (i = 0; i < 1000000; i++)
	{
		if (str[i] == '\0')
		{
			return (i);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[]) 
{
	string s1;
	bool f;
	cin >> s1;
	f = true;
	int i;
	long int b = 0;
	if (s1[0] == '0')
	{
		f = false;
	}
	for (i = 1; i < len(s1); i++)
	{

		if (s1[i] == '0' && f)
		{
			b += pow(2, len(s1)-i-1);
		}

		if (s1[i] == '1' && f == false)
		{
			b += pow(2, len(s1)-i-1);
		}

	}
	if (f)
	{
		b *= -1;
	}
	cout << b;
    getch();
	return 0;
}
