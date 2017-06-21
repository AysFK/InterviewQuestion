// NumberOf1InBinary.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//================���⺯��==================
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

//=================���Ժ���================
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
//=================main����================
int _tmain(int argc, _TCHAR* argv[])
{
	TEST(0,0);

	TEST(1,1);

	TEST(2,1);
	
	//10: 1010
	TEST(10,2);
	
	//0xFFFFFFFF
	//�����ʶ��Ϊ���룬��ԭ��
	//�����һ��	0xFFFFFFFE
	//���룺	0x80000001,��-1
	TEST(0xFFFFFFFF,32);

	//0x7FFFFFFF
	//�����ʶ��Ϊԭ��,��2147483648
	TEST(0x7FFFFFFF,31);

	//0x80000000: 1000 0000 ...
	TEST(0x80000000,1);
	return 0;
}