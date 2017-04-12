// ConstructBinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
/*
//���������ڵ��⣬ÿ���ڵ㶼��һ�����ڵ㣻��Ҷ�ӽڵ��⣬ÿ���ڵ���һ�������ӽڵ㣩
//�����������ֻ�������ӽڵ������ �������ǰ�к��򣬵ݹ飬�ǵݹ飩
//������������B-��������������̬��������������˳�����ɾ��ʱ������£�������������Ч�ʣ�����ɾ���ۺϽϺã�
//�������������������������ѣ��������
//*/
#include "stdafx.h"
#include "..\Utilities\BinaryTree.h"
#include <exception>

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startinorder, int* endinorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int lentgh)
{
	if (preorder == NULL || inorder == NULL || lentgh <= 0)
	{
		return NULL;
	}
	return ConstructCore(preorder, preorder + lentgh - 1, inorder, inorder + lentgh - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	//���ڵ�
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;
	//һ���ڵ㼰�쳣����
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input");
	}
	//�Ӵ��ݹ���ڵ�
	//ע���������ƣ�д�������ж�
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
	{
		rootInorder++;
	}
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{//������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{//������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}
// ====================���Դ���====================
void TEST(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != NULL)
		printf("%s begin:\n", testName);
	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");
	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);
		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}
//��ͨ��
void Test1()
{
	const int lentgh = 8;
	int preorder[lentgh] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[lentgh] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	TEST(__FUNCTION__, preorder, inorder, lentgh);
}
//�����ӽڵ�
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

// �����ӽ��               
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

//����ֻ��һ�����
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

//��ȫ������
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

// �����ָ��
void Test6()
{
	TEST(__FUNCTION__, NULL, NULL, 0);
}

// ������������в�ƥ��
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}