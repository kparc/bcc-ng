//! femtoline copyright (c) 2020 regents of kparc, bsd-2-clause

#include<unistd.h> //<! size_t write(2)
#include"t.h"

#define ZL static L

//! string manip (^wt)
/*

#define swp()             c=Rvv,Rvv=_Rv,_Rv=c;       //!< swap curr<>prev
*/
#define Rvv               li(r,vv)                     //!< byte under caret
#define _Rv               li(r,vv-1)                   //!< previous byte
#define xnc(x,n,c)        W(x&&!(x-ln(r))&&(c))x+=n;      //!< move x while cond
#define rwd(c)            xnc(v,-1,c)                //!< rewind caret while cond
#define eol               (v==ln(r))
#define vv                (v?eol?v-1:v:1)
#define swp()             lsw(r,vv-1,vv)       //!< swap curr<>prev

#if FUN //!< utf8
#define uff               (0x3f&*s++)
#define U4(c)             0xf0==(0xf8&c)
#define U3(c)             0xe0==(0xf0&c)
#define U2(c)             0xc0==(0xe0&c)
#define ubc(c)            UB[UN++]=c,UB[UN]=0 //!< accumulator
static UI cpt(S s)       {R U4(*s)?(0x07&*s++)<<18|uff<<12|uff<<6|uff:U3(*s)?(0x0f&*s++)<<12|uff<<6|uff:U2(*s)?(0x1f&*s++)<<6|uff:0;}
static UI rlu(G c)       {UI u=0;ubc(c);P(2>UN,0)if(u=cpt(UB))txn(UB,UN);if(u||4==UN)UN=0;R u;} //!< attempt to parse utfbuf
#else
#define LC()
static UI rlu(G c){R 0;}
#endif//FUN


#if FTY                   //!< raw tty
#include<sys/ioctl.h>     //!< ioctl(2)
#include<termios.h>       //!< termios
//#include <locale.h>
//#define LC()            setlocale(LC_ALL,"C.UTF-8")
//#define tc1(t)          cfmakeraw(&t);//!

static struct termios tco,tcn; //!< old|new
//#define tcg(t)            ioctl(0,TCGETS,&t)
//#define tcs(t)            ioctl(0,TCSETS,&t)
#define tcg(t)            tcgetattr(0,&t)
#define tcs(t)            tcsetattr(0,TCSAFLUSH,&t)

//t.c_iflag&=~(BRKINT|ICRNL|INPCK|ISTRIP|IXON),t.c_cflag|=(CS8)
#define tc1(t)            t.c_lflag&=~(ICANON|ECHO|ISIG),t.c_cc[VMIN]=1,t.c_cc[VTIME]=0;tcs(t) //!< blocking read, no echo, pass escapes and signals
#define rltc()            tcg(tco),tcn=tco,tc1(tcn); //!< LC();todo !isatty(0)
Z_ Tc(){rltc();}
#else
Z_ Tc(){}
#endif//FTY


#if FBB                   //!< bracket balancer
#define Qb(c,a...)        P(c,tx('\7'),a) //!< send audio bell on bracket misbalance
#define Jp                (x-r)
//! class                   !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
ZG cl(G c){P(!c,0)R 128>c?"  q     ()                 ;                               ( )                             ( ) "[c-32]:0;}
//ZS bq(L x){W((x=sch(++x,'"'))&&!({I i=0;W('\\'==x[--i]){};1&i;})){};R x;} //!< ffwd quoted string w/escapes

ZS bq(L x){I j=0;W((x=sch(++x,'"'))&&!({I i=0;W('\\'==x[--i]){};1&i;})){};R x;} //!< ffwd quoted string w/escapes

ZI bb(L r,I c){G b[16];I p[16],a,n=0,t=-1;S s,x=r-1;I i=-1;
	W(a=li(r,++i))
   SW(cl(a),
		C('q',s=bq(x);Qb(!s,x,Jp)c=Jp==c?s-r:s-r==c?Jp:c,x=s)
 		C('(',Qb(16==++n,Jp)p[n]=Jp,b[n]=*x;Z(c==Jp,t=Jp))
 		C(')',Qb(!n,Jp)Qb(b[n]!=*x-1-*x/64,p[n])c=Jp==c?p[n]:p[n]==t?Jp:c,--n)
 	)
	Qb(n,p[n])R c;}

ZI vmv(K r,I c,I n){I i=c+n;xnc(i,n,!sch((S)"(;)",cl(at(r,i))))R MN(MX(0,i),ln(r));} //!< move caret to next|prev {[(;)]}
#else
ZI bb(K r,I c){R c;}ZI vmv(K r,I c,I n){R c;}
#endif//FBB

//! calculate hard alloc limit (nyi)
ZI MMX(){I lsz = MX(64,LMX) + 8,       //!< single line, minimum of 64 bytes + overhead
           hmx = MX( 0,HMX) + 1,       //!< line count + current line buffer
           mlh = lsz * hmx +           //!< total worst case line storage
                 hmx * sizeof(char*),  //!< history ring buffer
           mlm = MLM?MX(256,MLM):mlh;  //!< if MLM is defined, no less than 256 bytes
           R MN(mlm,mlh);}             //!< effective alloc limit, MLM takes precedence if set

#if FIO                    //!< session persistence
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdio.h>
#include<fcntl.h>

ZL rla(L r){I d=open(FHF,O_RDWR|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);P(0>d,r)write(d,r,MN(ln(r),LMX));write(d,"\n",1);R close(d),r;}  //!< append
ZK rlr(){J j,l,n=0;S s,y=s=(S)mft(FHF,&n,MMX());P(!y||!n,kK(0));I c;K r=kK(c=HMX);N(c,Rk=K0)         //!< restore HMX lines of history from file
//c=-c;j=-1; N(n+1,Z('\n'==Yg||n==i,l=i-j-1;Z(IN(1,l,LMX),rK[HMX+c++]=Sn(y+j+1,l);Z(!c,goto EX));j=i))EX:R rlm0(y,n),drp(c,r);}   //!< top down
  j= n;_N(n,l='\n'==y[i];Z(l||!i,l+=i;Z(IN(1,j-l,LMX),rK[--c]=sL(y+l,j-l);
  pf("%.*s\n",j-l,y+l);
  Z(!c,goto EX));j=i))                                   //!< bottom up
  EX:R munmap(y,n),drp(c,r),r;}
#else
ZK rlr(){R(K)0;}ZK rla(K r){R r;}

#endif//FIO


//:~
