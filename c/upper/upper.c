#include <stdio.h>
#include <string.h>

int strToUpper(const char* str, const int strSize, char* result)
{
    int i = 0;
    for(i = 0;i < strSize;i++)
    {
        if (*(str +i) >= 'a' && *(str +i) <= 'z')
        {
            *(result +i) = *(str +i) - 32; //小写转大写
        }
        else
        {
            *(result +i) = *(str +i);
        }
    }
    return (0);
}

void main(void)
{
	char * str = "jadfoasjfiALDJFASIOkaljdAAD";
	char resule[100];
	
	strToUpper(str,strlen(str),(char *)resule);
	resule[99] = '\0';
	printf("%s\n",resule);
}
