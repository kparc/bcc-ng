#include<stdio.h>

int main() {

    unsigned int a = 0x33;
    
    printf("%x %x %x\n", a,a|8,a|8|8);
    printf("%x %x %x\n", a,a|0,a|0|0);
    
    return 0;
}
