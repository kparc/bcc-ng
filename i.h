#include"c.h"
// :+-*% ^&|<=>  x64 JJ Jj o2 cc tst RET cll psh pop acdbsbsd89..  o[m[s|d]] c3 eb+1 e8+4 e9+4 [f2/66/4*][0f] 5* 7*+1 b*+4 0f8*+4  03 23 2b 3b (6b 83) 89 8b ..

#define oOP() O("(t=%c o='%s%c%s' (%d) r=%s x=%s y=%-3s (%x))\t-> "," chijefs CHIJEFS"[t],GRN,0==o?'M':5==o?'C':OPS[o],OFF,o,a[r],a[x],y<16?(char*)a[y]:128<y?(char*)pi(y-128):"mem", 128<y?0:y)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wpedantic"

extern S OPS;                 //!< operator map

ZI B=5;I JT(I n),RG(I n);     //!< register, jump table entry

K op(I t,I o,I r,I x,I y);    //!< return object code to execute opcode o with arguments x and y and leave the argument of type t in register r
K cnd(I o,I x);               //!< cond (set byte on conditon functions: 0x0f90,...)
K psh(I t,I x);               //!< push from reg A[x]
K pop(I t,I x);               //!< pop to reg A[x]
K tst(I t,I x);               //!< test (sets sz if x is not zero), nyi for floats
K jmp(I n);                   //!< jump (c5 long c2 short)
K cll(I c);                   //!< call
K jjj(K x,I n);
K ret();                      //!< return from subroutine

#define xI ((I*)x)
#define xn xI[-1]
#define Xi xI[i]
#define Xc ((S)x)[i]

#ifndef TEST

#ifndef RV
ZK inst (K x){N(xn,O("%.2x%c",Xc,i==(xn-1)?0:' '))R O("\n"),x;}
#else
ZK inst(K x){_N(xn,O("%.2x",Xc));R O("\n"),x;}
#endif

#define trc(ff,f,a...) (O("   %s ",#ff),fflush(0),inst(f(a)))
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
