/*************************************************************************
	> File Name: strcmp.c
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jul 2019 08:12:02 PM PDT
 ************************************************************************/

#include<stdio.h>
void main()
{
    char str1[30];
    char str2[30];
    int ret = 0;

    do
    {
        gets(str1);
        gets(str2);
        ret = strcmp(str1,str2);
        printf("%d\n",ret);
    }while( ret );

}
