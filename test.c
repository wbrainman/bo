 /* assamble code start
    1 movl 8(%ebp),%edi
    2 movl 12(%ebp),%ebx
    3 movl 16(%ebp),%esi
    4 movl (%edi),%eax
    5 movl (%ebx),%edx
    6 movl (%esi),%ecx
    7 movl %eax,(%ebx)
    8 movl %edx,(%esi)
    9 movl %ecx,(%edi)
assamble code end*/

void decode1(int *xp, int *yp, int *zp) //1,2,3
{
   int x,y,z; 

   x = *xp; //4
   y = *yp; //5
   z = *zp; //6

   *yp = x; //7
   *zp = y; //8
   *xp = z; //9





}
