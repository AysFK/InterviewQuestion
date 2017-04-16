#include "LinearList.h"
template <class T>
class SeqList : public LinearList
{
public:
	SeqList(int mSize);
	~SeqList();
	bool IsEmpty() const;
	int Length() const;
	bool Find(int i, T& x) const;
	bool Insert(int i, T x);
private:
	int maxLength;
	T *elements;
};


template <class T>
SeqList<T>::SeqList(int mSize)
{
	maxLenth = mSize;
	elements = new T[maxLength];
	n = 0;
}

template <class T>
SeqList<T>::~SeqList()
{
	delete [] elements;
}

template <class T>
bool SeqList<T>::IsEmpty() const
{
	return 0 == n;
}

template <class T>
int SeqList<T>::Length() const
{
	return n;
}

template <class T>
bool SeqList<T>::Insert(int i, T x)
{
	if (i < -1 || i > n - 1)//插入范围控制;if n = 0, then i = -1 , insert to elements[0]
	{
		cout << "out of bound!" << endl;	return false;
	}
	if (n == maxLength)//溢出检查
	{
		cout << "OverFlow" << endl;		return false;
	}
	for (int j = n - 1; j > i; j--)//x插入在i元素后面
	{
		elements[j + 1] = elements[j];
	}
	elements[i + 1] = x;
	n++;
	return true;
	/*
	if (n == 0)                    // bool Delete(int i)
	if (i < 0 || i > n -1)
	for (int j = i + 1; j < n; j++)
	{
		elements[j - 1] = elements[j];
	}
	n--;
	*/
}

template <class T>
bool SeqLIst<T>::Find(int i, T& x) const
{
	if (i < 0 || i > n - 1)
	{
		cout << "out of bound!" << endl;
		return false;
	}
	x = elements[i];
	return true;
}  