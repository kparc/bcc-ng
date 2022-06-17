#include"a.h"
#include"i.h"

// 000 eax 001 ecx 010 edx 011 ebx 100 esp 101 ebp 110 esi 111 edi
ZS a[]={"eax","edi","esi","edx","ecx","r8", "r9","r10","r11","ebx","r12","r13","r14","r15","ebp","esp"};
ZI A[]={0,    7,     6,    2,    1,    8,    9,  10,   11,    3,    12,   13,   14,   15,   5,    4   }, //!< addresses of registers in function calling convention order
  //    jmp  jb   jz   jnbe jmp32 jnb  jnz  jbe   jnb32
  jt[]={0xeb,0x72,0x74,0x77,0xe9, 0x73,0x75,0x76, 0x0f83},CLL=0xe8,RET=0xc3;       //!< jump table
I JT(I n){R jt[n];}ZI REG(I n){R A[n];}                                             //!< jump table entry, register

ZK c5(I o,I n){R cj(o,pn((S)&n,4));}
ZI m(I a,I b,I c){R 64*a+8*(7&b)+(7&c);}                          //!< convert octal abc to int, used to fill mod(2),reg(3),r/m(3) byte

ZK rex(I r,I x,I b,K y){                                          //!< rex instructions
 R(r=7<REG(r))+(x=7<REG(x))+(b=7<REG(b))?cj(0x40+4*r+2*x+b,y):y;} //!< 0x41=rex.b 0x42=rex.x 0x43=rex.xb 0x44=rex.r 0x45=rex.rb 0x46=rex.rx 0x47=rex.rxb

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

ZK i(I o,I x,I y){R rex(16>x?x:0,0,16>y?y:0,h(o,16>x?REG(x):x-16,16>y?REG(y):y));}     //!< o opcode, xy arguments (maybe rex)

ZK o2f(I o,I x,I y){R 127>y
    //       0    1    2     3     4   5    6    7   8   9   10
    //ints:  mov  add  sub  imul       cmp  and              xor
    ?i((I[]){0x8b,0x03,0x2b,0x0faf,0x0,0x3b,0x23,0x0,0x0,0x0,0x33}[o],x,y)
    //                        0 1 234 5 6 78910                                             //!< add,sub,cmp,and,or,xor
    :rex(0,0,x,o?c3(0x83,m(3," \0\5  \7\4\1  \6"[o],REG(x)),y-128):c5(0xb8+(7&REG(x)),y-128));} //!< move to register x

//!return object code to execute opcode o with arguments x and y and leave the argument of type t in register r
K op(I t,I o,I r,I x,I y){K z;O("op(t=%c o=%x r=%s x=%d y=%d)\n"," chijefs CHIJEFS"[t],o,a[r],x,y);
 P(KF==t,
  8u>y-8?AB("vex"):j2(c2(0xc5,16*(8&~r)+8*(15&~x)+(5-o?3:1)),
  // for fp (with 0f prefix): i2f int to float
  //         0    1    2    3    4    5 6 7    8
  //       mov  add  sub  mul  div  cmp      i2f
  h((C[]){0x10,0x58,0x5c,0x59,0x5e,0x2e,0,0,0x2a}[o],r,y)))

 I a=126<y,s;
 P(0<=o&&r==x&&(!a||3-o),                                    //!< shl|shr
    4-o?o2f(o,r,y):                                          //!< 4 is % forces arguments to be floats, for integers means right shift (/)
    129-y?AB("/"):                                           //!< shift by one or fail
    i(0xd1,16+7,r))                                          //!< right shift by one
 P(0<o&&r==y,z=o2f(o,r,x),2-o?z:j2(z,i(0xf7,16+3,r)))        //!< neg
 P((a?3:1)<o,j2(o2f(0,r,x),o2f(o,r,y)))
 R s=
    0<o?0:
    3+(o+1)/2,        //     mov  mov      lea  imul
    rex(r,a?0:y,x,c3(0>o?1&o?0x8b:0x89:3-o?0x8d:0x6b,m(3-o?a:3,REG(r),a?REG(x):4),a?(2-o?y-128:128-y)<<s:m(s,A[y],A[x])));}

K psh(I t,I x){R rex(0,0,x,c1(0x50+(7&REG(x))));}                                  //!< push from reg A[x]
K pop(I t,I x){R rex(0,0,x,c1(0x58+(7&REG(x))));}                                  //!< pop to reg A[x]
K jmp(I n){R n<-128||n>127?c5(JT(4),0>n?n-3:n):c2(JT(0),n);}                       //!< jump (c5 long c2 short)
K tst(I t,I x){R KF==t?AB("tst"):i(0x85,x,x);}                                     //!< test (sets sz if x is not zero), nyi for floats
K cnd(I o,I x){R j2(i(0x0f20+JT(o),16,x),i(0x0fb6,x,x));}                          //!< cond (set byte on conditon functions: 0x0f90,...)
K jjj(K x,I n){R cj(0x0f,c5(16+xC[xn],n-4));}
K cll(I c){R c5(CLL,c);}                                                           //!< call
I ret(){R RET;}                                                                    //!< return

//:~