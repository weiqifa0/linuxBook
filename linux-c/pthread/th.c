
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>
#include <sys/syscall.h> 
 
#define gettidv1() syscall(__NR_gettid)  
#define gettidv2() syscall(SYS_gettid)  

int number = 10;

void *thread1(void * ptr)
{
    number *= 3;
    printf("IM %s ID:%ld number:%d\n",(char*)ptr,gettidv1(),number);
}
void *thread2(void * ptr)
{
    number += 2;
    printf("IM %s ID:%ld number:%d\n",(char*)ptr,gettidv1(),number);
}

int main(int argc,char ** argv)
{
    pthread_t thread1 = -1;
    if(pthread_create(&thread1,NULL,thread1,"th1")!=0)
    {
        printf("thread1 creat error\n");
    }

    pthread_t thread2 = -1;
    if(pthread_create(&thread1,NULL,&thread2,"th2")!=0)
    {
        printf("thread1 creat error\n");
    }
    printf("run main\n");
    //调用结束，同时运行，并且tid包含了新线程的id
	while(1)
	{
	    printf("  i am main thread\n");
	    sleep(2);
	}
}
