#include "stdio.h"

int main(void)
{
    char arr[] = {0x02,0xE2};
    char result = 0xFF;
    int i = 0;
    
    result = arr[0];
    for(i = 1;i<sizeof(arr);i++)
    {
	result ^= arr[i];
    }
    printf("0x%.2X\n",result);
}
