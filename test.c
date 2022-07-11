#include<stdio.h>
int __attribute__ ((noinline)) fun(int x){
    return x+41;
}

int main(int c,char**v){
    //printf("%d\n",fun(1));
    return fun(1);
}
