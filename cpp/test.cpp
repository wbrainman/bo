#include <iostream>
#include "test.h"

Miao::Miao()
{
	a = 0;
	b = 0;

}

void Miao::set()
{
	a = 1;
	b = 2;

}

void Miao::show()
{
	std::cout << "a = " << a << endl;
	std::cout << "b = " << b << endl;
}
