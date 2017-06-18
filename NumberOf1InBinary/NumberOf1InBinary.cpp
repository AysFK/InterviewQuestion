// NumberOf1InBinary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//================被测函数==================
int Numberof1_s1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}

	return count;
}

int Numberof1_s2(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}

	return count;
}

//=================测试函数================
void TEST(int number, int expected)
{
	int result1 = Numberof1_s1(number);
	if (result1 == expected)
		printf("Solution1: Test for %d passed.\n", number);
	else
		printf("Solution1: Test for %d failed.\n", number);

	int result2 = Numberof1_s2(number);
	if (result2 == expected)
		printf("Solution2: Test for %d passed.\n", number);
	else
		printf("Solution2: Test for %d passed.\n", number);

	printf("\n");
}
//=================main函数================
int _tmain(int argc, _TCHAR* argv[])
{
	TEST(0,0);

	TEST(1,1);

	TEST(2,1);
	
	//10: 1010
	TEST(10,2);
	
	//0xFFFFFFFF
	//计算机识别为补码，求原码
	//补码减一：	0xFFFFFFFE
	//求反码：	0x80000001,即-1
	TEST(0xFFFFFFFF,32);

	//0x7FFFFFFF
	//计算机识别为原码,即2147483648
	TEST(0x7FFFFFFF,31);

	//0x80000000: 1000 0000 ...
	TEST(0x80000000,1);
	return 0;
}