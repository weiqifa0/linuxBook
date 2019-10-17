#include <limits.h>
#include <stdio.h>
 
/*
* Check at compile time that something is of a particular type.
* Always evaluates to 1 so you may use it easily in comparisons.
typecheck宏有两个参数，
第一个是一个类型，比如unsigned long，
第二个是一个变量，比如a。
它生成一个unsigned long类型的变量__dummy，
然后利用typeof生成和a同样类型的变量__dummy2，
比较__dummy和__dummy2的地址。
如果它们不是同样类型的指针比较，比如a不是unsigned long，
这时候编译器会有一个警告，让你注意到这个问题。
*/
#define typecheck(type,x) \
({        type __dummy; \
        typeof(x) __dummy2; \
        (void)(&__dummy == &__dummy2); \
        1; \
})
 
 
#define time_after(a,b) \
(typecheck(unsigned long, a) && \
typecheck(unsigned long, b) && \
((long)(b) - (long)(a) < 0))
/*这个宏可以简化成
*#define typecheck(type,x) \
*((long)(b) - (long)(a) < 0)
*当然，在long == int的编译器中也可以
*((int)(b) - (int)(a) < 0)
*/

#define HZ (200)

int main(int argc, char **argv)
{
	unsigned long a,b,timeout,jiffies;
	printf("char_range: [%-4ld, %-4ld]\n",LONG_MIN,LONG_MAX);
	printf("uchar_range:[%-4lu, %-4lu]\n",0,ULONG_MAX);
	printf("%d~%d \n",(char)0x80,0x7F);
printf("%d~%d \n",(char)0xFF,0x7F);
printf("%d~%d \n",0xFF,0x7F);
	jiffies = 18446744073709551615/2;
	printf("%lld\n",(long)(jiffies));
	timeout = 18446744073709551615/2;
	timeout += jiffies;
    jiffies += 202;
	printf("jiffies=%ld,timeout=%ld, time_after(a,a+b)=%d\n",(long)jiffies, (long)timeout, time_after(jiffies,timeout));
	
	
	printf("--------------------------\n");
	#if 0
	a = 18446744073709551615+1; 
	b = 18446744073709551615/2;
	printf("a=%u,b=%lu, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	printf("--------------------------\n");
	a = 1; 
	b = 1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	
	
	a = ULONG_MAX;
	b = 1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	a = ULONG_MAX;
	b = ULONG_MAX/2;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	
	a = ULONG_MAX; 
	b = ULONG_MAX/2+1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	a = ULONG_MAX; 
	b = ULONG_MAX/2+2;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	a = ULONG_MAX/2; 
	b = 1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	
	a = ULONG_MAX/2; 
	b = ULONG_MAX/2;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	
	a = ULONG_MAX/2+1;
	b = ULONG_MAX/2-1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	
	a = ULONG_MAX/2+1; 
	b = ULONG_MAX/2;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	a = ULONG_MAX/2+1; 
	b = ULONG_MAX/2+1;
	printf("a=%u,b=%u, time_after(a,a+b)=%d\n",a, b, time_after(a,a+b));
	#endif
}
