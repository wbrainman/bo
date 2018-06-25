#include "10_10_3.h"
#include <iostream>

Golf::Golf()
{
	fullname = "ann";
	handicap = 100;
}

Golf::Golf(const string name, int hc)
{
	fullname = name;
	handicap = hc;
}

Golf::~Golf()
{
}

Golf &Golf::selfGolf(Golf &g)
{
	fullname = g.fullname;
	handicap = g.handicap;

	//return *this;
}

void Golf::setGolf()
{
	cout << "*** start entering" << endl;
	cout << "enter name:" << endl;
	string tempString;
	getline(cin,tempString);
	cout << "enter hc:" << endl;
	int hc;
	cin >> hc;
	cout << "*** end entering" << endl;

	Golf temp(tempString,hc);
	*this = temp;
}


void Golf::show()
{
	//cout << "fullname = " << fullname << "\n";
	cout << "fullname = " << fullname << endl;
	cout << "handicap = " << handicap << "\n";
}
