/*************************************************************************
	> File Name: strncpy.c
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jul 2019 11:31:12 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

void main(void)
{
    char uri[150];
    int uri_offset = 0;

    strncpy(uri,"weiqifa",strlen("weiqifa"));
    uri_offset += strlen("weiqifa");
    strncpy(uri+uri_offset,"gggg",strlen("gggg"));
    uri_offset += strlen("gggg");
    snprintf(uri+uri_offset,strlen("uri_offset=")+sizeof(uri_offset),"uri_offset=%d",uri_offset);
    printf("%s\n",uri);
}
