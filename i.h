#include"c.h"
// :+-*% ^&|<=>  x64 JJ Jj o2 cc tst RET cll psh pop acdbsbsd89..  o[m[s|d]] c3 eb+1 e8+4 e9+4 [f2/66/4*][0f] 5* 7*+1 b*+4 0f8*+4  03 23 2b 3b (6b 83) 89 8b ..

//      eax edi esi edx ecx r8 r9,        ebx              ebp esp                 //!<  000 eax 001 ecx 010 edx 011 ebx 100 esp 101 ebp 110 esi 111 edi
ZI A[]={0,  7,  6,  2,  1,  8, 9,  10,11, 3,  12,13,14,15, 5,  4  },B=5,           //!< addresses of registers in function calling convention order
  //    jmp  jb   jz   jnbe jmp32 jnb  jnz  jbe   jnb32
  JJ[]={0xeb,0x72,0x74,0x77,0xe9, 0x73,0x75,0x76, 0x0f83},CLL=0xe8,RET=0xc3;

K o2(I t,I o,I r,I x,I y);    //!< return object code to execute opcode o with arguments x and y and leave the argument of type t in register r
K cc(I o,I x);                //!< cond (set byte on conditon functions: 0x0f90,...)
K psh(I t,I x);               //!< push from reg A[x]
K pop(I t,I x);               //!< pop to reg A[x]
K tst(I t,I x);               //!< test (sets sz if x is not zero), nyi for floats
K jmp(I n);                   //!< jump (c5 long c2 short)
K cll(I c);                   //!< call
I ret();                      //!< return
K Jj(K x,I n);

//:~
