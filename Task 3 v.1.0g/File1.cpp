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
string esinob(int c)
{
	string s;
	int i;
	if (c < 0)
	{
		c *= -1;
		while (c > 0)
		{
			if (c % 2 == 0)
			{
				s = '1' + s;
			}
			else
			{
				s = '0' + s;
			}
			c /= 2;
		}
		while (len(s) < 100)
		{
			s = '1' + s;
		}
		s = '1' + s;
	}
	else
	{
			while (c > 0)
		{
			if (c % 2 == 0)
			{
				s = '0' + s;
			}
			else
			{
				s = '1' + s;
			}
			c /= 2;
		}
		while (len(s) < 100)
		{
			s = '0' + s;
		}
		s = '0' + s;
	}
	return(s);
}
string sym(string s1, string s2, int k)
{
int i;
string s3;
for (i = len(s1)-1; i >= 0; i--)
	{
		if (s1[i] == '1'  && s2[i] == '1')
		{
			
			if (k != 0)
			{
				s3 = '1' + s3;
				k--;
			}
			else
			{
				s3 = '0' + s3;
			}
			k++;
		}

		if (s1[i] == '0'  && s2[i] == '0')
		{
			if (k != 0)
			{
				s3 = '1' + s3;
				k--;
			}
			else
			{
				s3 = '0' + s3;
			}
		}

		if ((s1[i] == '1'  && s2[i] == '0') || (s1[i] == '0'  && s2[i] == '1'))
		{
			if (k != 0)
			{
				s3 = '0' + s3;
			}
			else
			{
				s3 = '1' + s3;
			}
		}
	}
return(s3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, i;
	string number1, number2, symma;
	number1 = ""; number2 = ""; symma = "";
	cin >> a >> b;
	number1 = esinob(a); number2 = esinob(b);
	int perexod;
	perexod = 0;
	symma = sym(number1, number2, perexod);
	if (perexod != 0)
	{
		number1 = "";
		for (i = 0; i < len(number2)-1; i++)
		{
			number1 += '0';
		}
		number1 = number1 + '1';
		number2 = symma;
		symma = "";
		perexod = 0;
		symma = sym(number1, number2, perexod);
	}

	
	if (symma[0] == '0')
	{
		bool f = false;
		number1 = symma;
		symma = "";
		symma = symma + '0';
		for (i = 1; i < len(number1); i++)
		{
			if (number1[i] == '1')
			{
				f = true;
			}
			if (f) 
			{
				symma = symma + number1[i];
			}	 
		}	 
		cout << symma;
	}
	
	else 
	{
		number1 = "";
		for (i = 0; i < len(number2)-1; i++)
		{
			number1 += '0';
		}
		number1 = number1 + '1';
		number2 = symma;
		symma = "";
		perexod = 0;
		symma = sym(number1, number2, perexod);
		if (perexod != 0)
		{
			number1 = "";
			for (i = 0; i < len(number2)-1; i++)
			{
				number1 += '0';
			}
			number1 = number1 + '1';
			number2 = symma;
			symma = "";
			perexod = 0;
			symma = sym(number1, number2, perexod);
			}

		bool f = false;
		number1 = symma;
		symma = "";
		symma = symma + '1';
		for (i = 1; i < len(number1); i++)
		{
			if (number1[i] == '0')
			{
				f = true;
			}
			if (f) 
			{
				symma = symma + number1[i];
			}	 
		}
		cout << symma;
    }

	getch();
	return 0;
}
