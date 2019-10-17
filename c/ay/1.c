#include "stdio.h"
#include "stdint.h"

uint8_t buf[16];
uint8_t i;
uint16_t data;

/*
for (i=0; i<16; i+=2)
{
    data = *((uint16_t *)&buf[i]);
} 
*/
void main()
{
    unsigned char a = 0;
    unsigned int b = 0;
    printf("%p %p \n",&a,&b);
}
