#include "10_10_1.h"
#include "10_10_2.h"
#include "10_10_3.h"
#include "10_10_4.h"
#include "10_10_5.h"
#include "10_10_6.h"
#include "10_10_7.h"
#include <iostream>

#define C_10_10_7

#ifdef C_10_10_1 
int main()
{
	Count count("bo", "123456", 500);
	count.show();

	count.deposite(100);
	count.withdraw(300);
	count.withdraw(50);

}
#endif

#ifdef C_10_10_2 
int main()
{
	Qerson one;
	Qerson two("Bob");
	Qerson three("alean", "Sam");

	one.Show();
	cout << endl;
	one.FormalShow();

	two.Show();
	cout << endl;
	two.FormalShow();

	three.Show();
	cout << endl;
	three.FormalShow();
}
#endif

#ifdef C_10_10_3 
int main()
{
	Golf g1("g1", 100);
	g1.show();

	Golf g2;
	g2.show();	

	g2.selfGolf(g1);
	g2.show();	

	Golf g3;
	g3.setGolf();
	g3.show();
}
#endif

#ifdef C_10_10_4 
int main()
{
	Sales s1;
	s1.show();

    const double ar[4] = {1.1, 2.2, 3.3, 4.4};
	Sales s2(ar, 4);
	s2.show();	

	Sales s3;
    s3.setSales();
	s3.show();	
}
#endif

#ifdef C_10_10_5
int main()
{
    Stack stack;
    Item item1 = {"aaa", 1};
    Item item2 = {"bbb", 1};
    Item item3 = {"ccc", 1};
    Item item4 = {"ddd", 1};
    Item item5 = {"eee", 1};
    Item item6 = {"fff", 1};
    Item item7 = {"ggg", 1};
    Item item8 = {"hhh", 1};
    Item item9 = {"iii", 1};
    Item item10 = {"jjj", 1};
    Item item11 = {"kkk", 1};

    stack.push(item1);
    stack.push(item2);
    stack.push(item3);
    stack.push(item4);
    stack.push(item5);
    stack.push(item6);
    stack.push(item7);
    stack.push(item8);
    stack.push(item9);
    stack.push(item10);
    stack.push(item11);

    Item item;
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);
    stack.pop(item);

    stack.show();

}
#endif

#ifdef C_10_10_6
int main()
{
    Move a;
    a.showmove();
    Move b(10,10);
    b.showmove();
    a.add(b);
    a.showmove();
}
#endif

#ifdef C_10_10_7
int main()
{
    Plorg a;
    a.show();
    char *name = "test";
    Plorg b(name,10);
    b.show();
}
#endif
