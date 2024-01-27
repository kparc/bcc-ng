#include"a.h"// read/write mmap/munmap printf/scanf malloc/free
extern J AWS;K3(l1);K1(l2);K mf(S s,J*n);//m.c

V w2(S s){write(2,s,sl(s));}ZS r2(S s){ZC b[256];R w2(s),b[read(0,b,256)-1]=0,b;}//ZI rand(){ZJ j0=-314159;R j0=4294957665L*j0+(j0>>32);}
ZK _dmp(S s,S x,J n){I d=open((V*)s,O_RDWR|O_CREAT|O_TRUNC,S_IRWXU);Qs(0>d,(S)s)write(d,x,n);R close(d),0;}K dmp(S s,K x){R _dmp(s,xC,xn-2);}

// printf scanf 
ZC b[24];ZS ng(S s){R*--s='-',s;}ZS pu(S s,J i){J j;do*--s='0'+i-10*(j=i/10);W(i=j);R s;}ZF x(I n){F e=1;N(n,e*=10)R e;}S pi(J i){R 0>i?ng(pi(-i)):pu(b+23,i);} //P(NI==f||0>(j|k),nf)
S pf(F f){P(0>f,ng(pf(-f)))P(!f,(S)"0.0")I n=6;W(f<1e6)--n,f*=10;W(f>=1e7)++n,f/=10;S p=n?p=pi(n),*--p='e',p:b+23;n=f+.5;W(99<n&&!(n%10))n/=10;R p=pu(p,n),p[-1]=*p,*p--='.',p;}
J ip(S p,I n){P('-'==*p,-ip(p+1,n-1))J j=0;N(n,j=10*j+p[i]-'0')R j;}ZS hh(S s,C c){N(2,C a=i?c&15:c>>4;s[i]="0W"[9<a]+a)R s;}S px(J j){S s=b+23;unsigned long k=j;do hh(s-=2,k);W(k>>=8);R s;}
F fp(S p,I n){P('-'==*p,-fp(p+1,n-1))I l=scn(p,'e',n),m=scn(p,'.',l),f=l<n?ip(p+l+1,n-l-1):0,j=ip(p,m),k;m+=m<l,k=ip(p+m,MN(9,l-=m));k+=j*x(l),f-=l;R 0>f?k/x(-f):k*x(f);} 

// REPL \ltwvf DAZ FTZ
K G[26],ps(S s);K1(ev);ZK es();ZK K0;K k0(){R r1(K0);}ZK vf(I f){K r=kS(0);N(26,K x=G[i];if(NL-x)if(f^(Ax||xt))r=j2(r,ks(i)))R r;}
ZK Li(K x,I i){R!xt||KS<xt?Xx:KC==xt?kc(Xc):KI==xt?ki(Xi):ks(Xi);}ZK e1(K(*f)(),K x,I d){K r=kK(xn);N1(rn,Rx=f?f(Li(x,i),d):Li(x,i))R r;}
K sS(I c,K x){I n=c?xn:0;N(xn,K y=Xx;n+=yn)K r=kC(n);if(c)--rn;S s=rC;N(xn,K y=Xx;s=((S)memcpy(s,(V*)y,yn))+yn;if(c)*s++=c)R X0(r);}
ZK1(cc){N(xn,if(94u<Xc-32){K r=kC(2*xn);N(xn,hh(rC+2*i,Xc))R j2(c2('0'+xu,'x'),r);})
//R cj('"',jc(r1(x),'"'));}
R r1(x);}

#define PRT 1     // print parse tree
#define TAB 1     // indent parse tree
#define TYP 0     // trace return types
#if PRT
I tb(I n){P(!TAB,n)O("\n");N(n,O(" "))R n;}ZC ty(K x){R KS==Ax?'s':KC==Ax?'c':KI==Ax?'i':KF==Ax?'f':'+'+!xi;}
ZI typ(K x){R KS==Ax?O("`%c",'a'+xi):KC==Ax?((94u<xi-32)?O("0x%x",xi):O("%c",xi)):KI==Ax?O("%d",xi):KF==Ax?O("%f",xf):O("%c",'+'+!xi);}
ZI len[16],max[16]; //!< FIXME recursion
#endif

ZK se(K x,I d){
 #if PRT
 $(Ax,$(len[d],typ(x))O(GRN),typ(x),O(OFF);
  $(!len[d]||len[d]<max[d],O(";"));len[d]++){$(len[d]&&len[d]<=max[d],tb(d));len[d]++;len[++d]=0,max[d]=xn-1;$(TYP,O("%c ("," chijefs CHIJEFS"[xu]))O("(");}
 #endif
 P(Ax,KS==Ax?c2('`','a'+xi):KC==Ax?X0(cc(x=c1(xi))):kp(KI==Ax?pi(xi):KF==Ax?pf(xf):(S)"+"+!xi))//!< atom
 P(8==xt,l2(x))
 P(1==xn,cj(',',se(Li(x,0),d)))
 I t=KS<xt?0:xt;
 P(KC==t,cc(x))
 P(!xn,c2("!("[!t],")  0   `"[t]))
 x=sS(";      "[t],e1(se,x,d));
 #if PRT
 O(")");--d;$(len[d]<=max[d],O(";"));
 #endif
 R!t?(cj('(',jc(x,')'))):x;}

K1(o){K y=QQ-Ax?se(x,0):j2(kp((S)"ERR: "),kp((S)(-1UL>>16&(J)x)));$(PRT,O("\n\n");R x;);R Y0(write(2,yC,yn)),nl(),x;}ZK1(pr){O(GRN);if(NL-x)r0(o(x));O(OFF);R x;}
ZS1(ld){J n;s=(S)mf(s,&n);Q((K)s)S t=s,u;I a,d=0;W(t<s+n&&d>=0){u=sc(t,10),*u++=0,a=t[1]?0:(*t=='/')-(*t=='\\');if(!d&&!a&&'/'-*t)Q(pr(es(t)))d+=a,t=u;}if(n)munmap(s,n);R NL;}
ZS1(tm){S t=sc(s,' ');Qs(!t,s)*t=0;I n=':'-*s++?1:10u>*s-'0'?ip(s,t-s):(J)es(s);K x='\\'-*++t?ps(t):0,r;F a=ms();N(n,Q(r=x?ev(x):ld(t+3))r0(r))if(x)r0(x);R ki(ms()-a);}
ZS1(es){K x;P('\\'-*s,!*s?NL:(x=ps(s))&&NL-x?X0(ev(x)):x)if(!*++s||'\\'==*s)exit(0);R!s[1]?'w'==*s?ki(AWS):sc((S)"vf",*s)?vf('f'==*s):qs(s):'t'==*s?tm(s+1):'l'==*s?ld(s+2):qs(s);}
V km(S*a){csr();O("bcc-ng 2024 (c) atw/kpc\n");N(26,G[i]=NL)*(K*)(K0=kK(0))=c0();if(*++a)pr(ld(*a));W(1)pr(es(r2((S)" ")));}I main(I c,char**a){R km((S*)a),0;}

//V _start(){asm("movl $0x9fc0,-4(%rsp);ldmxcsr -4(%rsp);lea 8(%rsp),%rdi;jmp km");}
//K qi(I i){R qs((S[]){"nyi","rank","length","type","domain","value"}[i]);}
//ZK1(rd1){QC(x)x=jc(x,0);I d=open(x,0);Qs(0>d,x)J b[16];fstat(d,b);R x=X0(511+ma(0,0,0,b[6]+4096)),xm=-1,xt=KC,ma(0,d,x,xn=b[6]),W+=xn,x;}(W-=xn,mu(x-511,xn+4096))
//ZK2(wr1){QC(x)x=jc(x,0);QC(y)unlink(x);I d=open(x,0102,0666);Qs(0>d,x)ftruncate(d,yn);R x=X0(ma(1,d,0,yn)),dsn(x,y,yn),mu(x,yn),Y0(NL);}
//K1(rd0){R Ss(0,rd1(x));} //{-1_'(0,1+&x=y)_y} K2(wr0){R wr1(x,sS(0,y));} //{,/x,'y}          

//:~
