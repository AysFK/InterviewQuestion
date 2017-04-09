#include "stdafx.h"
#include "../Utilities/List.h"
#include <stack>
using namespace std;

//========���⺯��========
//ջ����
void PrintListInReversedOrder_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

//�ݹ鷽��
void PrintListInReversedOrder_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
			PrintListInReversedOrder_Recursively(pHead->m_pNext);
		printf("%d\t", pHead->m_nValue);
	}
}

//========���Ժ���========
void TEST(char* testName, ListNode* pHead)
{
	printf("\n%s begin:\n", testName);
	printf("===>Iteratively\n");
	PrintListInReversedOrder_Iteratively(pHead);
	printf("\n");
	printf("===>Recursively\n");
	PrintListInReversedOrder_Recursively(pHead);
	printf("\n");
}

//========��������========
void test1()
{
	ListNode* PNode1 = CreateListNode(1);
	ListNode* PNode2 = CreateListNode(2);
	ListNode* PNode3 = CreateListNode(3);
	ListNode* PNode4 = CreateListNode(4);
	ListNode* PNode5 = CreateListNode(5);

	ConnectListNodes(PNode1, PNode2);
	ConnectListNodes(PNode2, PNode3);
	ConnectListNodes(PNode3, PNode4);
	ConnectListNodes(PNode4, PNode5);

	TEST(__FUNCTION__, PNode1);

	DestroyList(PNode1);
}
void test2()
{
	ListNode* PNode1 = CreateListNode(1);

	TEST(__FUNCTION__, PNode1);

	DestroyList(PNode1);
}

void test3()
{
	TEST(__FUNCTION__, NULL);
}

//========main����========
int main(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	return 0;
}