#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString & operator=(const CMyString &str);
protected:
	char* m_pData;
};
//1.添加赋值运算符函数
CMyString & CMyString::operator= (const CMyString &str)
{
	if (this == &str)
		return *this;
	delete[] m_pData;
	m_pData = NULL;
	m_pData = new char[(strlen(str.m_pData) + 1)];
	strcpy(m_pData, str.m_pData);
	return *this;
}