//IntToStr
//StrToInt
//linked list(linearlist,Seqlist,SingleList)

//CMystring

#include <iostream>
using namespace std;

template <class T>
class LinearList
{
public:
	virtual bool IsEmpty() const = 0;  //����Ա���������麯��
	virtual int Length() const = 0;
	virtual bool Find(int i, T& x) const = 0;
	virtual bool Insert(int x, T x) = 0;
protected:
	int n;//����
};