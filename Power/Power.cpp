// Power.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

//==================���⺯��=================
bool g_InvalidInput = false;

bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = unsigned int(exponent);
	if (exponent < 0)
		absExponent = (-1 * exponent);
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i =0; i<exponent; i++)
	{
		result *= base;
	}
	return result;
}

//PS: �ݹ���ۣ�
double PowerWithUnsignedExponent2(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	//a^(n/2) * a^(n/2)
	double result = PowerWithUnsignedExponent2(base, exponent >> 1);
	result *= result;
	//need a^(n/2) * a^(n/2) * a
	if (exponent & 0x1 == 1)
		result *= base;
	return result;
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001))
		return true;
	else
		return false;
}

//==================���Ժ���=================
void TEST(char* testname, double base, int exponent, double expectedResult, bool expectFlag)
{
	double result = Power(base, exponent);
	if (abs(result - expectedResult) < 0.0000001 && g_InvalidInput == expectFlag)
		printf("%s passed!\n", testname);
	else
		printf("%s failed!\n", testname);
}

//==================main����=================
int main()
{
	TEST("Test", 2, 3, 8, false);
	TEST("Test", -2, 3, -8, false);
	TEST("Test", 2, -3, 0.125, false);
	TEST("Test", 2, 0, 1, false);
	TEST("Test", 0, 4, 0, false);
	TEST("Test", 0, -4, 0, true);
    return 0;
}

