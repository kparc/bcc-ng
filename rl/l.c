//! femtoline copyright (c) 2020 regents of kparc, bsd-2-clause
#include"l.h"

Z_ rlf();
ZI rlp();
ZI rlb(UI n);
#define R0 R(K)0;

_ rl1(char*p){Tc(),x=rlr(),PT=p,_rl(0);}I rl0(){pf("sigint ***\n",);R 0;} //!< init free

I _rl(char*p){Z(p,PT=p);
  S seed=(S)"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
  //S seed=(S)"asof:{f:!$[99=@y;y;+y];(f_x)(f#x)bin y}";
  R v=LE=HL=ST=0,r=LN(seed,sln(seed)),ljp(0),v=0,rlf(),1;}        //!< next line

//ZG rlq(){K y=H(xn-2);P(!y,0)R cmp(r,y);}                               //!< same as previous?
//ZK rlc(){P(!rn||rlq(),--xn,r)R rla(H_=r);}                             //!< commit to history   //drp(1==xn-HMX,x)
//ZG rlq(){K y;P(!(y=H(xn-2)),0)R cmp(r,y);}                             //!< same as previous?
//ZK rlc(){P(!rn||rlq(),--xn,r)R drp(1==xn-HMX,x),rla(H_=r);}            //!< commit to history
//ZK rlc(){P(!rn||rlq(),--xn,r0(r))R drp(1==xn-HMX,x),rla(H_=r);}        //!< commit to history

//ZI rlp(){pf("history\r\n");R0;P(!x,x)N(xn-!DBG,txhl(Xk,i))R0;}         //!< history (p)rinter
//ZI rlh(I d){P(2>xn,0)P(rll(d),bk=v,ff=rn;rfc=1)R 0;}                   //!< (h)istory browser
//ZI rlj(I m){P(!rn,0)R bk=v,ff=m?vmv(r,v,m):bb(r,v);}                   //!< (j)ump or balance

ZI rlb(UI n){R(!n||LMX<n)?n:5>n?txn((S)"\b\b\b\b",n):txe(n,'D');}        //!< move caret (b)ack
Z_ rlf(){nl(),txpt(),lfl(r),rlb(rn-v);}                                  //!< (f)ull line reset
Z_ rlt(){
    txn(EL,4),
    //txC(Red,lff(r,v,rn-v)),
    lff(r,v,rn-v),
    v+=ff,rlb(rn-v);}                  //!< redraw the (t)ail

ZI wps(I d){I t=0,x=0,s=d?1:-1;N(d?rn-v:v,Z(' '==li(r,v+i*s+d-1),Z(!t,++x)break)++t,++x);R x*s;}//!< word offset back/fw

Z_ rld(){
    rlb(bk),v-=bk;
    if(rfc) {
        rlt();
    }
    else {
        //txC(Cya,lff(r,v,ff)),
        lff(r,v,ff),
        v+=ff;
    }
}                               //!< re(d)raw and move

I malloc_test();

//_ gb_dbg(L b);

ZI debg(){
    //gb_test();
    //gb_dbg(r);
    //malloc_test();
    R 0;
}

#define U(c,e...) Z(c,e,rlf();next)
#define WRD(d) {I j=wps(d);v+=j;ljp(v);Z(j,txe(j,"DC"[d]));M(noesc)}  //!< word back/fwd
K rl(){G c;NX:c=RX();
  bk=ff=0,rfc=1;                                                   //!< redraw from cursor
  SW(ST,                                                           //!< parse a byte
  C(noesc,                                                         //!< normal stdin
   Z(in(" ~"),lin(c),ff=v<rn;xesc)                                 //!< insert ascii
   //P(cNL,nl(),rlc())                                             //!< commit eol ⏎
   U(cNL,rlf())                                                    //!< commit eol ⏎
   //U(cTAB&&1<rn,rlp())                                           //!< show history
   U(cTAB,debg())                                                  //!< dump debug
   U(cR,pf(hlp))                                                   //!< display help  ^R
   P(cC,EOT)P(!rn&&In(1,5),NOP)                                    //!< sigint | nop  ^C
   SW(c,                                                           //!< ^* sequences
    cL(pf(ED),rlf())                                               //!< clear screen  ^L
    cW(I j=wps(0);bk-=j;N(-j,lbs()))                                //!< erase a word  ^W
    cU(ldp(),bk=v)cK(ltk())                                        //!< kill to home  ^U ^K
    cA(hme)cE(end)cD(del)                                          //!< home end del  ^A ^E ^D
    cZ(WRD(0))cX(WRD(1))                                           //!< word back/fwd

//    cT(Z(1<rn,swp(),ff=2,bk=eol?2:!!v,rfc0))                       //!< swap 2 chars  ^T
//    cB(rlj(0))cN(rlj(-1))cP(rlj(1))                                //!< mis(b)alance  ^B ^N ^P

    cBSP(Z(v,bk=1,lbs()))                                          //!< backspace ⌫
    cESC(M(esc)),rlu(c)))                                          //!< escape / utf
  C(esc,M(cBKT?ebkt:cEO?esco:noesc))                               //!< nxt substate
  C(ebkt,rfc=0;                                                    //!< eseq E [ ...
   Z(in("09"),LE=c,M(ebkt0))                                       //!< nxt substate
   //Z(in("AB"),rlh(c+c-0x83))                                     //!< hist up down  ↑  ↓
   SW(c,rfc=0;
    eC(lfw(),ff=v<rn)                                              //!< left   ←
    eD(lbk(),bk=!!v)                                               //!< right  →
    eH(HME:ljp(0);         Z(v, txe(v, 'D'));v-=v ;M(noesc))       //!< home   ⇱
    eF(END:ljp(rn);ff=rn-v;Z(ff,txe(ff,'C'));v+=ff;M(noesc))       //!< end    ⇲
   )
   xesc)

  C(ebkt0,rfc=0;Z('~'==c,                                          //!< eseq E [ 0-9
   Z(LE=='3',DEL:ldl(),rfc=rn>=v));xesc)                           //!< delete key ⌦
  //Z(es2("17"),hme)Z(es2("48"),end)                               //!< alt home|end  ^H ^F
  C(esco,                                                          //!< eseq E [ O ..
   SW(c,eH(hme)eF(end),xesc)),                                     //!< alt home|end
  XESC:ST=noesc)                                                   //!< default case
 rld();next}                                                       //!< partial draw

//:~
