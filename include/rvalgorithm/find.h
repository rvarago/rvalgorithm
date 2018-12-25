#ifndef RVFIND_H
#define RVFIND_H

#include <stdlib.h>

typedef int(*predicate_t)(const void *element);

/*
* @brief find and return the first element from collection which satisfies pred. Otherwise, returns rv_end(collection, size, n)
*/
const void*
rv_find_if_n(const void *collection, size_t size, size_t n, predicate_t pred);

#endif
