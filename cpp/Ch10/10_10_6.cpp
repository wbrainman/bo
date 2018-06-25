
#include "10_10_6.h"
#include <iostream>

Move::Move(double a, double b)
    :x(a)
    ,y(b)
{

}

Move::~Move()
{

}

void Move::showmove() const
{

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    
}

Move Move::add(const Move & m)
{
    x += m.x;
    y += m.y;
    return *this;

}

void Move::reset()
{
    x = 0;
    y = 0;

}
