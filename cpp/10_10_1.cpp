#include <iostream>
#include "10_10_1.h"

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
