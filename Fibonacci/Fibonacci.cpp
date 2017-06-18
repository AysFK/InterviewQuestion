// Fibonacci.cpp : 定义控制台应用程序的入口点。
//

/*#include "stdafx.h"
#include <iostream>
#include <sys/timeb.h>
#include <ctime>
#include <climits>
using namespace std;

int TEST(int n)
{
	if (n == 1)
		return 1;
	if (n <= 0)
		return 0;
	return TEST(n - 1) + TEST(n - 2);
}

long long TEST2(unsigned n)
{
	int result[] = { 0, 1 };
	if (n < 2)
		return result[n];
	long long FibOne = 1;
	long long FibTwo = 0;
	long long FibN = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		FibN = FibOne + FibTwo;
		FibTwo = FibOne;
		FibOne = FibN;
	}
	
	return FibN;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct timeb startTime, endTime;
	unsigned int n = 70;
	cout << "Fibonacci(" << n << ")=";
	ftime(&startTime);
	printf("%d\n",TEST2(n));
	ftime(&endTime);

	cout << "UseTime="<<(endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	return 0;
}*/

#include "stdafx.h"
#include <sys/timeb.h>
#include <ctime>
// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{
	if (n <= 0)
		return 0;

	if (n == 1)
		return 1;

	return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

// ====================方法2：循环====================
long long Fibonacci_Solution2(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long  fibNMinusOne = 1;
	long long  fibNMinusTwo = 0;
	long long  fibN = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

// ====================方法3：基于矩阵乘法====================
#include <cassert>

struct Matrix2By2
{
	Matrix2By2
	(
	long long m00 = 0,
	long long m01 = 0,
	long long m10 = 0,
	long long m11 = 0
	)
	:m_00(m00), m_01(m01), m_10(m10), m_11(m11)
	{
	}

	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
};

Matrix2By2 MatrixMultiply
(
const Matrix2By2& matrix1,
const Matrix2By2& matrix2
)
{
	return Matrix2By2(
		matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
		matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
		matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
		matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
	assert(n > 0);

	Matrix2By2 matrix;
	if (n == 1)
	{
		matrix = Matrix2By2(1, 1, 1, 0);
	}
	else if (n % 2 == 0)
	{
		matrix = MatrixPower(n / 2);
		matrix = MatrixMultiply(matrix, matrix);
	}
	else if (n % 2 == 1)
	{
		matrix = MatrixPower((n - 1) / 2);
		matrix = MatrixMultiply(matrix, matrix);
		matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
	}

	return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
	return PowerNMinus2.m_00;
}

// ====================测试代码====================
void Test(int n, int expected)
{
	struct timeb startTime1, endTime1, startTime2, endTime2, startTime3, endTime3;
	ftime(&startTime1);
	__int64 result1 = Fibonacci_Solution1(n);
	ftime(&endTime1);

	ftime(&startTime2);
	__int64 result2 = Fibonacci_Solution2(n);
	ftime(&endTime2);

	ftime(&startTime3);
	__int64 result3 = Fibonacci_Solution3(n);
	ftime(&endTime3);

	if (result1 == expected)
	{
		printf("Test for %d in solution1 passed.\n", n);
		printf("UseTime=%dms\n", (endTime1.time - startTime1.time) * 1000 + (endTime1.millitm - startTime1.millitm));
	}
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (result2 == expected)
	{
		printf("Test for %d in solution2 passed.\n", n);
		printf("UseTime=%dms\n", (endTime2.time - startTime2.time) * 1000 + (endTime2.millitm - startTime2.millitm));
	}
	else
		printf("Test for %d in solution2 failed.\n", n);

	if (result3 == expected)
	{
		printf("Test for %d in solution3 passed.\n", n);
		printf("UseTime=%dms\n", (endTime3.time - startTime3.time) * 1000 + (endTime3.millitm - startTime3.millitm));
	}
	else
		printf("Test for %d in solution3 failed.\n", n);
	
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(10, 55);
	Test(40, 102334155);

	return 0;
}
