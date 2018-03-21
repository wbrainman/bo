#include <iostream>
#include "10_10_1.h"

//using namespace std;

Count::Count() 
{
	m_name = '\0';
	m_countNum = '\0';
	m_fund = 0;
}

Count::Count(const std::string &name, const std::string &countNum, const int fund)
	:m_name('\0')
	,m_countNum('\0')
	,m_fund(0)
{

}

void Count::show()
{
}

void Count::deposite(const int in)
{

}

void Count::withdraw(const int out)
{

}

Count::~Count()
{

}
