// Print1ToMaxOfNDigits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <time.h>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

//================= 方法一 ==================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int length = strlen(number);

	for (int i = length - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == length - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = nSum + '0';
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}

	return isOverflow;
}
//================= 方法二 ==================
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	printf("\n");
	delete[] number;
}
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}
//=================打印函数==============
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	for (int i = 0; i < strlen(number); i++)
	{
		if (number[i] != '0' && isBeginning0)
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}
//=================测试代码==============
void TEST(int n)
{
	
	printf("\n=====>Test1:\n");
	//o(n)
	time_t start, end;
	time(&start);
	Print1ToMaxOfNDigits_1(n);
	time(&end);
	printf("%fs\n", difftime(end, start));

	printf("\n=====>Test2:\n");
	//o(n)
	time(&start);
	Print1ToMaxOfNDigits_2(n);
	time(&end);
	printf("%fs\n", difftime(end, start));
}
int main()
{
	TEST(1);
	TEST(2);
	TEST(3);
	TEST(0);
	TEST(-1);
    return 0;
}

