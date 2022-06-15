#include"a.h"

extern S tp;extern C N,L[26],T[26],D[2];extern K z,u(I u,K x);I1(t);I U(I i);

                // !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
I c(I c){R 128>c?"   +$++ ()++ + +0000000000+;+++  aaaaaaaaaaaaaNOaaaaaaaWaaa[+]+ `aaaaaaaaaaaaaaaaaaaaaaaaaa{+} "[c-32]:0;}

ZK Na(){S r=tp;W(10u>*++tp-'0'||'.'==*tp){};I f=0;N(tp-r,f|='.'==r[i])R f?kf(fp(r,tp-r)):ki(ip(r,tp-r));}
ZS pq(){R sc((S)";})]",*tp);}K1(n){R kc(KI==Ax&&129u>1+xi?128+xi:(z=jk(z,x),16+zn-3));}ZK p();
ZK pE(I a,I c){K r=k1(kc(c)),x;do r=jk(r,x=pq()?n(ki(0)):p());W(';'==*tp++);R u(a?a:t(x),r);}

ZK p(){K x,y;I a,b;
 S('0'-c('-'==(a=*tp++)?tp['.'==*tp]:'.'==a?*tp:a)?c(a):'0',
  case'N':T[N++]=KI;
  C('W',R++tp,x=p(),++tp,x=k3(kc(a),x,p()),N-='N'==a,x)
  //C('O',R++tp,x=p(),++tp,x=k2(kc(a),x),x)
  case'$':++tp;
  C('{',R pE(0,a))
  C('+',R x=p(),u('#'==a?KI:'%'==a?KF:t(x)-8*('*'==a),k2(kc(a),x)))
  C('[',R pE(12,a))
  C('(',x=p(),++tp)
  C('0',P('2'==a&&'*'==*tp,++tp,x=p(),u(t(x),k2(kc('\\'),x)))--tp;x=n(Na()))
  C('a',
   x='['==*tp?++tp,
   pE(T[b=a-'a']?T[b]-8:(x=G[b],x=xy,*D=MX(*D,xC[xn-2]),D[1]=MX(D[1],xC[xn-1]),xu),a):kc(a)),
  R AB(tp-1))
 P(pq(),x)
 P('+'-c(a=*tp++),AB(tp-1))
 $(':'==*tp,++tp,a+=128);
 b=t(y=p());
 $(':'==a&&Ax,T[xi-'a']=b)b='%'-a?MX(b,t(x)):KF;
 #define ff(x) (KF-b||KF==t(x)?x:Ax&&126<xi?n(kf(xi-128)):u(KF,k2(kc('%'),x)))
 R u(U('<')<U(a)?KI:b,k3(kc(a),ff(x),ff(y)));}

extern I M,a,RET;K v(I r,K x,I n),f(I r,K x);I l(S s,I c);I1(q);V1(lnk);K1(ev);

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
   if(sc("}])",a))P(!n||b[n--]!=*x-1-*x/64,x)
 }R n?x:0;}//!< bracket balancer

K ps(S s){
 S b;P(b=bb(s),qs(*b?b:(S)"bal")) //<! balance brackets
 a=0,N=8,*D=D[1]=1;N(26,L[i]=T[i]=0);M=0;tp=s; //!< reset
 S r='['==tp[1]&&(r=sc(tp,']'))&&*++r?r:0;K*k=r||':'==tp[1]?a=*tp,tp+=2,G+a-'a':0;
 P('!'==*tp,++tp,X(k,enm(ki(ip(tp,sl(tp))))))
 z=k2(kp(tp),NL);
 if(!tp[1]&&26u>*tp-'a')r1(G[*tp-'a']);
 if(r){X(k,k2(r1(zx),u(KI,c2(1,1))));N(r-tp-1,L[23+i]=D[0]++,T[23+i]=l((S)" chijefs CHIJEFS",tp[i]))tp=r;}
 K x=p(); o(x);O("\n");
 N(23,if(T[i])L[i]=D[KF==T[i]]++)
 {
  I a=t(x);
  zy=u(a,j2(X0(Ax||'$'-*xC?f(0,x):v(0,x,0)),c3(RET,*D,D[1])));
  //dis(zy); // disasm
  dmp((S)"t/lnk.bin",zy); // dump
  lnk(zy);
 }
 //dis(zy); // disasm
 //N(26,O("%c: %p\n",'a'+i,G[i]))  // globals

 // k!=0 is assignment: function values are (src;bin) tuples,
 // everything else gets assigned with the evaluation result.
 // non-assignining expressions return their value to the printer.
 R k?X(k,r?z:Z0(ev(z))):z;}

//! ("[i]{source}";0xrtype0xopcodes0xconsts) xyu is return type k|f|j
K1(ev){x=xy,x=KS<xu?((K(*)())x)():KF==xu?kf(((F(*)())x)()):ki(((J(*)())x)());R x;}

//:~
