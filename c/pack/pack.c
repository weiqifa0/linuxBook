#include "stdio.h"

#pragma pack(4)

struct TEST{
    int a1:30;
    char a2:2;
    int a3:16;
    int a4:16;
    char a5;
    int a6:3;
};

void main()
{
    
    struct TEST STU_TEST;
    printf("%d %d\n",sizeof(int),sizeof(STU_TEST));
    printf("%d\n",STU_TEST.a1);
}
