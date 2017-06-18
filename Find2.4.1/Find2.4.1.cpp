// Find2.4.1.cpp : 定义控制台应用程序的入口点。

//数据结构内容：线性表，堆栈，队列，树，集合和搜索，搜索树，跳表散列表，图，内排序
//递归和循环实现：递归法简洁效率低； 循环效率高（二叉树非递归遍历器类O(n)时间）,需要辅助空间（O(n)栈空间）
//搜索算法：顺序O(n)，二分O(log2n)，哈希表O(1)，二分排序树查找
//

//二分搜索：Ws(n) == Wu(n) == Au(n) == O(log2n)

#include "stdafx.h"

enum ResultCodes{ Underflow, Overflow, Success, Duplicate, NotPresent };

//虚基类DynamicSet
template <class T>
class DynamicSet
{
	//常成员函数不能修改本类数据成员；
	//静态成员同一类不同对象共享；
public:
	virtual ResultCodes search(T& x) const = 0;
	virtual ResultCodes insert(T x) = 0;
	virtual ResultCodes remove(T& x) = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
};

//派生类ListSet
template <class T>
class ListSet:public DynamicSet<T>
{
private:
	T * arr;
	int maxSize;
	int n;
public:
	ListSet(int msize){ maxSize = msize; arr = new T[maxSize]; n = 0; }
	~ListSet(){ delete[] arr; }
	bool isEmpty() const { return n == 0; }
	bool isFull() const { return maxSize == n; }
	ResultCodes search(T& x) const;
	ResultCodes insert(T x);
	ResultCodes remove(T& x);
private:
	int Bsearch(T& x, int low, int high) const;
};
//二分搜索
template <class T>
int ListSet<T>::Bsearch(T& x, int low, int high) const
{
	if (low <= high)
	{
		int m = (low + high) / 2;
		if (x < arr[m])
			return Bsearch(x, low, m - 1);
		else if (x > arr[m])
			return Bsearch(x, m + 1, high);
		else
			return m;
	}
	return -1;
}
//Bsearch
template <class T>
ResultCodes ListSet<T>::search(T& x) const
{
	//调用Bsearch,递归
	/*int i = Bsearch(x, 0, n - 1);
	if (i == -1) return NotPresent;
	x = arr[i]; return Success;*/
	//迭代
	int m, low = 0, high = n - 1;
	while (low <= high)
	{
		m = (low + high) / 2;
		if (x < arr[m])
			high = m - 1;
		else if (x > arr[m])
			low = m + 1;
		else
		{
			x = arr[m];
			cout << "Find " << x << endl;
			return Success;
		}
	}
	cout << x << " NotFind " << endl;
	return NotPresent;
}

//插入
template <class T>
ResultCodes ListSet<T>::insert(T x)
{
	if (n == maxSize)
	{
		cout << "Insert " << x << " failed" << endl;
		return Underflow;
	}
	arr[n++] = x;
	cout << "Insert " << arr[n - 1] << " success" << endl;
		return Success;
}

//删除
template <class T>
ResultCodes ListSet<T>::remove(T& x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			for (int j = i; i < n - 1;i++)
			{
				arr[j] = arr[j + 1];
			}
			cout << x << " Remove success" << endl;
			n--;
			return Success;
		}
	}
	cout << x << " Remove failed" << endl;
	return NotPresent;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "===============Int test============>" << endl;
	int x = 5, y = 6;
	ListSet<int> listset = ListSet<int>(5);
	listset.insert(1);
	listset.insert(2);
	listset.insert(5);

	listset.search(x);
	listset.search(y);

	listset.remove(x);
	listset.remove(y);

	cout << endl;
	cout << "===============Char test============>" << endl;
	char x2 = 'a', y2 = 'd';
	ListSet<char> listset2 = ListSet<char>(3);
	listset2.insert('a');
	listset2.insert('b');
	listset2.insert('c');
	listset2.insert('d');

	listset2.search(x2);
	listset2.search(y2);

	listset2.remove(y2);
	listset2.remove(x2);

	return 0;
}

