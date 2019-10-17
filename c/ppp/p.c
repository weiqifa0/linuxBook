#include "stdio.h"

char a = 12;
char *c[] = {"HELLO","NEW","WORLD","SAYHI"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp=cp;
char *p1 = &a;

void main()
{
    printf("%s\n",**++cpp);
    printf("%s\n",*--*++cpp+3);
    printf("%s\n",*cpp[-2]+3);
    
    printf("%s\n",cpp[-1][-1]+1);
    printf("%s\n",cpp[-1]);
}

/*
WORLD
LO
HI
EW
�@
*/
