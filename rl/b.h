//! simple line buffer

#include"_.h" //!< core
#include"c.h" //!< nolibc

#define PFNOIMPL
#include"pf.h" //!< printf(3)

typedef struct gb{S s;I t;I f;I g;}gb;typedef gb*L;

I txn(S x,I n);

#define WS               ws
#define R0               R(K)0;

//! line buffer accessors via r
#define lin(c)          gb_inC(r,c)              //!< insert byte at b[i]
#define lct(n)          ({N(n,gb_del(r));})      //!< (c)utout b[i..i+n]
#define ljp(i)          ({gb_mov(r,i-r->f);})    //!< (j)ump caret to i
#define ldp()           ({W(r->f)gb_bsp(r);})    //!< (d)rop before caret
#define ltk()           ({W(gb_del(r)){};})      //!< (t)ake up to caret
#define lbk()           gb_bak(r)                //!< caret back
#define lfw()           gb_fwd(r)                //!< caret forward
#define ldl()           gb_del(r)                //!< delete char
#define lbs()           gb_bsp(r)                //!< backspace
#define lsw(i,j)        (0)                      //!< swap r[i] and r[j]

L L0(),LN(S s,UI n);                             //!< blank line, line from string
I li(L b,UI i),                                  //!< character at i
  ln(L b),                                       //!< line length
  lff(L b,UI i,UI n),                            //!< flush line fragment
  lfl(L b);                                      //!< flush line

//! line buffer implementation
L gb_new(I n);
_ gb_inC(L b,I c);
_ gb_inS(L b,S s,I n);
_ gb_mov(L b,I a);
_ gb_bak(L b);
_ gb_fwd(L b);
I gb_del(L b);
_ gb_bsp(L b);
S gb_get(L b);
_ gb_test();


//:~
