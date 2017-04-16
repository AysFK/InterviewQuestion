#include "stdafx.h"
#include <iostream>
using namespace std;


int StrToInt(char *str)   //no illegal characters
{
	int sign = 1, num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return sign * num;
}