#include "stdio.h"
#include "stdint.h"

//#pragma pack(1)
uint8_t buf[16];//__attribute__((section(".ARM.__at_0x601051")));
uint8_t buf2[16];
#pragma pack(4)
void main(void)
{

    uint8_t i;
    uint16_t data;
    uint16_t *p;
    
    printf("%p\n",&buf);
    printf("%p\n",&buf2);
    printf("%p\n",&data);
    
    for(i = 0;i<16;i++)
    {
        buf[i] = i;
        printf("i = %d arr = %p %02x \n",i,&buf[i],buf[i]);
    }
        
    data = *((uint16_t *)&buf[1]);
    printf("data:%04x \n",data);
    p = (uint16_t *)&buf[1];
    printf("%p *p:%04x \n",p,*p);
    for(i=0;i<16;i++)
    {
        data = *((uint16_t *)&buf[i]);
        printf("%04x:\t",data);
    }
    printf("Finish\n");
}
