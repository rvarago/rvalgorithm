#include "rvalgorithm/end.h"

const void*
rv_end(const void *begin, size_t size, size_t n) {
	return ((const char *) begin) + size * n;
}