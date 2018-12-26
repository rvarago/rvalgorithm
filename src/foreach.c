#include "rvalgorithm/foreach.h"
#include "rvalgorithm/end.h"

void
rv_foreach_n(const void *collection, size_t size, size_t n, processor_t processor)
{
	const void * const end = rv_end(collection, size, n);
	for(const char *begin = (const char *) collection; begin != end; begin += size) {
		processor(begin);
	}
}