#include"a.h"

#define TRI_RANGE 75          //!< 26 lower/upper, 75 alnum
#define TRI_RANGE_OFFSET 48   //!< 97 ascii lowercase, 65 ascii uppercase, 48 alnum

static const char
 *LP[]={"N","W"},
 *V0[]={"exit","write","read"},
 *V1[]={"printf","mallloc","calloc","free","system"},
 *V2[]={"in","within","like","bin","ss","insert","wsum","wavg","div","xexp","setenv"},
 *V3[]={"mmu"};

V kw_lut_init();K kw_lookup(S x); //!< TODO kw_lut_destroy()

//:~
