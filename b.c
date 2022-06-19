#include"a.h" //asm("push %rbp;push %rbx");asm("pop %rbx;pop %rbp");MIN(y^(x^y)&x-y>>63)I low()__builtin_ctz(~i&-2);}V qq(I o,I r,I x,I y){oc(":+-*%?  c"[o]),oc('0'+r),oc('0'+x),oi(y);}
#include"i.h"
K3(l1);I c(I c),l(S,I),U(I i);K d(I r,K x);

// D    0 local vars/args 1 local floats
// L/T  values and types of D
// N    current loop counter (i,j,k,l..)
// M    used register count
// a    target variable (for assignments)
// tp   tape
K z;C N=8,D[2]={1,1},L[26],T[26];I M=0,a=0;S tp;

//!ops    01234567890123
S OPS=(S)" +-*% &|  <=>";              //!< TODO cst mod neq not flr ...

I U(I i){R l(OPS,i);}
K u(I u,K x){R xu=u,x;}                //!< assign return type to function value

//!compare                             convert to float                     nyi
ZK cm(I t,I x,I y){R OP(t,5,x,x,y);}ZK cv(I x,I y){R OP(KF,8,x,x,RG(y));}ZK sh(I t,I r){R AB("sh");}

//!dispatch comparison|operator|funcall
ZK o2(I t,I f,I r,K x,K y){I i=Ay?yi:yu;        //!< y is either value or function name
 R u(r,j3(
    Ay?c0():y,
    x,
    10>f?OP(t,f,r,xu,i):                        //!< function
    j2(cm(t,xu,i),16>r?CND(f-9,r):c1(f-9))      //!< comparison
    ));}

ZK ZR(I t,C r){R u(r,OP(t,2,r,r,r));}           //!< set register r of type t to zero (2 is subtract, i.e. r-r=0)
ZK MV(I t,I r,K y){R o2(t,0,r,u(r,c0()),y);}    //!< move value y with type t to register r (0 is mov, the first arg is empty array)
ZK SH(I t,K y){R u(yu,j2(y,sh(t,yu)));}         //!< nyi

ZI1(q){I i=xi-'a';R Ax?26u>i&&L[i]?L[i]:0:':'==*xC?I(xy):0;}

//!type of x
I1(t){I a=xi-'a';
 I r=!Ax?xu:                                    //!< not an atom is a function: xu holds rettype
  126<xi?KI:                                    //!< small integer atom encoded in a single byte
  26u>a&&T[a]?T[a]:                             //!< local variable
  A(x=26u>a?G[a]:                               //!< global variable
    zK[2+xi-16])?Ax:                            //!< function argument (additional element of z)
  xt+8;R r;}                                    //!< array (element type + 4th bit)

//!expr x to register r
ZK e(I r,K x){//O("e: r=%d ",r);fflush(0);o(r1(x));
 K y=d(r,x);
 if(Ay){
  I qz=128==yi||(32>yi&&!zK[2+yi-16]);          //!< if y is zero, either coded as a small int(128), or in the z array
  R qz?ZR(t(x),r)                               //!< set register to zero
      :MV(t(x),r,y);                            //!< otherwise move value to register
 }else R y;}                                    //!< for arrays and functions, pass y.

ZK E(I r,K x){I i=xn-1;K z=e(r,Xx),y=kK(i--);r=zu,Yx=z;W(i--)Yx=e(0,xK[i+1]);R u(r,sS(0,y));}

//!branch out
ZK b(I f,K x){K y=d(16,x);R Ay?AB("b"):16==yu?yC[yn-1]=JT(yC[yn-1]+f*4),y:j3(y,TST(t(x),yu),c1(JT(f?2:6)));}

//!force: transform values and other expressions into object code, except conditional expressions, and move result to register r
K f(I r,K x){//O("f: r=%d ",r);fflush(0);o(r1(x));
 K y=e(r,x);
 R r-yu?MV(t(x),r,y):y;} //<! if not a function, move value y to register r

//!ctf
ZK vh(K x,I r,I n){R++tp,1<n?e(0,x):f(r,x);}
K v(I r,K x,I n){K y=xz,z;I c=!n&&!Ay&&a==*yC,l=M;
 z=vh(xK[3],r,n),M=l,y=vh(y,r,n),x=b(1,xy);
 y=j2(y,n||c?yn-=c*B,JMP(1-n?n-xn-yn-3:zn):ret());
 R j3(jc(x,yn),y,z);}

//!while|for
ZV1(mm){I i;$(Ax,if(26u>xi-'a'&&L[i=xi-'a'])M|=1<<L[i])$(':'==*xC&&A(xy),i=I(xy)-'a',M&=~(1<<L[i]),mm(xz))N(xn,mm(sc((S)"{WNC",*xC)?xK[xn-1-i]:Xx))}
ZK1(w){I i='N'==*xC?L[N++]:0,j=0;mm(x);K y=xy,z=xz;I jj;
 P(!i&&!Az&&'$'==*zC,x=b(1,y),z=v(0,z,-xn-1),jj=-xn-1-zn-2,j3(jc(x,zn+2),z,JMP(jj)))
 x=i?M|=1<<i,jc(cm(0,i,j=(j=q(y))?j:*D),JT(1)):b(0,y),z=i?j2(e(0,z),OP(0,1,i,i,129)):e(0,z);
 I n=-zn-xn-1;z=j3(JMP(zn),z,n<-128?--xn,j2(x,JJJ(x,n)):jc(x,n));R i?--N,M&=~(1<<i),j3(f(j,y),ZR(0,i),z):z;}

ZK g(I c,K x){//O("g: c=%d ",c);fflush(0);o(r1(x));
 K y=c0(),z,r=c0();I i=0,l=a?M:0;
 W(++i<xn){
  z=Xx;I l=M&1<<i,b=Az||128>*zC&&':'-*zC||i-L[I(zy)-'a'],h=2-i||Az||26>c;z=f(i,z);
  $(!h,z=j3(PSH(0,3),z,POP(0,3)));
  $( l,z=j2(b?PSH(0,i):z,b?z:PSH(0,i)),r=j2(r,POP(0,i)));
  y=j2(z,y);}
 z=CLL(c);
 W(i<16){if(l&1<<i)z=j3(PSH(0,i),z,POP(0,i));++i;}
 R j3(y,z,r);}

ZI1(hh){I t=T[xi-'a'];R 14==t?-2:13==t?-4:2*t-26;}

//!to register, constant or global
K d(I r,K x){//O("d: r=%d ",r);fflush(0);o(r1(x));
 P(Ax,(r=q(x))?M|=1<<r,u(r,c0()):x)
 I s=15&r,a;K y,z;
 S((y=xy,c(a=*xC)), //!< a is function, y is 1st argument
  case'N':
  C('W',R w(x))
  C('$',R u(r,v(r,x,1)))
  C('{',R E(r,x))
  C('[',R g(26,x))
  C('a',R T[a-'a']?o2(0,1+hh(xx),s,d(0,xx),d(0,y)):g(a-'a',x))
  //C('O',R O("aha\n"),o(xy),O("--\n"))
  C(0,R y=d(0,y),o2(t(x),U(a-128),yu,y,d(s,xz))),

  $(':'==a,
   P(Ay,r=L[yi-'a'],M&=~(1<<r),f(r,xz))
   y=d(0,yy),z=e(s,xz),x=xy;
   R r=zu,u(r,j2(z,o2(0,hh(xx),r,d(0,xx),y))));

  //! monadic ops
  I m,b=t(y);
  P(3>xn,
   '&'==a?SH(b,e(0,y)):
   '%'==a?y=e(0,y),u(s,j2(y,cv(s,yu))):         //!< conversion to float
   '\\'==a?y=e(s,y),o2(b,1,s,u(yu,c0()),y):     //!< shift left, implemented as addition to itself
   o2(
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
   z=o2(b,a,r,y,f(m,z)),
   --D[KF==b],z)

  R Ay&&!q(y)&&2-a&&4-a
   ?o2(b,U('<')<a?11-a+11:a,r,e(s,z),y)
   :o2(b,a,r,e(s,y),d(s,z))
 )}

//!opcode length
ZI ln(S s){I o=*s++,      //!< opcode
    h=o/16,               //!< first hex digit of opcode
    p=0xc5==o?2:0x0f==o;  //!< add 2 for invalid opcode, 1 for 2 byte opcodes
    R 
     4==h?1+ln(s):        //!< h=4 rex
     ret()==o||5==h?1:    //!< h=5 push/pop
     JT(0)==o||7==h?2:    //!< h=7 conditional jumps
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
V1(dis){S s=xC;oc(' ');W(s<xC+xn-2){oc(' ');N(ln(s),w2(px(*s++)));};oc(' ');N(2,w2(px(*s++)))w2((S)" -> ");oc(KS<xu?'K':KF==xu?'f':KI==xu?'j':KC==xu?'c':'?');nl();}

//:~
