#include "12_01.h"
#include "12_02.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//#define C_12_01
#define C_12_02

#ifdef C_12_01 
int main()
{
    using std:: cout;
    using std:: endl;

    Cow cow1;
    cout << "---cow1---" << endl;
    cow1.ShowCow();
    cout << endl;

    Cow cow2("mmmm", "eat", 165);
    cout << "---cow2---" << endl;
    cow2.ShowCow();
    cout << endl;

    Cow cow3(cow2);
    cout << "---cow3---" << endl;
    cow3.ShowCow();
    cout << endl;
    
    cow1 = cow3;
    cout << "---cow1---" << endl;
    cow1.ShowCow();
    cout << endl;
    
    Cow *cow4 = new Cow;
    cout << "---cow4---" << endl;
    cow4->ShowCow();
    cout << endl;

    Cow *cow5 = new Cow("www", "sleep", 155);
    cout << "---cow5---" << endl;
    cow5->ShowCow();
    cout << endl;

    Cow *cow6 = new Cow(*cow5);
    cout << "---cow6---" << endl;
    cow6->ShowCow();
    cout << endl;

    delete cow4;
    delete cow5;
    delete cow6;
}
#endif


#ifdef C_12_02 
int main()
{
    String s1("and I an a C++ student.");
    String s2 = "Please enter u name:";
    String s3;
    cout << s2;
    cin >> s3;

    s2 = "My name is " + s3;
    cout << s2 << ".\n";

    s2 = s2 + s1;
    s2.StringUpper();
    //cout << "The string\n" << s2 << "\ncontains" << s2.
    cout << s2 << ".\n";

}
#endif

