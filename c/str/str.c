#include "stdio.h"

void main(void)
{
    char p1[] = {"abcdef"};
    char p2[] = "abcdef";
    char p3[] = {'a','b','c','d','e','f'};
    
    printf("%s\n",p1);
    printf("%s\n",p2);
    printf("%s\n",p3);
    
    printf("%p\n",p1);
    printf("%p\n",p2);
    printf("%p\n",p3);
}
