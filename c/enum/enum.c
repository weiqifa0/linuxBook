#include <stdio.h>

#define MY_INT 7777
#define MY_STRING "9999"
#define MY_STRING2 "9999\"8OK"000(888)
#define ENUM_CHIP_TYPE_CASE(x)   case x: return(#x);
#define MY_DEFINE(R) #R
#define MY_DEFINE2(R) MY_DEFINE(R)

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


int main()
{
    enum cvmx_chip_types_enum a;
    a = 2;
    printf("ENUM_CHIP_TYPE_CASE %s\n",name[a]);
    return 0;
}
