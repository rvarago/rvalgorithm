#ifndef RVALGORITHM_H
#define RVALGORITHM_H

#include <stdlib.h>

#include "rvalgorithm/find.h"
#include "rvalgorithm/end.h"

typedef void(*processor_t)(const void *element);

/*
* @brief apply processor to each element of collection.
*/
void
rv_foreach(const void *collection, size_t size, size_t nelems, processor_t processor);

#endif
