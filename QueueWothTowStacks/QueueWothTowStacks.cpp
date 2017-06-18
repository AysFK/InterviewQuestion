// QueueWothTowStacks.cpp : 定义控制台应用程序的入口点。
//

//==============Cqueue函数===============
#include "stdafx.h"
#include <stack>
#include <exception>
using namespace std;

template <typename T> class CQueue
{
private:
	stack<T> stack1;
	stack<T> stack2;
public:
	CQueue(){};
	~CQueue(){};
	void appendTail(const T& node);
	T deleteHead();
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T& Data = stack1.top();
			stack1.pop();
			stack2.push(Data);
		}
	}
	if (stack2.empty())
	{
		printf("queue is empty\n");
		exit(0);
		//throw new exception("Queue is empty");
	}
 	T head = stack2.top();
	stack2.pop();
	return head;
}

//==============测试函数===============
void TEST(char actualy, char expect)
{
	if (expect == actualy)
		printf("test passed!\n");
	else
		printf("test failed!\n");
}

//==============main函数===============
int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<char> cqueue;
	//char test = cqueue.deleteHead();
	cqueue.appendTail('a');
	cqueue.appendTail('b');
	cqueue.appendTail('c');

	char head = cqueue.deleteHead();
	TEST(head, 'a');
	head = cqueue.deleteHead();
	TEST(head, 'b');
	cqueue.appendTail('d');
	head = cqueue.deleteHead();
	TEST(head, 'c');
	head = cqueue.deleteHead();
	TEST(head, 'd');

	return 0;
}

