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
* @brief find and return the first element from collection which satisfies pred.
*/
const void*
rv_find(const void *collection, size_t size, size_t nelems, predicate_t pred);

/*
 * @brief returns a pointer n positions after base, whose elements occupy size bytes.
 */
const void*
rv_end(const void *begin, size_t size, size_t n);

#endif
