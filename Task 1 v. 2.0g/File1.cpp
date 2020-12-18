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
char fntc(long int k)
{
 switch (k)
			 {
				case 1 : return('1'); break;
				case 2 : return('2'); break;
				case 3 : return('3'); break;
				case 4 : return('4'); break;
				case 5 : return('5'); break;
				case 6 : return('6'); break;
				case 7 : return('7'); break;
				case 8 : return('8'); break;
				case 9 : return('9'); break;
				case 0 : return('0'); break;
				default : break;
			 }
}

int fctn(char s)
{
  switch (s)
			 {
				case '1' : return(1); break;
				case '2' : return(2); break;
				case '3' : return(3); break;
				case '4' : return(4); break;
				case '5' : return(5); break;
				case '6' : return(6); break;
				case '7' : return(7); break;
				case '8' : return(8); break;
				case '9' : return(9); break;
				case '0' : return(0); break;
				default : break;
			 }
}

int fctn12(char s)
{
  switch (s)
			 {
				case '1' : return(1); break;
				case '2' : return(2); break;
				case '3' : return(3); break;
				case '4' : return(4); break;
				case '5' : return(5); break;
				case '6' : return(6); break;
				case '7' : return(7); break;
				case '8' : return(8); break;
				case '9' : return(9); break;
				case '0' : return(0); break;
				case 'A' : return(10); break;
				case 'B' : return(11);  break;
				default : break;
			 }
}
int _tmain(int argc, _TCHAR* argv[])
{
	char ed;

	string str1;
	int i, ch, j;
	long int perexod, numb;
	char *str = new char [11];

	str1 = "";  // число в десятичной
	gets(str);
	 for (j = 0; j < strlen(str); j++)
	 {
			ch = fctn12(str[j]);
			perexod = 0;
			for (i = 0; i < len(str1); i++)
			{
				numb = fctn(str1[i]);
				numb *= 12;
				numb += perexod % 10;
				str1[i] = fntc(numb % 10);
				perexod = numb/10;
			}
			while (perexod > 0)
			{
				ed = fntc(perexod % 10);
				perexod /= 10;
				str1 += ed;
			}

			perexod = ch;
			for (i = 0; i < len(str1); i++)
			{
				numb = fctn(str1[i]);
				numb += perexod % 10;
				str1[i] = fntc(numb % 10);
				perexod = perexod/10;
			}
			while (perexod > 0)
			{
				ed = fntc(perexod % 10);
				perexod /= 10;
				str1 += ed;
			}
		}


	numb = 0;

	for (i = len(str1)-1; i >= 0; i--)
	{
	numb =numb * 10 +fctn(str1[i]);
	}

	str1 = "";

	while (numb > 8)                                    // Перевод в 9 систему
	{
		ed = fntc(numb % 9);
		numb /= 9;
		str1 += ed;
	}

	cout << numb;                                      // Вывод числа в 9 системе
	for (i = len(str1) - 1; i >= 0; i--)
	{
		cout << str1[i];
	}
	getch();
	return 0;
}
