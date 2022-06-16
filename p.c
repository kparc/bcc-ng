#include"a.h"
extern S tp;extern C N,L[26],T[26],D[2];extern K z,u(I u,K x),til(J x);I1(t);I U(I i);V1(dis);ZK p();

//!char class      !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
I c(I c){R 128>c?"   +$++ ()++ + +0000000000+;+++  aaaaaaaaaaaaaNOaaaaaaaWaaa[+]+ `aaaaaaaaaaaaaaaaaaaaaaaaaa{+} "[c-32]:0;}

ZK Na(){S r=tp;W(10u>*++tp-'0'||'.'==*tp){};I f=0;N(tp-r,f|='.'==r[i])R f?kf(fp(r,tp-r)):ki(ip(r,tp-r));} //!< int or float
ZS pq(){R sc((S)";})]",*tp);}I l(S s,I c){S t=sc(s,c);R t?t-s:0;}

// encode integers up to 127 as bytes with the highest bit set
// other numbers are appended at the end of z and return index
// (indices <16 correspond to registers, zn-3 is the index in
// the z is of K vals: z[0] is the source and z[1] is opcodes)
ZK1(n){R kc(KI==Ax&&129u>1+xi?128+xi:(z=jk(z,x),16+zn-3));}

ZK pE(I a,I c){         //!< parse an expr: c operator, a optional rettype
 K r=k1(kc(c)),x;       //!< store operator as char in K array
 do r=jk(r,x=pq()       //!< append parse trees of subsequent exprs to r
      ?n(ki(0))         //!< null-terminate expr when reached ;})]
      :p());            //!< parse the next expression
 W(';'==*tp++);         //!< semicolon is the only expression separator (FIXME multiline)
 R u(a?a:t(x),r);}      //!< force return type or use type of the last expr

//! parse next char on tape
ZK p(){K x,y;I a,b;                                            //!< a operator, xy operands, b return type
 S('0'-c('-'==(a=*tp++)?tp['.'==*tp]:'.'==a?*tp:a)?c(a):'0',   //!< special case: if expr starts with a minus, dot or a minus-dot, it may be a number
  case'N':T[N++]=KI;                                           //!< 'for' loop, increment loop variable (ij..) and fallthrough to W
  C('W',R                                                      //!< W|N(cnd){body}
   ++tp,x=p(),++tp,                                            //!<  parse cnd expr into x
   x=k3(kc(a),x,p()),                                          //!<  x is (W|N,cnd,body)
   N-='N'==a,x)                                                //!<  decrement loop variable (N loops only)
  case'$':++tp;                                                //!< $[ctf], fallthrough
  C('{',R pE(0,a))                                             //!< inner scope, descend and parse enclosed expression(s)
  C('+',R x=p(),                                               //!< operator: parse right operand and store rettype in xu:
   u('#'==a?KI:                                                //!<  count #x is int
     '%'==a?KF:                                                //!<  division x%y is float
     t(x)-8*('*'==a),                                          //!<  first *x is list type
     k2(kc(a),x)))                                             //!<  other ops inherit type of right operand
  C('[',R pE(12,a))                                            //!< parse a dyadic expression inside square brackets
  C('(',x=p(),++tp)                                            //!< parse a fenced expression
  C('0',                                                       //!< number:
   P('2'==a&&'*'==*tp,++tp,x=p(),                              //!<  translate 2*x to left shift \x, skip 2* and parse the right operand
    u(t(x),k2(kc('\\'),x)))                                    //!<  inherit type of x and return monadic tuple
   --tp;x=n(Na()))                                             //!<  parse a number
  C('a',                                                       //!< identifier:
   x='['==*tp?++tp,                                            //!<  a) if followed by [expr], it is an array indexing or a function call:
   pE(T[b=a-'a']?T[b]-8:                                       //!<   if varname has no type, it is a func call; for arrays, unset high bit
    (x=G[b],x=xy,                                              //!<   x is the varname, xy is the code
     *D=MX(*D,xC[xn-2]),D[1]=MX(D[1],xC[xn-1]),xu),a)          //!<   D[0] and D[1] are stored after RET, op is the array|function name (a)
     :kc(a)),                                                  //!<  b) if not, it is a variable reference.
  R AB(tp-1))                                                  //!< unmapped class is an error.
 P(pq(),x)                                                     //!< if reached end of expression, return its parse tree
 P('+'-c(a=*tp++),AB(tp-1))                                    //!< otherwise next char should be an operator:
 $(':'==*tp,++tp,a+=128);                                      //!< for assignment, set high bit of op char byte.
 b=t(y=p());                                                   //!< parse right operand into y and get its type into b
 $(':'==a&&Ax,T[xi-'a']=b)                                     //!< for assignment, rettype is the type of the right operand
  b='%'-a?MX(b,t(x)):KF;                                       //!< for div, force rettype to float, for all others uuse the widest one (KF>KJ>KI>KC)
 #define ff(x) (KF-b||KF==t(x)?x:Ax&&126<xi?n(kf(xi-128)):u(KF,k2(kc('%'),x)))
 R u(U('<')<U(a)?KI:b,                                         //!< if operator is a comparison (<=>), force return type to int
    k3(kc(a),ff(x),ff(y)));}                                   //!< return (op,left,right)

extern I M,a,RET;K v(I r,K x,I n),f(I r,K x),ev(K);I l(S s,I c),q(K);V1(lnk);

//!bracket balancer
#define BLIM 16
ZI m2(S s,S t){R*s==*t&&s[1]==t[1];}ZS bq(S x){W((x=sc(++x,'"'))&&!({I i=0;W('\\'==x[--i]);1&i;})){};R x;} //!< parse quoted string with esc sequences
ZS bb(S x){C b[BLIM];I n=0,a;S s;x-=1;
 W(*++x){
  $(m2((S)" /",x),s=sc(x,'\n');
  P(!s,n?x:0)x=s)
  $('"'==(a=c(*x)),s=bq(x);
  P(!s,x)x=s)
  $(sc("{[(",a),P(BLIM==++n,x)b[n]=*x)
  $(sc("}])",a),P(!n||b[n--]!=*x-1-*x/64,x));
 }R n?x:0;}//!< bracket balancer

K ps(S s){
 if(26u>*s-'a'&&!s[1]){K x=G[*s-'a'];Qs(NL==x,s)P(FN(x),os((S)xx),dis(xy),NL);}//!< FIXME quick hack to pretty print opcodes by referencing function name
 S b;P(b=bb(s),qs(*b?b:(S)"bal"))                //!< balance brackets
 a=0,N=8,*D=D[1]=1;N(26,L[i]=T[i]=0);M=0;tp=s;   //!< reset state
 S r='['==tp[1]&&(r=sc(tp,']'))&&*++r?r:0;
 K*k=r||':'==tp[1]?a=*tp,tp+=2,G+a-'a':0;
 P('!'==*tp,++tp,X(k,til(ki(ip(tp,sl(tp))))))
 P('"'==*tp,++tp,b=tp,X(k,pn(b,bq(tp)-b)))
 z=k2(kp(tp-!!r),NL); // !!r fix bracket
 if(!tp[1]&&26u>*tp-'a')r1(G[*tp-'a']);
 if(r){X(k,k2(r1(zx),u(KI,c2(1,1))));N(r-tp-1,L[23+i]=D[0]++,T[23+i]=l((S)" chijefs CHIJEFS",tp[i]))tp=r;}
 K x=p(); o(x);O("\n");
 N(23,if(T[i])L[i]=D[KF==T[i]]++)
 {
  I a=t(x); //!< type
  // z will contain:
  // - the evaluated string in x
  // - function value (machine code followed by D[0] and D[1]) with return type a
  // - arguments that do not fit in registers
  zy=u(a,j2(X0(Ax||'$'-*xC?f(0,x):v(0,x,0)),c3(RET,*D,D[1])));
  //dis(zy); // disasm
  dmp((S)"t/lnk.bin",zy); // dump
  lnk(zy);
 }
 //dis(zy); // disasm
 //N(26,O("%c: %p\n",'a'+i,G[i]))  // dump globals

 // k!=0 is assignment: function values are (src;bin) tuples,
 // everything else gets assigned with the evaluation result.
 // non-assignining expressions return their value to the printer.
 R k?X(k,r?z:Z0(ev(z))):z;}

//! ("[i]{source}";0xrtype0xopcodes0xconsts) xyu is return type k|f|j
K1(ev){x=xy,x=KS<xu?((K(*)())x)():KF==xu?kf(((F(*)())x)()):ki(((J(*)())x)());R x;}

//:~
