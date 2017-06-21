// Find2.4.1.cpp : �������̨Ӧ�ó������ڵ㡣

//���ݽṹ���ݣ����Ա���ջ�����У��������Ϻ�������������������ɢ�б�ͼ��������
//�ݹ��ѭ��ʵ�֣��ݹ鷨���Ч�ʵͣ� ѭ��Ч�ʸߣ��������ǵݹ��������O(n)ʱ�䣩,��Ҫ�����ռ䣨O(n)ջ�ռ䣩
//�����㷨��˳��O(n)������O(log2n)����ϣ��O(1)����������������
//

//����������Ws(n) == Wu(n) == Au(n) == O(log2n)

#include "stdafx.h"

enum ResultCodes{ Underflow, Overflow, Success, Duplicate, NotPresent };

//�����DynamicSet
template <class T>
class DynamicSet
{
	//����Ա���������޸ı������ݳ�Ա��
	//��̬��Աͬһ�಻ͬ������
public:
	virtual ResultCodes search(T& x) const = 0;
	virtual ResultCodes insert(T x) = 0;
	virtual ResultCodes remove(T& x) = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
};

//������ListSet
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
//��������
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
	//����Bsearch,�ݹ�
	/*int i = Bsearch(x, 0, n - 1);
	if (i == -1) return NotPresent;
	x = arr[i]; return Success;*/
	//����
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

//����
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

//ɾ��
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

