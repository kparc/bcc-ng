//! nolibc
#pragma once
#include"_.h"

//I txN(G c,I n),I txN(G c,I n);
I tx(I c),sln(S s),txn(S x,I n),txN(I c,I n);

//#if NOLIBC
#if 1
//#include <unistd.h> //!< write|read|size_t

extern  void*  malloc(size_t);
extern  void*  realloc(void *, size_t);
extern  void   free(void *);

#ifdef XOUS
extern  int    libc_putchar(I c);
extern  int    libc_getchar();
extern  int    libc_write(I fd,_*ptr,I nbyte);

#define main init
#endif

#define BASE              0x70000000L     //!< sbrk(2)

//K dmp(S s,S x,J n){I d=open((V*)s,O_RDWR|O_CREAT|O_TRUNC,S_IRWXU);Qs(0>d,(S)s)write(d,x,n);R close(d),0;}

//I RX();S sch(S s,I c),mcp(S d,S s,I n),memmove(S d,S s,I n),memset(S x,I c,I n);I rand(),mcmp(S x,S y,I n);
I RX();S sch(S s,I c),mcp(S d,S s,I n);

//void* memmove(void *, const void *, size_t);
//void* memset(void *, int,  size_t);

//S memmove(S d,S s,I n);
//S memset(S x,I c,I n);
S mmv(S d,S s,I n);
I rand(),mcmp(S x,S y,I n);I wri(S s);

_ exit(I);K mft(S s,J*n,J l);S ma(I d,szt n);

//#define mmv memmove
//#define mset memset
#define strerror(e)       pf("errno: %d\n",e)
#define ABS(e)            ((0>(e))?(-(e)):(e))
#define pfl()             (0)

#else                     //!< use local stdlib

#include<stdio.h>
#include<string.h>
#include<stdlib.h>        //! abs()
#define sln(s)            ((UI)strlen((char*)s))
#define sch(s,c)          ((S)strchr((char*)s,c))
#define mcp(d,s,n)        ((S)memcpy((char*)d,(char*)s,n))
#define mmv(d,s,n)        ((S)memmove((char*)d,(char*)s,n))
#define ABS(e)            abs(e)
#define pfl()             fflush(0)


extern  int    libc_putchar(int c);
extern  int    libc_getchar();

#define BASE              0L

#endif//NOLIBC

//! math
#if (__x86_64__||i386)&&(!__TINYC__)
#define clz(n)            (__builtin_clz((UI)n))    //!< count leading zeros
#define clzl(n)           (__builtin_clzl((UJ)n))
#else
#define __(n)             i|=i>>n;
ZI dbj[32] =              {0,9,1,10,13,21,2,29,11,14,16,18,22,25,3,30,8,12,20,28,15,17,24,7,19,27,23,6,26,5,4,31};
#define clz(i)            (31-__lg2((UI)i))
#define clzl(i)           (63-__lg2((UI)i))         //!< shim
#define npw2(n)         __(1)__(2)__(4)__(8)__(16)  //!< round uint up to the next power of 2
static inline             I __lg2(UI i){npw2(i);R dbj[i*0x07C4ACDDU>>27];}
#endif
static UI p10[] =         {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
static inline             I lg10(UI i){I t=(32-clz(i)+1)*1233>>12;R t-(i<p10[t]);}


//:~
