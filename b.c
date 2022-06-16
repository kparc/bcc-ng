#include"a.h" //asm("push %rbp;push %rbx");asm("pop %rbx;pop %rbp");MIN(y^(x^y)&x-y>>63)I low()__builtin_ctz(~i&-2);}V qq(I o,I r,I x,I y){oc(":+-*%?  c"[o]),oc('0'+r),oc('0'+x),oi(y);}
K3(l1);I c(I c),l(S,I),U(I i);K d(I r,K x);ZK c5(I o,I n){R cj(o,pn((S)&n,4));}
// :+-*% ^&|<=>  x64 JJ Jj o2 cc tst RET cll psh pop acdbsbsd89..  o[m[s|d]] c3 eb+1 e8+4 e9+4 [f2/66/4*][0f] 5* 7*+1 b*+4 0f8*+4  03 23 2b 3b (6b 83) 89 8b ..

K z;C N=8,D[2]={1,1},L[26],T[26];I M=0,a=0;S tp;

// 0 000 eax
// 1 001 ecx
// 2 010 edx
// 3 011 ebx
// 4 100 esp
// 5 101 ebp
// 6 110 esi
// 7 111 edi

//      eax edi esi edx ecx r8 r9,        ebx              ebp esp
ZI A[]={0,  7,  6,  2,  1,  8, 9,  10,11, 3,  12,13,14,15, 5,  4  },B=5,           //!< addresses of registers in function calling convention order
  //    jmp  jb   jz   jnbe jmp32 jnb  jnz  jbe   jnb32
  JJ[]={0xeb,0x72,0x74,0x77,0xe9, 0x73,0x75,0x76, 0x0f83};I RET=0xc3,CLL=0xe8;

K u(I u,K x){R xu=u,x;}                                                            //!< assign return type to function value
ZI m(I a,I b,I c){R 64*a+8*(7&b)+(7&c);}                                           //!< convert octal abc to int, used to fill mod(2),reg(3),r/m(3) byte

ZK rex(I r,I x,I b,K y){    //!< rex instructions
 // 0x41=rex.b  0x42=rex.x  0x43=rex.xb 0x44=rex.r
 // 0x45=rex.rb 0x46=rex.rx 0x47=rex.rxb
 R(r=7<A[r])+(x=7<A[x])+(b=7<A[b])?cj(0x40+4*r+2*x+b,y):y;}

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

ZK i(I o,I x,I y){R rex(16>x?x:0,0,16>y?y:0,h(o,16>x?A[x]:x-16,16>y?A[y]:y));}     //!< o opcode, xy arguments (maybe rex)
ZK psh(I t,I x){R rex(0,0,x,c1(0x50+(7&A[x])));}                                   //!< push from reg A[x]
ZK pop(I t,I x){R rex(0,0,x,c1(0x58+(7&A[x])));}                                   //!< pop to reg A[x]
ZK jmp(I n){R n<-128||n>127?c5(JJ[4],0>n?n-3:n):c2(*JJ,n);}                        //!< jump (c5 long c2 short)
ZK cc(I o,I x){R j2(i(0x0f20+JJ[o],16,x),i(0x0fb6,x,x));}                          //!< cond (set byte on conditon functions: 0x0f90,...)
ZK tst(I t,I x){R KF==t?AB("tst"):i(0x85,x,x);}                                    //!< test (sets sz if x is not zero), nyi for floats
ZK Jj(K x,I n){R cj(0x0f,c5(16+xC[xn],n-4));}
ZK cll(I c){R c5(CLL,c);}                                                          //!< call

//!opmap         01234567890123
I U(I i){R l((S)" +-*% &|  <=>",i);}           //!< TODO cst mod neq not flr ...

ZK o2f(I o,I x,I y){
R 127>y  //    0    1    2     3      4    5    6   7   8   9   10
    //ints:  mov  add  sub  imul         cmp  and              xor
    ?i((I[]){0x8b,0x03,0x2b,0x0faf, 0x0,0x3b,0x23,0x0,0x0,0x0,0x33}[o],x,y)
    :rex(0,0,x,o?c3(0x83,m(3," \0\5  \7\4\1  \6"[o],A[x]),y-128):c5(0xb8+(7&A[x]),y-128));}//!< move to register x
//                            0 1 234 5 6 78910                                            //!< add,sub,cmp,and,or,xor

//!return object code to execute opcode o with arguments x and y and leave the argument of type t in register r
ZK o2(I t,I o,I r,I x,I y){K z;//O("o2: t=%c o=%d r=%d x=%p y=%p\n"," chijefs CHIJEFS"[t],o,r,x,y);
 P(KF==t,8u>y-8?AB("vex"):j2(c2(0xc5,16*(8&~r)+8*(15&~x)+(5-o?3:1)),
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
 P((a?3:1)<o,j2(o2f(0,r,x),o2f(o,r,y))) //     mov  mov      lea imul
 R s=0<o?0:3+(o+1)/2,rex(r,a?0:y,x,c3(0>o?1&o?0x8b:0x89:3-o?0x8d:0x6b,m(3-o?a:3,A[r],a?A[x]:4),a?(2-o?y-128:128-y)<<s:m(s,A[y],A[x])));}

//!compare                             convert to float                    nyi
ZK cm(I t,I x,I y){R o2(t,5,x,x,y);}ZK cv(I x,I y){R o2(KF,8,x,x,A[y]);}ZK sh(I t,I r){R AB("sh");}

//!comparison|operator|funcall dispatch
ZK O2(I t,I f,I r,K x,K y){I i=Ay?yi:yu; //!< y is either value or function name
 R u(r,j3(
    Ay?c0():y,
    x,
    10>f?o2(t,f,r,xu,i):                        //!< function
    j2(cm(t,xu,i),16>r?cc(f-9,r):               //!< comparison
    c1(f-9))));}

ZK ZR(I t,C r){R u(r,o2(t,2,r,r,r));}           //!< set register r of type t to zero (2 is subtract, i.e. r-r=0)
ZK MV(I t,I r,K y){R O2(t,0,r,u(r,c0()),y);}    //!< move value y with type t to register r (0 is mov, the first arg is empty array)
ZK SH(I t,K y){R u(yu,j2(y,sh(t,yu)));}         //!< nyi

ZI1(hh){I t=T[xi-'a'];R 14==t?-2:13==t?-4:2*t-26;}
ZI1(q){I i=xi-'a';R Ax?26u>i&&L[i]?L[i]:0:':'==*xC?I(xy):0;}

//!type of x
I1(t){I a=xi-'a';
 I r=!Ax?xu:                              //!< not an atom is a function: xu holds rettype
  126<xi?KI:                              //!< small integer atom encoded in a single byte
  26u>a&&T[a]?T[a]:                       //!< local variable
  A(x=26u>a?G[a]:                         //!< global variable
    zK[2+xi-16])?Ax:                      //!< function argument (additional element of z)
  xt+8;R r;}                              //!< array (element type + 4th bit)

//!expr x to register r
ZK e(I r,K x){K y=d(r,x);if(Ay){
    I qz=128==yi||(32>yi&&!zK[2+yi-16]);  //!< if y is zero, either coded as a small int(128), or in the z array
    R qz?ZR(t(x),r)                       //!< set register to zero
        :MV(t(x),r,y);                    //!< otherwise move value to register
  }else R y;}                             //!< for arrays and functions, pass y.

ZK E(I r,K x){I i=xn-1;K z=e(r,Xx),y=kK(i--);r=zu,Yx=z;W(i--)Yx=e(0,xK[i+1]);R u(r,sS(0,y));}

//!branch out
ZK b(I f,K x){K y=d(16,x);R Ay?AB("b"):16==yu?yC[yn-1]=JJ[yC[yn-1]+f*4],y:j3(y,tst(t(x),yu),c1(JJ[f?2:6]));}

//!force: transform values and other expressions into object code, except conditional expressions, and move result to register r
K f(I r,K x){K y=e(r,x);R r-yu?MV(t(x),r,y):y;}//<! if not a function, move value y to register r

//!ctf
ZK vh(K x,I r,I n){R++tp,1<n?e(0,x):f(r,x);}
K v(I r,K x,I n){K y=xz,z;I c=!n&&!Ay&&a==*yC,l=M;
 z=vh(xK[3],r,n),M=l,y=vh(y,r,n),x=b(1,xy);
 y=j2(y,n||c?yn-=c*B,jmp(1-n?n-xn-yn-3:zn):c1(RET));R j3(jc(x,yn),y,z);}

//!while|for
ZV mm(K x){I i;$(Ax,if(26u>xi-'a'&&L[i=xi-'a'])M|=1<<L[i])$(':'==*xC&&A(xy),i=I(xy)-'a',M&=~(1<<L[i]),mm(xz))N(xn,mm(sc((S)"{WNC",*xC)?xK[xn-1-i]:Xx))}
ZK1(w){I i='N'==*xC?L[N++]:0,j=0;mm(x);K y=xy,z=xz;I jj;
 P(!i&&!Az&&'$'==*zC,x=b(1,y),z=v(0,z,-xn-1),jj=-xn-1-zn-2,j3(jc(x,zn+2),z,jmp(jj)))
 x=i?M|=1<<i,jc(cm(0,i,j=(j=q(y))?j:*D),JJ[1]):b(0,y),z=i?j2(e(0,z),o2(0,1,i,i,129)):e(0,z);
 I n=-zn-xn-1;z=j3(jmp(zn),z,n<-128?--xn,j2(x,Jj(x,n)):jc(x,n));R i?--N,M&=~(1<<i),j3(f(j,y),ZR(0,i),z):z;}

ZK g(I c,K x){K y=c0(),z,r=c0();I i=0,l=a?M:0;W(++i<xn){z=Xx;I l=M&1<<i,b=Az||128>*zC&&':'-*zC||i-L[I(zy)-'a'],h=2-i||Az||26>c;z=f(i,z);if(!h)z=j3(psh(0,3),z,pop(0,3));
 if(l)z=j2(b?psh(0,i):z,b?z:psh(0,i)),r=j2(r,pop(0,i));y=j2(z,y);}
 z=cll(c);W(i<16){if(l&1<<i)z=j3(psh(0,i),z,pop(0,i));++i;}R j3(y,z,r);}

//!to register, constant or global
K d(I r,K x){
 P(Ax,(r=q(x))?M|=1<<r,u(r,c0()):x)
 I s=15&r,a;K y,z;
 S((y=xy,c(a=*xC)), //!< a is function, y is 1st argument
  case'N':
  C('W',R w(x))
  C('$',R u(r,v(r,x,1)))
  C('{',R E(r,x))
  C('[',R g(26,x))
  C('a',R T[a-'a']?O2(0,1+hh(xx),s,d(0,xx),d(0,y)):g(a-'a',x))
  //C('O',R O("aha\n"),o(xy),O("--\n"))
  C(0,R y=d(0,y),O2(t(x),U(a-128),yu,y,d(s,xz))),

  if(':'==a){
   P(Ay,r=L[yi-'a'],M&=~(1<<r),f(r,xz))
   y=d(0,yy),z=e(s,xz),x=xy;
   R r=zu,u(r,j2(z,O2(0,hh(xx),r,d(0,xx),y)));}

  //! monadic ops
  I m,b=t(y);
  P(3>xn,
   '&'==a?SH(b,e(0,y)):
   '%'==a?y=e(0,y),u(s,j2(y,cv(s,yu))):         //!< conversion to float
   '\\'==a?y=e(s,y),O2(b,1,s,u(yu,c0()),y):     //!< shift left, implemented as addition to itself
   O2(
    0,
    '#'==a?-3:                                  //!< number of elements
    '*'==a?1+hh(y):                             //!< deref / 1st element
    '/'==a?4:                                   //!< shift right (4 is div for floats, shr for ints)
    U(a),                                       //!< dyadic function
    s,
    e(s,y),                                     //!< first argument is y
    kc(128+('#'==a?-1:'*'!=a))                  //!< second argument is one (kc(129)) or kc(127) for # (why?) or zero for * (why?)
   )
  )
  z=xz;                                         //!< z is the second argument
  a=U(a),r=U('<')<a||16-r?r:0;                  //!< a is func number, r will be zero for the 1st literal long argument if the op is not a comparison
  P(!Ay&&!q(y)&&!Az&&!q(y),                     //!< FIXME bug? last one: q(z)
   M|=1<<(m=D[KF==b]++),
   y=e(0,y),M&=~(1<<m),
   z=O2(b,a,r,y,f(m,z)),
   --D[KF==b],z)

  R Ay&&!q(y)&&2-a&&4-a
   ?O2(b,U('<')<a?11-a+11:a,r,e(s,z),y)
   :O2(b,a,r,e(s,y),d(s,z))
 )}

//!opcode length
ZI ln(S s){I o=*s++,      //!< opcode
    h=o/16,               //!< first hex digit of opcode
    p=0xc5==o?2:0x0f==o;  //!< add 2 for invalid opcode, 1 for 2 byte opcodes
    R 
     4==h?1+ln(s):        //!< h=4 rex
     RET==o||5==h?1:      //!< h=5 push/pop
     *JJ==o||7==h?2:      //!< h=7 conditional jumps
     0xe==h||0xb==h?5:    //!< h=0xe call, h=0xb mov
     p&&8==*s/16?6:       //!< conditional jumps
     // 3==s[p]/64 => mod == 11 => r/m is a register
     //               add      imul
     p+(3==s[p]/64?2+(0x83==o||0x6b==o):
     // displacement addressing mode: the instruction
     // will have one instruction byte, one for mod,reg,r/m
     // and four for the address, else instruction, mod,reg,r/m
     // and one byte for the register
     5==(0xc7&s[p])?6:3);}

//!fix relative addresses
V1(lnk){S s=xC;W(s<xC+xn){
 I n=ln(s+=4==*s/16),p=0xc5==*s?2:0x0f==*s;S r=s+n-4; //!< 4==*s/16 => rex instruction, skip it
 if(0xe8==*s|| //!< function call
    (p?8-s[1]/16:4>*s/16||8==*s/16)&&5==(0xc7&s[1+p])) //!< check if instruction uses relative address argument:
  *(I*)r=(0xe8==*s?a-'a'==*r?x:26==*r?(K)l1:((K*)G[*r])[1]:32>*r?(K)&zF[2+*r-16]:(K)(G+*r-'a'))-(K)r-4;
 s+=n;}}

//!pretty print function opcodes and its return type
//V1(dis){w2(px(xu)),oc(':');S s=xC;W(s<xC+xn-2){N(ln(s),w2(px(*s++)))oc(' ');}N(2,w2(px(*s++)))nl();}
V1(dis){S s=xC;oc(' ');W(s<xC+xn-2){oc(' ');N(ln(s),w2(px(*s++)));};oc(' ');N(2,w2(px(*s++)))w2(" -> ");oc(KS<xu?'K':KF==xu?'f':KI==xu?'j':KC==xu?'c':'?');nl();}

//:~
