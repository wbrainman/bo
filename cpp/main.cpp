#include "10_10_1.h"
#include "10_10_2.h"
#include <iostream>

#define C_10_10_3

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
	Count count("bo", "123456", 500);
	count.show();

	count.deposite(100);
	count.withdraw(300);
	count.withdraw(50);

}
#endif
