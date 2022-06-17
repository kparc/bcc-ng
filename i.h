#include"c.h"
// :+-*% ^&|<=>  x64 JJ Jj o2 cc tst RET cll psh pop acdbsbsd89..  o[m[s|d]] c3 eb+1 e8+4 e9+4 [f2/66/4*][0f] 5* 7*+1 b*+4 0f8*+4  03 23 2b 3b (6b 83) 89 8b ..

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wint-conversion"
//#pragma GCC diagnostic ignored "-Wpedantic"

ZI B=5;I JT(I n),REG(I n);    //!< register, jump table entry

K op(I t,I o,I r,I x,I y);    //!< return object code to execute opcode o with arguments x and y and leave the argument of type t in register r
K cnd(I o,I x);               //!< cond (set byte on conditon functions: 0x0f90,...)
K psh(I t,I x);               //!< push from reg A[x]
K pop(I t,I x);               //!< pop to reg A[x]
K tst(I t,I x);               //!< test (sets sz if x is not zero), nyi for floats
K jmp(I n);                   //!< jump (c5 long c2 short)
K cll(I c);                   //!< call
I ret();                      //!< return
K jjj(K x,I n);

#define xI ((I*)x)
#define xn xI[-1]
#define Xi xI[i]
#define Xc ((S)x)[i]

#ifndef TEST
ZK inst(K x){N(xn,O("%.2x%c",Xc,i==(xn-1)?0:' '));O("\n");R x;}
#define trc(ff,f,a...) (O("%s: ",#ff),fflush(0),inst(f(a)))
#else
#define trc(ff,f,a...) f(a)
#endif

#define OP(a...)  trc(OP,op,a)
#define CND(a...) trc(CND,cnd,a)
#define PSH(a...) trc(PSH,psh,a)
#define POP(a...) trc(POP,pop,a)
#define TST(a...) trc(TST,tst,a)
#define JMP(a...) trc(JMP,jmp,a)
#define CLL(a...) trc(CLL,cll,a)
#define JJJ(a...) trc(JJJ,jjj,a)

//:~
