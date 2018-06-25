#include <iostream>
#include <cstring>
#include "10_10_2.h"

#if 1
Qerson::Qerson(const string &ln, const char* fn)
	:lname(ln)
{

	memcpy(fname, fn, strlen(fn));
}
#else
Qerson::Qerson(const string &ln, const char* fn)
{
	lname = ln;
	memcpy(fname, fn, strlen(fn));

}
#endif

Qerson::~Qerson()
{

}

void Qerson::Show() const
{
	cout << lname << " " << fname << "\n";
}

void Qerson::FormalShow() const
{
	cout << fname << " " << lname << "\n";
}
