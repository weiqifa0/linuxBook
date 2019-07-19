#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = { 0 };
    char str2[50] = { 0 };
    int i = 1;
    int ret = 0 ;
    do 
    {
        printf("******第%d次输入******\n", i);
        gets(str1);
        gets(str2);
        i++;
        ret = strcmp(str1, str2);
        if(ret > 0)
	{
		printf("%s\n",str1);
 		printf("%s\n",str2);
	}
	else
	{
		printf("%s\n",str2);
 		printf("%s\n",str1);
	}
        printf("%d\n",ret);
    } while ( ret );
    return 0;
}
