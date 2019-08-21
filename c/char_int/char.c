#include "stdio.h"

void main(void)
{
    signed char a = (unsigned char)-1;
	unsigned char b = a;
	int c = a;
	int d = b;
	signed char aa = (unsigned char)-1;
	unsigned int cc = aa;
	unsigned int dd = -1;
	
	printf("%d %u\n",cc,dd);
	printf("%x %x %x %x\n", a, b, c, d);
	printf("%d %d %d %d\n", a, b, c, d);
	
	printf("0x%x\n",cc);
}
