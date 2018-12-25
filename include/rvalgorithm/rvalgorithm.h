#ifndef RVALGORITHM_H
#define RVALGORITHM_H

#include <stdlib.h>

typedef void(*processor_t)(const void *element);

typedef int(*predicate_t)(const void *element);

/*
* @brief apply processor to each element of collection.
*/
void
rv_foreach(const void *collection, size_t size, size_t nelems, processor_t processor);

/*
* @brief find and return the first element from collection which satisfies pred. Otherwise, returns rv_end(collection, size, n)
*/
const void*
rv_find_n(const void *collection, size_t size, size_t n, predicate_t pred);

/*
 * @brief returns a pointer n positions after base, whose elements occupy size bytes.
 */
const void*
rv_end(const void *begin, size_t size, size_t n);

#endif
