#include <cstring>
#include <cctype>
#include "12_02.h"

using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings ++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str = '\0';
    num_strings ++;
}

String::String(const String &st)
{
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings ++;
}

String::~String()
{
    -- num_strings;
    delete [] str;
}

String& String::operator=(const String &st)
{
    if(this == &st) {
        return *this; 
    }

    delete [] str;

    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings ++;
    return *this; 

}

String&String::operator=(const char *s)
{
    delete [] str;

    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings ++;
    return *this; 
}



char& String::operator[] (int i)
{
    return str[i];
}

const char& String::operator[] (int i) const
{
    return str[i];
}

int String::SameChar(char c)
{
    //TODO
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st.str = temp;
        st.len = String::CINLIM;
    while(is && is.get() != '\n')
        continue;
    return is;
}

String& operator+(const char* s, String& st)
{
    String temp;
    temp.len = strlen(s) + st.len;
    temp.str = new char[temp.len + 1];
    std::strcpy(temp.str, s);
    std::strcat(temp.str, st.str);


}

String& String::operator+(const String &st)
{
    len += st.len + 1;
    char temp[len];

    std::strcat(temp, str);
    std::strcat(temp, st.str);

    delete [] str;

    str = new char[len];
    std::strcpy(str, temp);

}

String& String::operator+(const char *s)
{
    len += std::strlen(s) + 1;
    char temp[len];

    std::strcat(temp, str);
    std::strcat(temp, s);

    delete [] str;

    str = new char[len];
    std::strcpy(str, temp);

}


String & String::StringLower()
{
    int i = 0;
    char temp[len + 1];
    char c;

    while(str[i]) {
        c = str[i];
        temp[i] = std::tolower(c);            
        i ++;
    }

    delete[] str;
    str = new char(len + 1);
    std::strcpy(str, temp);

    return *this;
}


String & String::StringUpper()
{
    int i = 0;
    char temp[len + 1];
    char c;

    while(str[i]) {
        c = str[i];
        temp[i] = std::toupper(c);            
        i ++;
    }

    delete[] str;
    str = new char(len + 1);
    std::strcpy(str, temp);

    return *this;
}

