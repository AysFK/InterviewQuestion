#include "stdafx.h"
#include <iostream>
using namespace std;

int StrToInt(char* str);//declare

char str[100];

char* IntToStr(int num)
{
	int i = 0, j = 0;
	char temp[100];
	while (num)
	{
		temp[i] = num % 10 + '0';// + 48
		num = num / 10;
		i++;
	}
	temp[i] = 0;
	i--;
	while (i > -1)
	{
		str[j] = temp[i];
		i--; j++;
	}
	str[j] = 0;
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//IntToStr
	char *str = IntToStr(12345);
	cout << str << endl;
	//StrToInt
	int num = StrToInt("123456");//printf("%s\n", str);
	cout << num - 1<< endl;
	return 0;
}



