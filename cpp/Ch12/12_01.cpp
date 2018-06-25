#include "12_01.h"
#include <iostream>
#include <string.h>

Cow::Cow()
{
    memset(name, '\0',sizeof(name));
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
    memcpy(name, nm,sizeof(nm));
    hobby = new char[(strlen(ho)) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[(strlen(c.hobby)) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow& Cow::operator=(const Cow &c)
{
    if(&c == this) {
        return *this; 
    }

    if(NULL != hobby) {
        delete [] hobby;
    }

    strcpy(name, c.name);
    hobby = new char[(strlen(c.hobby)) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;

    return *this; 

}

void Cow::ShowCow() const
{
    using std:: cout;
    using std:: endl;

    cout << "name = " << name << endl;
    cout << "hoby = " << hobby << endl;
    cout << "weight = " << weight << endl;
}
