// Datastructure.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

//=======被测函数=======
//Ex3.行列均为增序的二维数组matrix，查找一元素number
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
//=======测试代码=======
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

//=======测试用例=======
/*
1 2 8  9
2 4 9  12
4 7 10 13
6 8 11 15
*/
//在数组中
void test1()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test1", (int*)array, 4, 4, 2, true);
}

//不在数组中
void test2()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test2", (int*)array, 4, 4, 3, false);
}

//最小数
void test3()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test3", (int*)array, 4, 4, 1, true);
}

//最大数
void test4()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test4", (int*)array, 4, 4, 15, true);
}

//比最小数小
void test5()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test5", (int*)array, 4, 4, -5, false);
}

//比最大数大
void test6()
{
	int array[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TEST("test6", (int*)array, 4, 4, 17, false);
}

//空指针
void test7()
{
	TEST(__FUNCTION__, NULL, 4, 4, 2, false);//__FUNCTION__函数名
}

//=======主函数=======
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