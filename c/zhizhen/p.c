#include "stdio.h"

void main(void)
{
    int a = 0x0012fed4;
    int *p = *(int**)&a;
    
    *p = 0x23;
    
    printf("%d\n",*p);
}
