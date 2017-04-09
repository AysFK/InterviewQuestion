// ReplaceBlack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>

//========���Ժ���=======
//4.�滻�ַ����еĿո�Ϊ��%20�� 
void ReplaceBlank(char string[], int length)
{
	if (string == NULL && length <= 0)
		return;
	int i = 0;
	int originalLength = 0;
	int blankNums = 0;
	while (string[i] != '\0')
	{
		originalLength++;
		if (string[i] == ' ')
			blankNums++;
		i++;
	}
	int newLength = originalLength + blankNums * 2;
	if (newLength > length)
		return;
	int index1 = originalLength;
	int index2 = newLength;
	while (index1 >= 0 && index1 < index2)
	{
		if (string[index1] == ' ')
		{
			string[index2--] = '0';
			string[index2--] = '2';
			string[index2--] = '%';
		}
		else
			string[index2--] = string[index1];
		index1--;
	}
}

//========���Դ���========
void TEST(char* testName, char string[], int length, char expected[])
{
	if (testName != NULL)
		printf("%s begin:", testName);
	ReplaceBlank(string, length);
	if (string == NULL && expected == NULL)
		printf("passed!\n");
	else if (string == NULL && expected != NULL)
		printf("failed!\n");
	else if (strcmp(expected, string) == 0)
		printf("passed!\n");
	else
		printf("failed!\n");
}
//========��������========
//�׿ո�
void test1()
{
	const int length = 100; //const -> string[length]
	char string[length] = " BlankAtBegin";
	TEST(__FUNCTION__, string, length, "%20BlankAtBegin");
}
//ĩ�ո�
void test2()
{
	const int length = 100;
	char string[length] = "BlankAtEnd ";
	TEST(__FUNCTION__, string, length, "BlankAtEnd%20");
}
//�пո�
void test3()
{
	const int length = 100;
	char string[length] = "BlankAt Middle";
	TEST(__FUNCTION__, string, length, "BlankAt%20Middle");
}
//�޿ո�
void test4()
{
	const int length = 100;
	char string[length] = "NoBlank";
	TEST(__FUNCTION__, string, length, "NoBlank");
}
//ȫ�ո�
void test5()
{
	const int length = 100;
	char string[length] = "   ";
	TEST(__FUNCTION__, string, length, "%20%20%20");
}
//�����ո�
void test6()
{
	const int length = 100; 
	char string[length] = "Tow  Blank";
	TEST(__FUNCTION__, string, length, "Tow%20%20Blank");
}
//���ַ���
void test7()
{
	const int length = 100;
	char string[length] = "";
	TEST(__FUNCTION__, string, length, "");
}
//NULL
void test8()
{
	TEST(__FUNCTION__, NULL, 0, NULL);
}
//========main========
int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}

