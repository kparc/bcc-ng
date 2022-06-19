#include"a.h"
#include"i.h"

//!addresses of registers in function calling convention order
ZS a[]={"eax","edi","esi","edx","ecx","r8d","r9d","r10","r11d","ebx","r12d","r13d","r14d","r15d","ebp","esp"};
ZI A[]={ 0,    7,    6,    2,    1,    8,    9,    10,   11,    3,    12,    13,    14,    15,    5,    4   },
//      jmp  jb   jz   jnbe jmp32 jnb  jnz  jbe  jnb32
  jt[]={0xeb,0x72,0x74,0x77,0xe9, 0x73,0x75,0x76,0x0f83}; //!< jump table

I JT(I n){R jt[n];}I RG(I n){R A[n];}          //!< jump table entry, register

ZK c5(I o,I n){R cj(o,pn((S)&n,4));}
ZI m(I a,I b,I c){R 64*a+8*(7&b)+(7&c);}       //!< convert octal abc to int, used to fill mod(2),reg(3),r/m(3) byte

ZK rex(I r,I x,I b,K y){                       //!< rex instructions
 R(r=7<RG(r))+(x=7<RG(x))+(b=7<RG(b))          //!< 0x41=rex.b 0x42=rex.x 0x43=rex.xb 0x44=rex.r 0x45=rex.rb 0x46=rex.rx 0x47=rex.rxb
   ?cj(0x40+4*r+2*x+b,y):y;}

//! opcode o, arguments x y (not rex, x should never be >15)
ZK h(I o,I x,I y){R j2(
 256>o?c1(o):   //!< 1 byte opcode
 c2(o>>8,o),    //!< 2 byte opcode
 // 3 bit for mod, 3 bit for reg, 3 bit for r/m
 // mod 3 => register addressing mode:
 // 1st arg (x) in reg
 // 2nd arg (y) in r/m
 16>y?c1(m(3,x,y)):
 // mod 0 and r/m 5 => displacement only addressing mode:
 // 1st arg (x) in reg
 // 2nd arg (y) in 32 bit address following the instruction
 c5(m(0,x,5),y));}

ZK i(I o,I x,I y){R rex(16>x?x:0,0,16>y?y:0,h(o,16>x?RG(x):x-16,16>y?RG(y):y));}     //!< o opcode, xy arguments (maybe rex)

ZK f(I o,I x,I y){
 R 127>y
 //       0    1    2     3     4   5    6    7   8   9   10
 //ints:  mov  add  sub  imul       cmp  and              xor
 ?i((I[]){0x8b,0x03,0x2b,0x0faf,0x0,0x3b,0x23,0x0,0x0,0x0,0x33}[o],x,y)
 //                        0 1 234 5 6 78910                                                 //!< add,sub,cmp,and,or,xor
 :rex(0,0,x,o?c3(0x83,m(3," \0\5  \7\4\1  \6"[o],RG(x)),y-128):c5(0xb8+(7&RG(x)),y-128));}   //!< c5 move to register x

K psh(I t,I x){R rex(0,0,x,c1(0x50+(7&RG(x))));}                //!< push from reg A[x]
K pop(I t,I x){R rex(0,0,x,c1(0x58+(7&RG(x))));}                //!< pop to reg A[x]
K jmp(I n){R n<-128||n>127?c5(JT(4),0>n?n-3:n):c2(JT(0),n);}    //!< jump (c5 long c2 short)
K tst(I t,I x){R KF==t?AB("tst"):i(0x85,x,x);}                  //!< test (sets sz if x is not zero), nyi for floats
K cnd(I o,I x){O("(o=%d x=%s)\t\t\t-> ",o,a[x]);
 R j2(i(0x0f20+JT(o),16,x),i(0x0fb6,x,x));}       //!< cond (set byte on conditon functions: 0x0f90,...)
K jjj(K x,I n){R cj(0x0f,c5(16+xC[xn],n-4));}

#ifndef RV

//!return object code to execute opcode o with arguments x and y and store argument of type t in register r
K op(I t,I o,I r,I x,I y){K z;
 O("(t=%c o='%s%c%s' (%d) r=%s x=%s y=%-3s)\t-> "," chijefs CHIJEFS"[t],GRN,0==o?'M':5==o?'C':OPS[o],OFF,o,a[r],a[x],y<16?(char*)a[y]:128<y?(char*)pi(y-128):"mem");

 P(KF==t,8u>y-8?AB("vex"):j2(c2(0xc5,16*(8&~r)+8*(15&~x)+(5-o?3:1)),
  // for fp (with 0f prefix): i2f int to float
  //         0    1    2    3    4    5 6 7    8
  //       mov  add  sub  mul  div  cmp      i2f
  h((C[]){0x10,0x58,0x5c,0x59,0x5e,0x2e,0,0,0x2a}[o],r,y)))

 I a=126<y,s;

 //P(2==o,i(0xf7,16+3,r))                                       //!< FIXME neg

 P(0<=o&&r==x&&(!a||3-o),                                       //!< shl|shr
    4-o?                                                        //!< 4 is % forces arguments to be floats, for integers means right shift (/)
    f(o,r,y):
    129-y?AB("/"):                                              //!< shift by one or fail
    i(0xd1,16+7,r))                                             //!< right shift by one

 P(0<o&&r==y,z=f(o,r,x),2-o?z:j2(z,i(0xf7,16+3,r)))             //!< neg
 P((a?3:1)<o,j2(f(0,r,x),f(o,r,y)))

 R s=
    0<o?0:
    3+(o+1)/2,        //     mov  mov      lea  imul
    rex(r,a?0:y,x,c3(0>o?1&o?0x8b:0x89:3-o?0x8d:0x6b,m(3-o?a:3,RG(r),a?RG(x):4),a?(2-o?y-128:128-y)<<s:m(s,RG(y),RG(x))));}

K cll(I c){R c5(0xe8,c);}                                       //!< call
I ret(){R c1(0xc3);}                                            //!< return
#endif

//:~