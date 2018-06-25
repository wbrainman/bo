#include <iostream>
#include "10_10_1.h"

using namespace std;

Count::Count() 
{
	m_name = "unknow";
	m_countNum = "000000";
	m_fund = 0;
}

Count::Count(const std::string &name, const std::string &countNum, const int fund)
	:m_name(name)
	,m_countNum(countNum)
	,m_fund(fund)
{

}

void Count::show()
{
	cout << "name 		: "<< m_name << "\n";
	cout << "countNum 	: "<< m_countNum << "\n";
	cout << "fund 		: "<< m_fund << "\n";
}

void Count::deposite(const int in)
{
	cout << "deposit in : " << in << "\n";
	m_fund += in;
	cout << "fund now is : "<< m_fund << "\n";
}

void Count::withdraw(const int out)
{
	if(out > m_fund) {
		cout << "sorry !, out > fund" << "\n";
		return;
	}

	m_fund -= out;
	cout << "fund now is : "<< m_fund << "\n";
}

Count::~Count()
{

}
