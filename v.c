#include"a.h"
#include"i.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wpedantic"

extern S OPS;                 //!< operator map

//       0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15    16    17   18   19   20   21
ZS a[]={"a0","a1","a2","a3","a4","a5","a6","a7","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","t3","t4","t5","t6"};
ZI A[]={ 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,   26,   27,  28,  29,  30,  31 };

#define V UI
ZK rv(V i){R pn((S)&i,4);}

ZK EU(V o,V f3,V rd,V s1,V im)       {R rv(o|f3<<12|rd<<7|s1<<15|im<<20);}
ZK EI(V o,V f3,V rd,V s1,V im)       {R EU(o,f3,rd,s1,im);}
ZK ER(V o,V f3,V rd,V s1,V s2,V f7)  {R rv(o|f3<<12|rd<<7|s1<<15|s2<<20|f7<<25);}
ZK ES(V o,V f3,V s1,V s2,V im)       {R rv(o|f3<<12|(im&0x1f)<<7|s1<<15|s2<<20|((im>>5)<<25));}

#ifdef RV

//!return object code to execute opcode o with arguments x and y and store argument of type t in register r
K op(I t,I o,I r,I x,I y){oOP();

 P(KF==t,AB("vop: rv float nyi\n"))

 K z=0;I a=126<y,ll=0;//I ll=a?0:8; // rv32/64
 r=A[r],x=A[x],y=a?y-128:A[y];

 #define IR(l,f3,r,x,y,f7) z=a?EI(0x13|l,f3,r,x,y):ER(0x33|l,f3,r,x,y,f7) 

 S(OPS[o],
    C('+',  IR(ll,     0,r,x,y,0))       // add  d,a,b
    C('-',  IR(ll,     0,r,x,y,0x20))    // sub  d,a,b
    C('^',  IR(0,      4,r,x,y,0))       // xor  d,a,b
    C('|',  IR(0,      6,r,x,y,0))       // or   d,a,b
    C('&',  IR(0,      7,r,x,y,0))       // and  d,a,b
    C('*',  IR(ll,     0,r,x,y,1))       // mul  d,a,b
    C('%',  IR(ll,     4,r,x,y,1))       // div  d,a,b
    C('\\', IR(ll|ll,  5,r,x,y,0))       // srl  d,a,b
    C('/',  IR(ll,     1,r,x,y,0))       // sll  d,a,b
    C(' ',z=EI(0x13,   0,r,y,0))         // mv   d,s  (addi rd, rs, 0)
    //C('%', ER(ll?0x3b:0x33,6,d,a,b,1))     // rem  d,a,b
    //C(SAR, ER(0x33|ll|ll,  5,d,a,b,0x20))  // sra  d,a,b
    //C(UMOD,ER(0x33|ll,     7,d,a,b,1))     // remu d,a,b
    //C(UDIV,ER(0x33|ll,     5,d,a,b,1))     // divu d,a,b (also PDIV)
    ,O("vop nyi: %c",o);R AB("NYI"))

 //P(2==o,i(0xf7,16+3,r))                                       //!< FIXME neg

// P(0<=o&&r==x&&(!a||3-o),                                       //!< shl|shr
//    4-o?f(o,r,y):                                               //!< 4 is % forces arguments to be floats, for integers means right shift (/)
//    129-y?AB("/"):                                              //!< shift by one or fail
//    i(0xd1,16+7,r))                                             //!< right shift by one
// P(0<o&&r==y,z=f(o,r,x),2-o?z:j2(z,i(0xf7,16+3,r)))             //!< neg

 //P((a?3:1)<o,j2(f(0,r,x),f(o,r,y)))

// R s=
//    0<o?0:
//    3+(o+1)/2,        //     mov  mov      lea  imul
//    rex(r,a?0:y,x,c3(0>o?1&o?0x8b:0x89:3-o?0x8d:0x6b,m(3-o?a:3,RG(r),a?RG(x):4),a?(2-o?y-128:128-y)<<s:m(s,A[y],A[x])));

 //_N(4,O("%.2x",((S)&z)[i]))O("->");

 R z;}

K cll(){
  I docall=1,tr=docall?1:5;       //!< ra or t0
  R j2(EU(0x17,0,0,0,(1<<7)),     //!< auipc TR, 0 %call(func)
       EI(0x67,0,tr,tr,0));}      //!< jalr  TR, r(TR)

//call offset                       Call far-away subroutine
//    auipc  x1, offset[31:12]
//    jalr   x1, x1, offset[11:0]

//tail offset                       Tail call far-away subroutine
//    auipc x6, offset[31:12]
//    jalr  x0, x6, offset[11:0]

K ret(){R EI(0x67,0,0,1,0);};     //!< jalr x0,x1,0 aka ret
#endif

//:~
