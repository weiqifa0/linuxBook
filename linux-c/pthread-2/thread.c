
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>

#include <sys/syscall.h> 
 
#define gettidv1() syscall(__NR_gettid)  
#define gettidv2() syscall(SYS_gettid)  

typedef struct {
    int counter;
} atomic_t;

#define ATOMIC_INIT(i)	( (atomic_t) { (i) } )

#define atomic_read(v)		(*(volatile int *)&(v)->counter)
#define atomic_set(v,i)		((v)->counter = (i))

long int NUM = 0;
int lock = 0;
//atomic_t v = ATOMIC_INIT(0);
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//ATOMIC_INIT(&NUM);
atomic_t btn_atomic = ATOMIC_INIT(0);


void * th(void * ptr)
{
    //pthread_mutex_lock(&mutex);
    int i = 0;
    for(i = 0;i < 1000000000;i++)
    {
        atomic_set(&NUM,i);
        //NUM++;
    }
    //usleep(20);
    //printf("IM %s ID:%ld number:%ld\n",(char*)ptr,gettidv1(),NUM);
    //pthread_mutex_unlock(&mutex);
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
