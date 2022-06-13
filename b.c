#include"a.h" //asm("push %rbp;push %rbx");asm("pop %rbx;pop %rbp");MIN(y^(x^y)&x-y>>63)I low()__builtin_ctz(~i&-2);}V qq(I o,I r,I x,I y){oc(":+-*%?  c"[o]),oc('0'+r),oc('0'+x),oi(y);}
K3(l1);ZK c5(I o,I n){R cj(o,pn((S)&n,4));}
// :+-*% ^&|<=>  x64 JJ Jj o2 cc tst RET cll psh pop acdbsbsd89..  o[m[s|d]] c3 eb+1 e8+4 e9+4 [f2/66/4*][0f] 5* 7*+1 b*+4 0f8*+4  03 23 2b 3b (6b 83) 89 8b ..
K1(ev){x=xy,x=KS<xu?((K(*)())x)():KF==xu?kf(((F(*)())x)()):ki(((J(*)())x)());R x;}

ZK z;ZI a=0,A[]={0,7,6,2,1,8,9,10,11,3,12,13,14,15,5,4},B=5,RET=0xc3,
 JJ[]={0xeb,0x72,0x74,0x77,0xe9,0x73,0x75,0x76, 0x0f83};

ZI m(I a,I b,I c){R 64*a+8*(7&b)+(7&c);}
ZK rex(I r,I x,I b,K y){R(r=7<A[r])+(x=7<A[x])+(b=7<A[b])?cj(0x40+4*r+2*x+b,y):y;}
ZK h(I o,I x,I y){R j2(256>o?c1(o):c2(o>>8,o),16>y?c1(m(3,x,y)):c5(m(0,x,5),y));}
ZK i(I o,I x,I y){R rex(16>x?x:0,0,16>y?y:0,h(o,16>x?A[x]:x-16,16>y?A[y]:y));}
ZK cll(I c){R c5(0xe8,c);}
ZK psh(I t,I x){R rex(0,0,x,c1(0x50+(7&A[x])));}
ZK pop(I t,I x){R rex(0,0,x,c1(0x58+(7&A[x])));}
ZK cc(I o,I x){R j2(i(0x0f20+JJ[o],16,x),i(0x0fb6,x,x));}
ZK tst(I t,I x){R KF==t?AB("tst"):i(0x85,x,x);}
ZK Jj(K x,I n){R cj(0x0f,c5(16+xC[xn],n-4));}
ZK o2f(I o,I x,I y){R 127>y?i((I[]){0x8b,0x03,0x2b,0x0faf,0,0x3b,0x23}[o],x,y):rex(0,0,x,o?c3(0x83,m(3," \0\5  \7\4\1"[o],A[x]),y-128):c5(0xb8+(7&A[x]),y-128));}
ZK o2(I t,I o,I r,I x,I y){K z;P(KF==t,8u>y-8?AB("vex"):j2(c2(0xc5,16*(8&~r)+8*(15&~x)+(5-o?3:1)),h((C[]){0x10,0x58,0x5c,0x59,0x5e,0x2e,0,0,0x2a}[o],r,y))) 
 I a=126<y,s;P(0<=o&&r==x&&(!a||3-o),4-o?o2f(o,r,y):129-y?AB("/"):i(0xd1,16+7,r))P(0<o&&r==y,z=o2f(o,r,x),2-o?z:j2(z,i(0xf7,16+3,r)))P((a?3:1)<o,j2(o2f(0,r,x),o2f(o,r,y)))
 R s=0<o?0:3+(o+1)/2,rex(r,a?0:y,x,c3(0>o?1&o?0x8b:0x89:3-o?0x8d:0x6b,m(3-o?a:3,A[r],a?A[x]:4),a?(2-o?y-128:128-y)<<s:m(s,A[y],A[x])));}
ZK cm(I t,I x,I y){R o2(t,5,x,x,y);}
ZK cv(I x,I y){R o2(KF,8,x,x,A[y]);}
ZK sh(I t,I r){R AB("sh");}
ZI ln(S s){I o=*s++,h=o/16,p=0xc5==o?2:0x0f==o;R 4==h?1+ln(s):RET==o||5==h?1:*JJ==o||7==h?2:0xe==h||0xb==h?5:p&&8==*s/16?6:p+(3==s[p]/64?2+(0x83==o||0x6b==o):5==(0xc7&s[p])?6:3);}

V1(lnk){S s=xC;W(s<xC+xn){
 I n=ln(s+=4==*s/16),p=0xc5==*s?2:0x0f==*s;S r=s+n-4;
 if(0xe8==*s||(p?8-s[1]/16:4>*s/16||8==*s/16)&&5==(0xc7&s[1+p]))
  *(I*)r=(0xe8==*s?a-'a'==*r?x:26==*r?(K)l1:((K*)G[*r])[1]:32>*r?(K)&zF[2+*r-16]:(K)(G+*r-'a'))-(K)r-4;
  //*(I*)r=(0xe8==*s?a-'a'==*r?x:26==*r?(S)l1:((K*)G[*r])[1]:32>*r?(S)&zF[2+*r-16]:(S)(G+*r-'a'))-r-4;
 s+=n;}}

V1(dis){w2(px(xu)),oc(':');S s=xC;W(s<xC+xn-2){N(ln(s),w2(px(*s++)))oc(' ');}N(2,w2(px(*s++)))nl();}
K u(I u,K x){R xu=u,x;}
K jmp(I n){R n<-128||n>127?c5(JJ[4],0>n?n-3:n):c2(*JJ,n);}

K O2(I t,I f,I r,K x,K y){I i=Ay?yi:yu;R u(r,j3(Ay?c0():y,x,10>f?o2(t,f,r,xu,i):j2(cm(t,xu,i),16>r?cc(f-9,r):c1(f-9))));}
K SH(I t,K y){R u(yu,j2(y,sh(t,yu)));}
K ZR(I t,C r){R u(r,o2(t,2,r,r,r));}
K MV(I t,I r,K y){R O2(t,0,r,u(r,c0()),y);}

ZC N=8,D[2]={1,1},L[26],T[26];ZI M=0;ZS tp;K d(I r,K x);

I1(hh){I t=T[xi-'a'];R 14==t?-2:13==t?-4:2*t-26;}
I1(t){I a=xi-'a';R!Ax?xu:126<xi?KI:26u>a&&T[a]?T[a]:A(x=26u>a?G[a]:zK[2+xi-16])?Ax:xt+8;}
I1(q){I i=xi-'a';R Ax?26u>i&&L[i]?L[i]:0:':'==*xC?I(xy):0;}
K e(I r,K x){K y=d(r,x);R Ay?128==yi||32>yi&&!zK[2+yi-16]?ZR(t(x),r):MV(t(x),r,y):y;}
K b(I f,K x){K y=d(16,x);R Ay?AB("b"):16==yu?yC[yn-1]=JJ[yC[yn-1]+f*4],y:j3(y,tst(t(x),yu),c1(JJ[f?2:6]));}
K f(I r,K x){K y=e(r,x);R r-yu?MV(t(x),r,y):y;}
K E(I r,K x){I i=xn-1;K z=e(r,Xx),y=kK(i--);r=zu,Yx=z;W(i--)Yx=e(0,xK[i+1]);R u(r,sS(0,y));}

ZK vh(K x,I r,I n){R++tp,1<n?e(0,x):f(r,x);}
K v(I r,K x,I n){K y=xz,z;I c=!n&&!Ay&&a==*yC,l=M;
 z=vh(xK[3],r,n),M=l,y=vh(y,r,n),x=b(1,xy);
 y=j2(y,n||c?yn-=c*B,jmp(1-n?n-xn-yn-3:zn):c1(RET));R j3(jc(x,yn),y,z);}

ZV mm(K x){I i;$(Ax,if(26u>xi-'a'&&L[i=xi-'a'])M|=1<<L[i])$(':'==*xC&&A(xy),i=I(xy)-'a',M&=~(1<<L[i]),mm(xz))N(xn,mm(sc("{WNC",*xC)?xK[xn-1-i]:Xx))}
K1(w){I i='N'==*xC?L[N++]:0,j=0;mm(x);K y=xy,z=xz;I jj;
 P(!i&&!Az&&'$'==*zC,x=b(1,y),z=v(0,z,-xn-1),jj=-xn-1-zn-2,j3(jc(x,zn+2),z,jmp(jj)))
 //P(!i&&!Az&&'$'==*zC,x=b(1,y),z=v(0,z,-xn-1),j3(jc(x,zn+2),z,jmp(-xn-1-zn-2)))
 x=i?M|=1<<i,jc(cm(0,i,j=(j=q(y))?j:*D),JJ[1]):b(0,y),z=i?j2(e(0,z),o2(0,1,i,i,129)):e(0,z);
 I n=-zn-xn-1;z=j3(jmp(zn),z,n<-128?--xn,j2(x,Jj(x,n)):jc(x,n));R i?--N,M&=~(1<<i),j3(f(j,y),ZR(0,i),z):z;}

K g(I c,K x){K y=c0(),z,r=c0();I i=0,l=a?M:0;W(++i<xn){z=Xx;I l=M&1<<i,b=Az||128>*zC&&':'-*zC||i-L[I(zy)-'a'],h=2-i||Az||26>c;z=f(i,z);if(!h)z=j3(psh(0,3),z,pop(0,3));
 if(l)z=j2(b?psh(0,i):z,b?z:psh(0,i)),r=j2(r,pop(0,i));y=j2(z,y);}  z=cll(c);W(i<16){if(l&1<<i)z=j3(psh(0,i),z,pop(0,i));++i;}R j3(y,z,r);}

                 //!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
I c(I c){R 128>c?"   +$++ ()++ + +0000000000+;+++  aaaaaaaaaaaaaNaaaaaaaaWaaa[+]  `aaaaaaaaaaaaaaaaaaaaaaaaaa{+} "[c-32]:0;}
I l(S s,I c){S t=sc(s,c);R t?t-s:0;}I U(I i){R l((S)" +-*% &|  <=>",i);}

K d(I r,K x){P(Ax,(r=q(x))?M|=1<<r,u(r,c0()):x)I s=15&r,a;K y,z;
 S((y=xy,c(a=*xC)),
 case'N':C('W',R w(x))C('$',R u(r,v(r,x,1)))C('{',R E(r,x))C('[',R g(26,x))C('a',R T[a-'a']?O2(0,1+hh(xx),s,d(0,xx),d(0,y)):g(a-'a',x))C(0,R y=d(0,y),O2(t(x),U(a-128),yu,y,d(s,xz))),
 if(':'==a){P(Ay,r=L[yi-'a'],M&=~(1<<r),f(r,xz))y=d(0,yy),z=e(s,xz),x=xy;R r=zu,u(r,j2(z,O2(0,hh(xx),r,d(0,xx),y)));} I m,b=t(y);
 P(3>xn,'&'==a?SH(b,e(0,y)):'%'==a?y=e(0,y),u(s,j2(y,cv(s,yu))):'\\'==a?y=e(s,y),O2(b,1,s,u(yu,c0()),y):O2(0,'#'==a?-3:'*'==a?1+hh(y):'/'==a?4:U(a),s,e(s,y),kc(128+('#'==a?-1:'*'!=a))))
 z=xz;a=U(a),r=9<a||16-r?r:0;P(!Ay&&!q(y)&&!Az&&!q(y),M|=1<<(m=D[KF==b]++),y=e(0,y),M&=~(1<<m),z=O2(b,a,r,y,f(m,z)),--D[KF==b],z)
 R Ay&&!q(y)&&2-a&&4-a?O2(b,9<a?11-a+11:a,r,e(s,z),y):O2(b,a,r,e(s,y),d(s,z)))}

ZK Na(){S r=tp;W(10u>*++tp-'0'||'.'==*tp){};I f=0;N(tp-r,f|='.'==r[i])R f?kf(fp(r,tp-r)):ki(ip(r,tp-r));}
ZS pq(){R sc((S)";})]",*tp);}K1(n){R kc(KI==Ax&&129u>1+xi?128+xi:(z=jk(z,x),16+zn-3));}ZK p();
ZK pE(I a,I c){K r=k1(kc(c)),x;do r=jk(r,x=pq()?n(ki(0)):p());W(';'==*tp++);R u(a?a:t(x),r);}

ZK p(){K x,y;I a,b;
 S('0'-c('-'==(a=*tp++)?tp['.'==*tp]:'.'==a?*tp:a)?c(a):'0',
  case'N':T[N++]=KI;
  C('W',R++tp,x=p(),++tp,x=k3(kc(a),x,p()),N-='N'==a,x)
  case'$':++tp;
  C('{',R pE(0,a))
  C('+',R x=p(),u('#'==a?KI:'%'==a?KF:t(x)-8*('*'==a),k2(kc(a),x)))
  C('[',R pE(12,a))
  C('(',x=p(),++tp)
  C('0',P('2'==a&&'*'==*tp,++tp,x=p(),u(t(x),k2(kc('\\'),x)))--tp;x=n(Na()))
  C('a',
   x='['==*tp?++tp,
   pE(T[b=a-'a']?T[b]-8:(x=G[b],x=xy,*D=MX(*D,xC[xn-2]),D[1]=MX(D[1],xC[xn-1]),xu),a):kc(a)),
  AB(tp-1))
 P(pq(),x)
 if('+'-c(a=*tp++))AB(tp-1);
 if(':'==*tp)++tp,a+=128;
 b=t(y=p());
 $(':'==a&&Ax,T[xi-'a']=b)b='%'-a?MX(b,t(x)):KF;
 #define ff(x) (KF-b||KF==t(x)?x:Ax&&126<xi?n(kf(xi-128)):u(KF,k2(kc('%'),x)))
 R u(9<U(a)?KI:b,k3(kc(a),ff(x),ff(y)));}

K ps(S s){a=0,N=8,*D=D[1]=1;N(26,L[i]=T[i]=0);M=0;tp=s; //!< reset
 S r='['==tp[1]&&(r=sc(tp,']'))&&*++r?r:0;K*k=r||':'==tp[1]?a=*tp,tp+=2,G+a-'a':0;
 P('!'==*tp,++tp,X(k,enm(ki(ip(tp,sl(tp))))))
 z=k2(kp(tp),NL);
 if(!tp[1]&&26u>*tp-'a')r1(G[*tp-'a']);
 if(r){X(k,k2(r1(zx),u(KI,c2(1,1))));N(r-tp-1,L[23+i]=D[0]++,T[23+i]=l((S)" chijefs CHIJEFS",tp[i]))tp=r;}
 K x=p(); //o(x);
 N(23,if(T[i])L[i]=D[KF==T[i]]++)
 {
  I a=t(x);
  zy=u(a,j2(X0(Ax||'$'-*xC?f(0,x):v(0,x,0)),c3(RET,*D,D[1])));
  //dis(zy); // disasm
  dmp((S)"t/lnk.bin",zy); //!< dump
  lnk(zy);
 }
 //dis(zy); // disasm
 //N(26,O("%c: %p\n",'a'+i,G[i]))
 R k?X(k,r?z:Z0(ev(z))):z;}

//:~
