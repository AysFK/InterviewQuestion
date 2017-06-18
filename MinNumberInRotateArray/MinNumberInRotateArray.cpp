// MinNumberInRotateArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
using namespace std;

// ====================被测函数====================
int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index2])
			return MinInOrder(numbers, index1, index2);
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (result >= numbers[i])
			result = numbers[i];
	}
	return result;
}
// ====================测试代码====================
void TEST(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);
		for (int i = 0; i < length; i++)
		{
			printf("%d ", numbers[i]);
		}
		if (result == expected)
			printf("\tPassed\tMin:%d\n",result);
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == NULL)
			printf("Test Passed.\n");
		else
			printf("Test faild.\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	//一般旋转数组
	int array1[] = { 3, 4, 5, 1, 2 };
	TEST(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，重复数为最小
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	TEST(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，一般重复
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	TEST(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，重复为第一，最后和最小
	int array4[] = { 1, 0, 1, 1, 1 };
	TEST(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素
	int array5[] = { 1, 2, 3, 4, 5 };
	TEST(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	TEST(array6, sizeof(array6) / sizeof(int), 2);

	// 输入NULL
	TEST(NULL, 0, 0);
	return 0;
}

