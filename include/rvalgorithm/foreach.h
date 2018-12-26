#ifndef RVFOREACH_H
#define RVFOREACH_H

#include <stdlib.h>

typedef void(*processor_t)(const void *element);

/*
* @brief apply processor to each element of collection.
*/
void
rv_foreach_n(const void *collection, size_t size, size_t n, processor_t processor);

#endif
