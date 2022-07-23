#include<stdio.h>
int __attribute__ ((noinline)) fun(){
    return 3*1000;
}

int main(int c,char**v){
    //printf("%d\n",fun(1));
    return fun();
}
