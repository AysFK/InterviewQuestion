// Datastructure.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

//=======���⺯��=======
//Ex3.���о�Ϊ����Ķ�ά����matrix������һԪ��number
bool Find(int* matrix, int row, int col, int number)
{
	bool found = false;
	if (matrix != NULL && row > 0 && col > 0)
	{

		int r = 0, c = col - 1;
		while (r < row && c >= 0)
		{
			if (number == matrix[r*col + c])
			{
				found = true;
				break;
			}
			else if (number < matrix[r*col + c])
				c--;
			else if (number > matrix[r*col + c])
				r++;
		}
	}
	return found;
}
//=======���Դ���=======
void TEST(char* testName, int* matrix, int row, int col, int number, bool expected)
{
	if (testName != NULL)
	{
		printf("%s begin:", testName);
	}
	bool result = Find(matrix, row, col, number);
	if (result == expected)
		printf("passed\n");
	else
		printf("failed\n");
}

//=======��������=======
/*
1 2 8  9
2 4 9  12
4 7 10 13
6 8 11 15
*/
//��������
void test1()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test1", (int*)array, 4, 4, 2, true);
}

//����������
void test2()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test2", (int*)array, 4, 4, 3, false);
}

//��С��
void test3()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test3", (int*)array, 4, 4, 1, true);
}

//�����
void test4()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test4", (int*)array, 4, 4, 15, true);
}

//����С��С
void test5()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test5", (int*)array, 4, 4, -5, false);
}

//���������
void test6()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test6", (int*)array, 4, 4, 17, false);
}

//��ָ��
void test7()
{
	TEST(__FUNCTION__, NULL, 4, 4, 2, false);//__FUNCTION__������
}

//=======������=======
int main(int argc, TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}