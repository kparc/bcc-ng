#define PFNOIMPL
#include"l.h"

#define Pt "> "
#define F(opt) ("-+"[!!opt])

ZI oe(L x){
    pf("COMMIT\r\n");
    P(EOT==x,0)P(NOP==x,1)R lfl(x),nl(),_rl(Pt);}

I main(){
 pf("precursor %clc %caw %ctty %cbb %cfio %cutf mmx=%d (^r help)\r\n",F(!NOLIBC),F(AW),F(FTY),F(FBB),F(FIO),F(FUN),MMX());
 //trc1();
 rl1(Pt);
 W(oe(rl()));
 //trc0();
 R rl0();}

//:~
