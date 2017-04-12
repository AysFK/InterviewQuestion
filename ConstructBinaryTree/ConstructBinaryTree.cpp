// ConstructBinaryTree.cpp : 定义控制台应用程序的入口点。
/*
//树（除根节点外，每个节点都有一个父节点；除叶子节点外，每个节点有一个或多个子节点）
//二叉树（最多只有两个子节点的树； 考察遍历前中后序，递归，非递归）
//二叉搜索树，B-树（搜索树：表动态集，二分搜索需顺序表，插删费时，相比下，搜索树，搜索效率，插入删除综合较好）
//二叉树特例（二叉搜索树，堆，红黑树）
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
	//根节点
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;
	//一个节点及异常处理
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input");
	}
	//子串递归求节点
	//注意条件控制，写出序列判断
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
	{
		rootInorder++;
	}
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{//左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{//右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}
// ====================测试代码====================
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
//普通树
void Test1()
{
	const int lentgh = 8;
	int preorder[lentgh] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[lentgh] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	TEST(__FUNCTION__, preorder, inorder, lentgh);
}
//无左子节点
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

// 无左子结点               
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

//树中只有一个结点
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

//完全二叉树
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	TEST(__FUNCTION__, preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	TEST(__FUNCTION__, NULL, NULL, 0);
}

// 输入的两个序列不匹配
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