//! femtoline copyright (c) 2020 regents of kparc, bsd-2-clause

#include"_.h"

extern _ trc1(),trc0(),trc(S s);

//!         init         readline  prompt    free
extern void rl1(char*);K rl();int _rl(char*),rl0();

//! config
#define LMX               64*3          //!< max line byte length (multiples of 64)
#define HMX               32            //!< max lines of history (>=0)
#define MLM               8*1024        //!< hard malloc limit (>=256 or zero)

#ifndef AW
#define AW                0             //!< use k9 backend
#endif

//! feature flags
#define FUN               0             //!< unicode support
#define FBB               0             //!< bracket balancer

#ifdef XOUS
#define FTY               0             //!< set tty raw mode
#else
#define FTY               1             //!< set tty raw mode
#endif

#define FIO               0             //!< persist sessions
#define DBG               0             //!< refcount debug
#define CLR               0             //!< partial redraw debug
#define FHF               ".k"          //!< history filename

//! nolibc
#include"c.h"

//! printf
#include"pf.h"

//! line buffer
#include"b.h"

//! features
#include"f.h"

//! tracefile
#include "trc.h"


//:~
