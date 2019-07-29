
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>

#include <sys/syscall.h> 
 
#define gettidv1() syscall(__NR_gettid)  
#define gettidv2() syscall(SYS_gettid)  


long int NUM = 0;

void * th(void * ptr)
{
    int i = 0;
    for(i = 0;i < 1000000000;i++)
    {
        NUM++;
    }
    //sleep(1);
    //printf("IM %s ID:%ld number:%ld\n",(char*)ptr,gettidv1(),NUM);
}

int main(int argc,char ** argv)
{
    pthread_t thread1 = -1;
    if(pthread_create(&thread1,NULL,th,"th1")!=0)
    {
        printf("thread1 creat error\n");
    }

    pthread_t thread2 = -1;
    if(pthread_create(&thread2,NULL,th,"th2")!=0)
    {
        printf("thread1 creat error\n");
    }
      
    
    while(1)
    {
        printf("IM %s ID:%ld number:%ld\n","Main",gettidv1(),NUM);
        sleep(2);
    };
}
