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

const void*
rv_find_n(const void *collection, size_t size, size_t n, predicate_t pred)
{
	const char *begin = (const char *) collection;
	for(const void *end = rv_end(collection, size, n); begin != end && !pred(begin); begin += size) {}
	return begin;
}

const void*
rv_end(const void *begin, size_t size, size_t n) {
	const char *begin_as_char_ptr = (const char *) begin;
	return begin_as_char_ptr + size * n;
}
