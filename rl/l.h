//! femtoline copyright (c) 2020 regents of kparc, bsd-2-clause

//! config
#include"fl.h"

enum{noesc,esc,ebkt,ebkt0,esco};        //!< line states
typedef struct rls{G st;I hl;I ct;char*pt;G le;G un;G ub[5];}rls; //! curr state
static rls RL;ZL r;ZK x;ZI bk,ff,rfc;      //!< (s)tate cur(r)line (x)istory (b)ack(ff)wd (r)edraw(f)rom(c)aret

//! state accessors
#define ST                RL.st         //!< current state
#define HL                RL.hl         //!< history line
#define v                 RL.ct         //!< caret pos
#define PT                RL.pt         //!< prompt
#define LE                RL.le         //!< last esc char
#define UN                RL.un         //!< utf counter
#define UB                RL.ub         //!< utf buffer
#define rn                ln(r)         //!< line length

//! state shortcuts
#define hme               goto HME
#define end               goto END
#define del               goto DEL
#define xesc              goto XESC     //!< leave escape mode
#define next              goto NX;      //!< read next byte
#define M(m)              ST=m;next;    //!< change state and read next

//! history
#define H(i)              (xn?IN(0,i,xn-1)?xK[i]:0:0) //!< get item
#define H_                xK[xn-1]        //!< last line in history
#define hp                xn-1-HL         //!< inverted history pos
#define QH(n)             IN(0,hp+n,xn-1)   //!< validate new index
#define rll(n)            QH(n)?(HL-=n,r=H(hp)):0     //<! selector

//! ctrl+keystroke
#define cA(a...)          C(1,  a)
#define cB(a...)          C(2,  a)
#define cD(a...)          C(4,  a)
#define cE(a...)          C(5,  a)
#define cK(a...)          C(11, a)
#define cL(a...)          C(12, a)
#define cN(a...)          C(14, a)
#define cP(a...)          C(16, a)
#define cT(a...)          C(20, a)
#define cU(a...)          C(21, a)
#define cW(a...)          C(23, a)
#define cX(a...)          C(24, a)
#define cZ(a...)          C(26, a)

//! keystroke
#define cESC(a...)        C( 27,a)
#define cBSP(a...)        C(127,a)
#define cC                 ( 3==c)
#define cF                 ( 6==c)         //!< nyi
#define cR                 (18==c)
#define cTAB               ( 9==c)
#define cEO                (79==c)
#define cBKT               (91==c)
#define cNL              ('\n'==c||'\r'==c)

//! esc [ c
#define eC(a...)          C('C',a)
#define eD(a...)          C('D',a)
#define eH(a...)          C('H',a)
#define eF(a...)          C('F',a)

//! viti100
#define EOL               "\r\n"
#define NOP               (L)0x00         //!< request next byte
#define EOT               (L)0x04         //!< (e)nd (o)f (t)ransmission
#define EBKT              "\x1b["         //!< dec vt100 escape sequence
#define EL                "\x1b[K"        //!< (e)rase (l)ine to the end
#define ED                "\x1b[H\x1b[2J" //!< (e)rase (d)isplay command

//! ansi color
enum {Amb=227,Red=196,Cya=207};
#define clr(c)            pf("\x1b[38;5;%dm",c) //<! color on
#define off()             pf("\x1b[0m")         //<! color off
#define txnC(c,s,n)       txC(c,txn(s,n))
#define red(s,n)          txnC(Red,s,n)
#define cya(s,n)          txnC(Cya,s,n)
#define amb(s,n)          txnC(Amb,s,n)
#define redQ(q,e...)      ((q)?txC(Red,(e)):(e))      //!< conditional

#if CLR
#define txC(c,e...)       (clr(c),e,off())
#else
#define txC(c,e...)       (e)
#endif

#define cRED(cond)        ((cond)?"\x1b[38;5;196m":"")
#define cOFF()            "\x1b[0m"

#define In(l,r)           IN(l,c,r)
#define in(r)             In(*r,r[1])

//! refcard ^r
static char*hlp="\n"
  "  erase a word    ^w\n"
  "  clear screen    ^l\n"
  "  fix a (t)ypo    ^t\n"
  "  catch sigint    ^c\n"
 #if FBB
  "  test balance    ^b\n"
  "  goto {[(;)]}    ^np\n"
 #endif
  "  alt home end    ^ae\n"
  "  kill<=>caret    ^udk\n"
  "  show history    tab\n\n";

//! extra comms
ZI txfatal(S s)            {R pf((S)"fatal: %s\n",s),exit(1),1;}
#define nl(x)             tx('\n')
#define txe(n,c)          (pf("%s%d%c",EBKT,ABS(n),c),pfl())       //!< E [ n CMD
#define txpt()            txn(PT,sln(PT))                     //!< prompt
ZI txhl(K y,UI i)         {R pf("%4d ",i)+lfl(y)+nl();}


//:~
