//! nolibc
#include"c.h"

//#if NOLIBC
#if 1

//! core comms (tx)byte (txn)bytes (txN)times
#ifdef XOUS
I tx(I c){R libc_putchar(c),1;}I RX(){R libc_getchar();}
I txn(S x,I n){P(!x,0)P(!n,n)R libc_write(0,x,n);}

#else
I tx(I c){R write(1,&c,1);}I RX(){I c;R read(0,&c,1),c;}
I txn(S x,I n){P(!n,n)write(0,x,n);R n;}

S sch(S s,I c)           {W(*s-c)P(!*s++,(S)0)R s;}
S mmv(S d,S s,I n)       {P(s<d&&d<s+n,d+=n,s+=n;W(n--)*--d=*--s;d)R mcp(d,s,n);}
_*memcpy(_*d, const _*s, size_t n)  {S x=(S)d,y=(S)s;W(n--)*x++=*y++;R d;}

#endif

I sln(S s)               {I r=0;W(*s++)r++;R r;}
S mcp(S d,S s,I n)       {W(n--)*d++=*s++;R d;}//S mcp(S d,S s,I n){S x=(S)d,y=(S)s;W(n--)*x++=*y++;R d;}
S memset(S x,I c,I n)    {N(n,x[i]=c);R x;}//{S s=(S)d;W(n--)*s++=c;R d;}
I mcmp(S x,S y,I n){S p=x,q=y;I r=0;P(x==y,r)W(n>0){Z(*p!=*q,r=(*p>*q)?1:-1;break;);n--,p++,q++;}R r;}
I txN(I c,I n){N(n,tx(c))R n;}

#else

#include<stdarg.h>
I tx(I c){R write(1,&c,1);}I txn(S x,I n){P(!n,n)N(n,tx(x[i]));R n;}I txN(I c,I n){N(n,tx(c))R n;}
I pf(S f,...) {I r;va_list p;va_start(p,f);r=printf(f,&p);fflush(0);va_end(p);R r;}

#endif

/*

//! mmap|munmap
extern I txfatal(S s);
#include<sys/mman.h>     //!< mmap|unmap
#include<sys/stat.h>     //!< stat|fstat
#include<fcntl.h>        //!< open|close

//! mmap(w/o)ffset (m)ap(f)ile(t)ail (m)m(a)p (m)ap(f)ile
ZS mao(I d,szt n,szt o){ZJ p=BASE;p+=d?0:n;_*r=mmap((_*)(d?0:p-n),n,PROT_READ|PROT_WRITE|PROT_EXEC,d?MAP_PRIVATE:(MAP_ANON|MAP_PRIVATE|MAP_FIXED),d-!d,0);P(r==MAP_FAILED,txfatal((S)"mmap"),(S)0)R r;}
K mft(S s,J*n,J l){struct stat b;I d=open((_*)s,0);P(0>d,txfatal(s))R(K)(fstat(d,&b),s=(*n=l?MN(l,b.st_size):b.st_size)?mao(d,*n,b.st_size-*n):s,close(d),s);} //!< mmap l trailing bytes or entire file
S ma(I d,szt n){R mao(d,n,0);}ZK mf(S s,J*n){R mft(s,n,0);}

*/

/*

//#include <time.h>

//! start timer
ext clock_t clk_start();

//! milliseconds lapsed since last clk_start()
ext UJ clk_stop();

//! calculate ms difference between start and end
ext UJ clk_diff(clock_t s, clock_t e);
*/

/*
clock_t start,end;

clock_t clk_start() {
	R start = clock();
}

UJ clk_diff(clock_t s, clock_t e) {
	R(e - s) * 1E3 / CLOCKS_PER_SEC;
}

UJ clk_stop() {
	end = clock();
	UJ r = clk_diff(start,end);
	start = end; //< allow chained clk_stop()
	R r;
}

*/

//:~
