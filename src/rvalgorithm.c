#include "rvalgorithm/rvalgorithm.h"

void
rv_foreach(const void *collection, size_t size, size_t nelems, processor_t processor)
{
	const char *base = (const char *) collection;
	for(int i = 0; i < nelems; ++i) {
		processor(base);
		base += size;
	}
}