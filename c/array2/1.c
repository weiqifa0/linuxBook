#include <stdio.h>
int arraySum(int arr[],int len)
{
    unsigned int loop = 0;

    int sum = 0;
    if(NULL == arr)
    {
        return 0;
    }
    for(loop = 0; loop < len; loop++)
    {
        sum+=arr[loop];
        printf("arr:%d\n",arr[loop]);
    }
    return sum;   
}
int main(void)
{
    int a[] = {1,2,3,4,5,6};
    printf("size:%d\n",sizeof(a));
    int sum = arraySum(a,sizeof(a)/sizeof(a[0]));
    printf("arr sum is %d\n",sum);
    return 0;
}
