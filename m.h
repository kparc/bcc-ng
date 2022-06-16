#pragma once

//! posix wrappers
#ifdef USE_AW_MALLOC
void*aw_malloc(size_t n);
void*aw_realloc(void*p,size_t n);
void*aw_calloc(size_t n,size_t sz);
void aw_free(void*p);
#endif

//:~
