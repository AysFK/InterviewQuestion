#include "stdafx.h"
#include "BinaryTree.h"

BinaryTreeNode* CreateBinaryTree(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != NULL)
	{
		printf("Value of this node is: %d\n", pNode->m_nValue);
		if (pNode->m_pLeft != NULL)
			printf("Value of the left child is: %d\n", pNode->m_pLeft->m_nValue);
		else
			printf("Left child is Null");
		if (pNode->m_pRight != NULL)
			printf("Value of the right child is: %d\n", pNode->m_pRight->m_nValue);	
		else
			printf("Right child is Null.\n");
	}
	else
	{
		printf("The node is null.\n");
	}
	printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);
	if (pRoot != NULL)
	{
		if (pRoot->m_pLeft != NULL)
			PrintTreeNode(pRoot->m_pLeft);
		if (pRoot->m_pRight != NULL)
			PrintTreeNode(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}