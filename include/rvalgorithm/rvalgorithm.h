#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdlib.h>

typedef void( *processor_t )( const void *element );

typedef int( *predicate_t )( const void *element );

/*
* @brief apply processor to each element of collection.
*/
void
foreach( const void *collection, size_t size, size_t nelems, processor_t processor );

/*
* @brief find and return the first element from collection which satisfies pred.
*/
const void*
find( const void *collection, size_t size, size_t nelems, predicate_t pred );

#endif
