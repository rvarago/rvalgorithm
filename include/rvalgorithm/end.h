#ifndef RVEND_H
#define RVEND_H

#include <stdlib.h>

/*
 * @brief returns a pointer n positions after base, whose elements occupy size bytes.
 */
const void*
rv_end(const void *begin, size_t size, size_t n);

#endif