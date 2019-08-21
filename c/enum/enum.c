#include <stdio.h>

#define PRINTF_ENUM(x) ({printf("enum:%s\n",#x);}) //打印枚举名

enum cvmx_chip_types_enum {
    CVMX_CHIP_TYPE_NULL = 0,
    CVMX_CHIP_TYPE_DEPRECATED = 1,
    CVMX_CHIP_TYPE_OCTEON_SAMPLE = 2,
    CVMX_CHIP_TYPE_MAX
};

const char *name[] =
{
    "CVMX_CHIP_TYPE_NULL",
    "CVMX_CHIP_TYPE_DEPRECATED",
    "CVMX_CHIP_TYPE_OCTEON_SAMPLE",
    "CVMX_CHIP_TYPE_MAX"
};

void printf_enum(enum cvmx_chip_types_enum en)
{
    switch(en)
    {
        case CVMX_CHIP_TYPE_NULL:
        {
            printf("CVMX_CHIP_TYPE_NULL\n");
        }
        break;
        case CVMX_CHIP_TYPE_DEPRECATED:
        {
            printf("CVMX_CHIP_TYPE_DEPRECATED\n");
        }
        break;
        case CVMX_CHIP_TYPE_OCTEON_SAMPLE:
        {
            printf("CVMX_CHIP_TYPE_OCTEON_SAMPLE\n");
        }
        break;
        case CVMX_CHIP_TYPE_MAX:
        {
            printf("CVMX_CHIP_TYPE_MAX\n");
        }
        break;
    }
}

int main()
{
    enum cvmx_chip_types_enum a;
    a = 2;
    
    //#1
    printf("ENUM_CHIP_TYPE_CASE %s\n",name[a]);
    
    //#2
    PRINTF_ENUM(CVMX_CHIP_TYPE_DEPRECATED);
    
    //#3
    a = 3;
    printf_enum(a);
    return 0;
}
