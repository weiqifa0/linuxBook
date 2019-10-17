#include "stdio.h"

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))
//* > &
//(*(volatile unsigned *)&(sequence))
unsigned sequence;

void main()
{
    int i = 0;
    for(i = 0;i<20;i++)
    {
        sequence = i;
        printf("%d\n",ACCESS_ONCE(sequence));
    }
}
