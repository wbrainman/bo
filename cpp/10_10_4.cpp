#include <iostream>
#include "10_10_4.h"

using namespace std;

Sales::Sales()
{
    for(int i = 0; i < Quarters; i ++) {
        m_sales[i] = 0; 
    }

    m_average = 0;
    m_max = 0;
    m_min = 0;

}

Sales::Sales(const double ar[], int n)
{
    int temp;
    temp = n > Quarters ? Quarters : n;
    int i;

    for(i = 0; i < temp; i ++) {
        m_sales[i] = ar[i]; 
    }

    average();
    max();
    min();
}

Sales::~Sales()
{

}

void Sales::setSales()
{
    double ar[Quarters];
    int i;

	cout << "*** start entering" << endl;
    for(i = 0; i < Quarters; i ++) {
	    cout << "enter sale[%d]:" << i << endl;
        cin >> ar[i];
    }
	cout << "*** end entering" << endl;

	Sales temp(ar,Quarters);
	*this = temp;

}

void Sales::show() const
{
    int i;
    for(i = 0; i < Quarters; i ++) {
        cout << "m_sales[0] = " << m_sales[i] << endl;
    }

    cout << "average    = " << m_average << endl;
    cout << "max        = " << m_max << endl;
    cout << "min        = " << m_min << endl;
}

double Sales::average()
{
    double sum = 0;
    int i;

    for(i = 0; i < Quarters; i ++) {
        sum += m_sales[i];
    }

    m_average = sum / (int)Quarters;
}

double Sales::max()
{
    m_max = m_sales[0];

    int i;
    for(i = 0; i < Quarters; i ++) {
        m_max = m_max > m_sales[i] ? m_max : m_sales[i];
    }
}

double Sales::min()
{
    m_min = m_sales[0];

    int i;
    for(i = 0; i < Quarters; i ++) {
        m_min = m_min < m_sales[i] ? m_min : m_sales[i];
    }
}

