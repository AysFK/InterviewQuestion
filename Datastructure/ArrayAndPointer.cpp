#include "stdafx.h"
//2.1数组和指针(数组作为函数参数传递时，退化为同类型的指针)
int GetSize(int data[])
{
	return sizeof(data);
}

/*int main(int argc, _TCHAR* argv[])
{
	//作为数组
	int data1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof(data1);
	//指针
	int* data2 = data1;
	int size2 = sizeof(data2);
	//参数时退化为指针
	int size3 = GetSize(data1);
	printf("size1 = %d  size2 = %d  size3 = %d\n", size1, size2, size3);
	return 0;
}*/