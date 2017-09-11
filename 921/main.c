/*main.c*/
#include <stdlib.h>
#include "a.h"

extern void func_two();
extern void func_three();

int main()
{
    func_two();
    func_three();
    return 0;
}

/*2.c*/
#include "a.h"
#include "b.h"

extern void func_two()
{
}

/*3.c*/
#include "b.h"
#include "c.h"

extern void func_three()
{
}
