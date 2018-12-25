#include "rvalgorithm/find.h"
#include "rvalgorithm/end.h"

const void*
rv_find_if_n(const void *collection, size_t size, size_t n, predicate_t pred)
{
	const char *begin = (const char *) collection;
	for(const void *end = rv_end(collection, size, n); begin != end && !pred(begin); begin += size) {}
	return begin;
}