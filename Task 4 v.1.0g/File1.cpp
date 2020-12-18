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
				case 10 : return('A'); break;
				case 11 : return('B'); break;
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
				case 'A' : return(10); break;
				case 'B' : return(11);  break;
				default : break;
			 }
}

string add(string numb1, string numb2)
{
	int i, a, b, perexod;
	perexod = 0;
	string answ;
			for (i = len(numb1)-1; i >= 0; i--)
		{
			a = fctn( numb1[i] );
			b = fctn( numb2[i] );
			if (perexod != 0)
			{
				answ = fntc ( (a + b + perexod) % 12) + answ;
				perexod--;
			}
			else
			{
				answ = fntc ( (a + b) % 12) + answ;
			}
			if (a + b + 1 > 11)
			{
				perexod++;
			}
		}
		if (perexod != 0)
			{
				answ = '1' + answ;
				perexod--;
			}
	return(answ);
}

string sub(string numb1, string numb2)
{       
	int i, a, b, perexod;
	perexod = 0;
	string answ;
			for (i = len(numb1)-1; i >= 0; i--)
		{
			a = fctn( numb1[i] );
			b = fctn( numb2[i] );
			if (perexod == 0) 
			{
				if (a >= b)
				{
					answ = fntc ( (a - b) % 12) + answ;
				}
				else
				{
					answ = fntc ( (a + 12 - b) % 12) + answ;
					perexod--;
				}
			}
			else
			{
				if (a >= b)
				{
					answ = fntc ( (a - b + perexod) % 12) + answ;
				}
				else
				{
					answ = fntc ( (a + 12 - b + perexod) % 12) + answ;
					perexod--;
				}	
			}
		}
		return(answ);
}
int _tmain(int argc, _TCHAR* argv[]) 
{
	string numb1, numb2, act, answ, vspomog;
	int i, perexod, a, b;
	cout << "enter the first number: ";
	cin >> numb1;
	cout << "enter the second number: ";
	cin >> numb2;
	cout << "do you want to subtract or add these numbers? sub/add: ";
	cin >> act;
	bool f1, f2;  // указатели на отрицательность
	f1 = false; f2 =false;

	vspomog = "";
	if (numb1[0] == '-') 
	{
		f1 = true;
		for (i = 1; i < len(numb1); i++) 
		{
			vspomog = vspomog + numb1[i];		
		}
		numb1 = vspomog;  
	}
	vspomog = "";
	if (numb2[0] == '-') 
	{
		f2 = true;
		for (i = 1; i < len(numb2); i++) 
		{
			vspomog = vspomog + numb2[i];		
		} 
		numb2 = vspomog;     
	}


	if (len(numb1) > len(numb2))
	{
		while (len(numb1) != len(numb2))
		{
			numb2 = '0' + numb2;
		}
	}
	else
	{
		while (len(numb1) != len(numb2))
		{
			numb1 = '0' + numb1;
		}
	}

	bool f3;
	f3 = false;
	for (i = 0; i < len(numb1); i++)
	{
		a = fctn(numb1[i]);
		b = fctn(numb2[i]);
		if (a > b) 
		{
		 f3 = false;
		 break;    
		}
		if (a < b) 
		{     
		 f3 = true;
		 break;    
		}
	}
	bool f4;
	if (f3)
	{
	answ = numb1;
	numb1 = numb2;
	numb2 = answ;
	answ = "";
	f4 = f1;
	f1 = f2;
	f2 = f4;	
	}		
	perexod = 0;
	if (act == "add")
	{
		if (f1 && f2) 
		{
		cout << "-" ;
		answ = add(numb1, numb2);
		}
		if (f1 == false && f2 == false) 
		{
		answ = add(numb1, numb2);    
		}
		if (f1 == false && f2) 
		{
		answ = sub(numb1, numb2);	
		}
		if (f1 && f2 == false) 
		{
		cout << "-";
		answ = sub(numb1, numb2);	
		}
		
	}
	if (act == "sub") 
	{
		if (f1 && f2) 
		{
			if (f3 = false) 
			{
			cout << "-" ;
			}
		answ = sub(numb1, numb2);
		}
		if (f1 == false && f2 == false) 
		{
		answ = sub(numb1, numb2); 
			if (f3) 
			{
			 cout << "-";
			}   
		}
		if (f1 == false && f2) 
		{
			if (f3) 
			{
			cout << "-" ;
			}
		answ = add(numb1, numb2);	
		}
		if (f1 && f2 == false) 
		{
			if (f3 = false) 
			{
			cout << "-" ;
			}
		answ = add(numb1, numb2);	
		}	
	}

	f3 = false;
   for (i = 0; i < len(answ); i++)
   {
	if (answ[i] != '0') 
	{
	 f3 = true;
	}	
	if (f3) 
	{
	 cout << answ[i];	
	}   
   }
	getch();
	return 0;
}
