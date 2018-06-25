
#include "10_10_5.h"
#include <string.h>
#include <iostream>

Stack::Stack()
{
    m_top = 0;
    m_sum = 0;

    for(int i = 0; i < MAX; i ++) {
        //m_item[i].fullname = {'\0'}; 
        memset(m_item[i].fullname, '\0', 34);
        m_item[i].payment = 0; 
    }

}

Stack::~Stack()
{

}

bool Stack::isFull()
{

    return MAX == m_top; 
}

bool Stack::isEmpty()
{
    return 0 == m_top; 
}

bool Stack::push(const Item &item)
{
    std::cout << "PUSH" << std::endl;

    if(MAX >  m_top) {
        m_item[m_top ++] = item;
        std::cout << "top =  " << (m_top - 1);
        std::cout << "   fullname =  " << m_item[m_top - 1].fullname << std::endl;
        return true;
    }

    std::cout << "full!!!" << std::endl;
    return false;
}

bool Stack::pop(Item &item)
{
    std::cout << "POP" << std::endl;

    if(0 < m_top) {
        item = m_item[-- m_top];
        m_sum += item.payment;
        std::cout << "top =  " << (m_top);
        std::cout << "   fullname =  " << m_item[m_top].fullname << std::endl;
        return true;
    }

    std::cout << "empty!!!" << std::endl;
    return false;
}

void Stack::show()
{
    std::cout << "sum is " << m_sum << std::endl;
}
