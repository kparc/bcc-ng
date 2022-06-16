#include<string.h>//memset
#include"stdio.h"//dprintf

#include"_.h"
#include"c.h"

#define PFNOIMPL
#include"pf.h"

//! write

#ifdef TRC

#include<fcntl.h>//open
#include<unistd.h>//write/close


#include "trc.h"
#define DBGFILE "trace.log"

I trcfd;
_ trc1(){
	if(trcfd)return;
	trcfd=open((_*)DBGFILE,O_RDWR|O_CREAT|O_TRUNC,S_IRWXU);
	trcrst();
	trc("====================================\n");
}
_ trc0(){
	Z(!trcfd)return;
	close(trcfd);}

#else
I trcfd;
_ trc1(){}
_ trc0(){}

#endif

int rnd(void);

int add_one(int a) {
    pf("ffi adding one to %d\n\r", a);
    return a + 1;
}

int malloc_test() {
    int i;

    int randomnumber;
    int size = 32;
    void *p[size];
    for (i = 0; i < size; i++) {
        randomnumber = rnd() % 10;
        p[i] = malloc(32 * 32 * randomnumber);
    }

    for (i = size-1; i >= 0; i--) {
        free(p[i]);
    }

    S foo = malloc(200);
    for (i = 0; i < 200; i++) {
        foo[i] = (char)i;
    }
    S bar = malloc(200);
    mcp(bar, foo, 200);
    if (mcmp(foo, bar, 200) != 0) {
        pf("fail on alloc and copy\n");
    } else {
        pf("pass on alloc and copy\n");
    }
    char *baz = realloc(foo, 300);
    int mresult = mcmp(baz, bar, 200);
    if (mresult != 0) {
        pf("fail on realloc copy: %d\n", mresult);
        for (i = 0; i < 200; i++) {
            if (bar[i] != baz[i]) {
                pf("   fail bar[%d](%d) != baz[%d](%d)\n", i, bar[i], i, baz[i]);
            }
        }
    } else {
        pf("pass on realloc copy \n");
    }
    mset(baz, 42, 300);
    int pass = 1;
    for (i = 0; i < 300; i++) {
        if (baz[i] != 42) {
            pf("fail on memset\n");
            pass = 0;
        }
    }
    if (pass == 1) {
        pf("memset passed\n");
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// rand

#define	RAND48_SEED_0	(0x330e)
#define	RAND48_SEED_1	(0xabcd)
#define	RAND48_SEED_2	(0x1234)
#define	RAND48_MULT_0	(0xe66d)
#define	RAND48_MULT_1	(0xdeec)
#define	RAND48_MULT_2	(0x0005)
#define	RAND48_ADD	(0x000b)
unsigned short __rand48_seed[3] = {
	RAND48_SEED_0,
	RAND48_SEED_1,
	RAND48_SEED_2
};
unsigned short __rand48_mult[3] = {
	RAND48_MULT_0,
	RAND48_MULT_1,
	RAND48_MULT_2
};
unsigned short __rand48_add = RAND48_ADD;
void
__dorand48(unsigned short xseed[3])
{
	unsigned long accu;
	unsigned short temp[2];
	accu = (unsigned long) __rand48_mult[0] * (unsigned long) xseed[0] +
	 (unsigned long) __rand48_add;
	temp[0] = (unsigned short) accu;	/* lower 16 bits */
	accu >>= sizeof(unsigned short) * 8;
	accu += (unsigned long) __rand48_mult[0] * (unsigned long) xseed[1] +
	 (unsigned long) __rand48_mult[1] * (unsigned long) xseed[0];
	temp[1] = (unsigned short) accu;	/* middle 16 bits */
	accu >>= sizeof(unsigned short) * 8;
	accu += __rand48_mult[0] * xseed[2] + __rand48_mult[1] * xseed[1] + __rand48_mult[2] * xseed[0];
	xseed[0] = temp[0];
	xseed[1] = temp[1];
	xseed[2] = (unsigned short) accu;
}
int
rnd(void)
{
	__dorand48(__rand48_seed);
	return ((int) __rand48_seed[2] << 15) + ((int) __rand48_seed[1] >> 1);
}
