#include "rvalgorithm/end.h"

const void*
rv_end(const void *begin, size_t size, size_t n) {
	const char *begin_as_char_ptr = (const char *) begin;
	return begin_as_char_ptr + size * n;
}