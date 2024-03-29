#pragma once

#include<stdlib.h> //system()
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/syscall.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
typedef unsigned char C,*S;typedef int I;typedef int UI;typedef unsigned short UH;typedef long J;typedef double F;typedef void V;typedef unsigned long long K,UJ;

#define R return
#ifdef TEST
#define O(a...) (0)
#else
#define O printf
#endif
#define P(b,a...)   if(b)R({a;});                          //!< "bail early" predicate aka panic.
#define W(b...)     while((b))                             //!< while
#define N(n,a...)   {I i=0,_n=(n);W(i<_n){a;++i;}}         //!< no stinking loops.
#define _N(n,a...)  {I i=(n);W(i--){a;}}                   //!< walk something backwards.
#define $(b,a...)   if(b){a;}else                          //!< cond
#define S(i,c,a...) switch(i){c default:a;}                //!< switch
#define C(i,a...)   case i:{a;}break;                      //!< case+break

#define MN(a,b)    ({typeof(a)_a=(a);typeof(a)_b=(b);_a<_b?_a:_b;})
#define MX(a,b)    ({typeof(a)_a=(a);typeof(a)_b=(b);_a>_b?_a:_b;})
#define IN(l,x,r)  ((l)<=(x)&&(x)<=(r))
#define CNT(x)     (sizeof(x)/sizeof(x[0]))

#define ZI static I
#define ZC static C
#define ZS static S
#define ZJ static J
#define ZF static F
#define ZK static K
#define ZV static V

#define ptr(x) (*(S*)&x)
#define xC ptr(x)
#define yC ptr(y)
#define zC ptr(z)
#define fC ptr(f)
#define rC ptr(r)

#define _ static inline
#define AB(s)       (os((S)s),exit(1),(K)0L) //abort string

#define sl(s) strlen((char*)s)

//!ansi color
#define CYA "\x1b[38;5;105m"  //<! color on
#define GRN "\x1b[38;1;10m"   //<! color on
#define RED "\x1b[38;5;196m"  //<! color on
#define OFF "\x1b[0m"         //<! color off

//:~
