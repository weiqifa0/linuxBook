#include <stdio.h>
#include <string.h>



#define typecheck(type,x)\
({ \ 
    type __dummy;\
    typeof(x) __dummy2;\
    (void)(&__dummy == &__dummy2);\
    1;\
})

#define TEST(flags) typecheck(unsigned long, flags)

int main(){
    unsigned long i = 0;a
    
    if(TEST(i)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}
