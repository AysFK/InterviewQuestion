#include "stdafx.h"
//2.1�����ָ��(������Ϊ������������ʱ���˻�Ϊͬ���͵�ָ��)
int GetSize(int data[])
{
	return sizeof(data);
}

/*int main(int argc, _TCHAR* argv[])
{
	//��Ϊ����
	int data1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof(data1);
	//ָ��
	int* data2 = data1;
	int size2 = sizeof(data2);
	//����ʱ�˻�Ϊָ��
	int size3 = GetSize(data1);
	printf("size1 = %d  size2 = %d  size3 = %d\n", size1, size2, size3);
	return 0;
}*/