#include "10_10_7.h"
#include <iostream>
#include <string.h>

Plorg::Plorg()
{
    memcpy(m_name, "Plorga", MAX);
}

Plorg::Plorg(char* name, int ci)
    :m_ci(ci)
{
    memcpy(m_name, name, MAX);

}

Plorg::~Plorg()
{

}

void Plorg::show()
{
    using std:: cout;
    using std:: endl;
    cout << "name = " << m_name << endl;
    cout << "ci = " << m_ci << endl;
}
